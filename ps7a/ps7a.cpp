// Copyright 2015 Michael Overy

#include <boost/regex.hpp>

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

using boost::regex;

using boost::gregorian::date;
using boost::gregorian::from_simple_string;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

// stoi function provided by Victor Grinberg
template <typename T>
int to_int(const T& sm) {
  return atoi(sm.str().c_str());
}

int main(int argc, char* argv[]) {
  // Check # of Command Line Args
  if (argc != 2) {
    cout << "Invalid # of command lind arguments" << endl;
    return 0;
  }

  // Open Device Log, end if it can't be opened.
  ifstream inputFile(argv[1], ifstream::in);
  if (!inputFile.is_open()) {
    cout << "Unable to open file \"" << argv[1] << "\"" << endl;
    return 0;
  }

  string outputFileName(string(argv[1]) + ".rpt");
  ofstream outputFile;
  outputFile.open(outputFileName.c_str());

  // Strings used to construct regex expressions
  string s_date("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
  string s_time("([0-9]{2}):([0-9]{2}):([0-9]{2})");
  string s_boot("(.*log.c.166.*)");
  string s_done("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

  // Regex Expressions
  regex r_boot(s_date + s_time + s_boot);
  regex r_done(s_date + s_time + s_done);

  // Variable to hold matches
  boost::smatch m;

  // Instantiate some variables for the loop
  string line;
  int line_number = 1;
  bool booting = false;
  ptime t1, t2;

  // Gather boot records until EOF
  while (getline(inputFile, line)) {
    if (regex_match(line, m, r_boot)) {
      if (booting)
        outputFile << "**** Incomplete boot **** \n" << endl;

      date d(from_simple_string(m[0]));
      ptime temp(d, time_duration(to_int(m[4]), to_int(m[5]), to_int(m[6])));
      t1 = temp;

      outputFile << "=== Device boot ===" << endl;
      outputFile << line_number << "(" << argv[1] << "): ";
      outputFile << m[1] << "-" << m[2] << "-" << m[3] << " ";
      outputFile << m[4] << ":" << m[5] << ":" << m[6] << " ";
      outputFile << "Boot Start" << endl;
      booting = true;

    } else if (regex_match(line, m, r_done)) {
      if (booting) {
        date d(from_simple_string(m[0]));
        ptime temp(d, time_duration(to_int(m[4]), to_int(m[5]), to_int(m[6])));
        t2 = temp;

        time_duration td = t2 - t1;

        outputFile << line_number << "(" << argv[1] << "): ";
        outputFile << m[1] << "-" << m[2] << "-" << m[3] << " ";
        outputFile << m[4] << ":" << m[5] << ":" << m[6] << " ";
        outputFile << "Boot Completed" << endl;

        outputFile << "\t" << "Boot Time: ";
        outputFile << td.total_milliseconds() << "ms \n" << endl;

        booting = false;
      } else {
        outputFile << "**** Unexpected boot ****\n" << endl;
      }
    }

    line_number++;
  }

  return 0;
}

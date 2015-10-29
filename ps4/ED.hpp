#ifndef ED_HPP
#define ED_HPP

#include <cstring>
#include <vector>

class ED {
private:
  // Input Variables
  std::string stringA;
  std::string stringB;

  // Constructed Variables
  std::vector< std::vector<int> > opt;
  int editDistance;
  std::string editString;

  // Private Functions
  int optDistance();
  std::string alignment() const;
  int penalty(char a, char b);
  int min(int a, int b, int c);
public:
  ED(std::string _stringA, std::string _stringB);
  //  int penalty(char a, char b);
  //  int min(int a, int b, int c);
  //  int optDistance();
  //  std::string alignment() const;
  void printOpt() const;
  int getEditDistance() const;
  std::string getEditString() const;
  
};

#endif

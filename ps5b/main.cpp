#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

using namespace std;

vector<int16_t> makeSamplesFromString(GuitarString gs) {
  vector<int16_t> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
  sf::Event event;
  double freq;
  string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

  vector<vector<int16_t> > samples(37);
  vector<sf::Sound> sounds(37);
  vector<sf::SoundBuffer> soundBuffers(37);

  for(int i = 0; i < 37; i++) {
    freq = 440 * pow(2, (i - 24) / 12.0);
    GuitarString gs(freq);
    samples[i] = makeSamplesFromString(gs);
    
    if (!soundBuffers[i].loadFromSamples(&samples[i][0], samples[i].size(), 2,
                                         SAMPLES_PER_SEC))
      throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    
    sounds[i].setBuffer(soundBuffers[i]);
  }

  /*  vector<int16_t> sample;

  double freq = CONCERT_A;
  GuitarString gs1 = GuitarString(freq);
  sf::Sound sound1;
  sf::SoundBuffer buf1;
  sample = makeSamplesFromString(gs1);
  if (!buf1.loadFromSamples(&sample[0], sample.size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    sound1.setBuffer(buf1); */
  
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::TextEntered:
        if (event.text.unicode < 128) {
          string temp;
          temp += static_cast<char>(event.text.unicode);
          cout << "Playing sound associated with " << temp << endl;
          int index = keyboard.find(temp);
          sounds[index].play();
        }
        break;
      default:
        break;
      }  
      
    
      window.clear();
      window.display();
    }
  }

  return 0;
}

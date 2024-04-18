// Description: Defines the Detector class for modeling the particle detector.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef DETECTOR_H
#define DETECTOR_H

#include "Lepton.h"
#include <string>

class Detector 
{
private:
  std::string detector_type; // "tracker", "calorimeter", or "muon chamber"
  bool status; // true for on, false for off

public:
  Detector(); // Default constructor
  Detector(const std::string& type); // Parameterized constructor
  ~Detector(); // Destructor

  // Setters and getters
  void set_detector_type(const std::string& type);
  void set_status(bool status);
  std::string get_detector_type() const;
  bool get_status() const;

  // Functionality
  void turn_on();
  void turn_off();
  int detect_particle(const Lepton& particle) const;

  // Utility
  void print_info() const;
};

#endif 



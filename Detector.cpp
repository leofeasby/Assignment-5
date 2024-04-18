// Description: Defines the Detector class for particle detection modeling
// Author: Leo Feasby
// Date: 18/04/2024

#include "Detector.h"
#include <iostream>

Detector::Detector() 
  : detector_type("tracker"), status(false) 
{}

Detector::Detector(const std::string& type) 
  : status(false) 
{
  // Validate detector type before setting
  if (type == "tracker" || type == "calorimeter" || type == "muon chamber") 
  {
    this->detector_type = type;
  } 
  else 
  {
    std::cerr << "Invalid detector type. Setting to default 'tracker'.\n";
    this->detector_type = "tracker"; // Default to tracker if invalid
  }
}

Detector::~Detector() {}

void Detector::set_detector_type(const std::string& type) 
{
  // Validate detector type as in constructor
  if (type == "tracker" || type == "calorimeter" || type == "muon chamber") 
  {
    this->detector_type = type;
  } 
  else 
  {
    std::cerr << "Invalid detector type. No change made.\n";
  }
}

void Detector::set_status(bool status) 
{
  this->status = status;
}

std::string Detector::get_detector_type() const 
{
  return this->detector_type;
}

bool Detector::get_status() const 
{
  return this->status;
}

void Detector::turn_on() 
{
  this->status = true;
}

void Detector::turn_off() 
{
  this->status = false;
}

int Detector::detect_particle(const Lepton& particle) const 
{
  if (!status) 
  {
    std::cout << "Detector is off.\n";
    return 0;
  }

  if ((detector_type == "tracker" && (particle.get_particle_type() == "electron" || particle.get_particle_type() == "muon")) ||
      (detector_type == "calorimeter" && particle.get_particle_type() == "electron") ||
      (detector_type == "muon chamber" && particle.get_particle_type() == "muon")) 
  {
    std::cout << particle.get_particle_type() << (particle.get_charge() == 1 ? " (antiparticle)" : "") << " was detected\n";
    return 1;
  }

  return 0;
}

void Detector::print_info() const 
{
  std::cout << "Detector Type: " << this->detector_type
            << "\nStatus: " << (this->status ? "On" : "Off") << '\n';
}



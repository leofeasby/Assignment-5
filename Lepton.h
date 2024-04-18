// Description: Models particles with attributes like mass, charge, and four-momentum.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef LEPTON_H
#define LEPTON_H

#include <string>
#include <iostream>
#include <memory> // For smart pointers
#include "FourMomentum.h"

class Lepton 
{
protected:
  double rest_mass;
  int charge; // +1 for particles, -1 for antiparticles
  std::unique_ptr<FourMomentum> four_momentum; // Using std::unique_ptr for FourMomentum

public:
  Lepton(); // Default constructor
  Lepton(double mass, int charge, double energy, double px, double py, double pz); // Parameterized constructor
  Lepton(const Lepton& other); // Copy constructor
  Lepton& operator=(const Lepton& other); // Copy assignment operator
  Lepton(Lepton&& other) noexcept; // Move constructor
  Lepton& operator=(Lepton&& other) noexcept; // Move assignment operator
  ~Lepton(); // Destructor

  // Setters
  void set_rest_mass(double mass);
  void set_charge(int charge);
  void set_four_momentum(double energy, double px, double py, double pz);

  // Getters
  double get_rest_mass() const;
  int get_charge() const;
  double get_e() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;

  // Other member functions
  virtual void print_info() const; // Make this method virtual and public
  FourMomentum operator+(const Lepton& other) const; // Overloaded "+" operator for summing four-vectors
  double dot_product(const Lepton& other) const; // Function for the dot product of two particle four-vectors
  std::string get_particle_kind() const 
  {
    return charge > 0 ? "Antiparticle" : "Particle";
  }

  virtual std::string get_particle_type() const = 0; // Pure virtual function

  // Friend function declarations
  friend FourMomentum sum_four_momenta(const Lepton& lepton1, const Lepton& lepton2);
  friend double dot_product_four_momenta(const Lepton& lepton1, const Lepton& lepton2);

  static const double light_speed;
};

#endif 

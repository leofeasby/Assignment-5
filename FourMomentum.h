// Description: Defines the FourMomentum class for managing energy and momentum components.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <vector>
#include <stdexcept>

class FourMomentum 
{
private:
  std::vector<double> momentum; // Stores [energy, px, py, pz]

public:
  FourMomentum(double energy = 0.0, double px = 0.0, double py = 0.0, double pz = 0.0)
    : momentum{energy, px, py, pz} 
  {}

  // Copy Constructor
  FourMomentum(const FourMomentum& other) 
    : momentum(other.momentum) 
  {}

  // Copy Assignment Operator
  FourMomentum& operator=(const FourMomentum& other) 
  {
    if (this != &other) 
    {
      momentum = other.momentum;
    }
    return *this;
  }

  // Move Constructor
  FourMomentum(FourMomentum&& other) noexcept 
    : momentum(std::move(other.momentum)) 
  {}

  // Move Assignment Operator
  FourMomentum& operator=(FourMomentum&& other) noexcept 
  {
    if (this != &other) 
    {
      momentum = std::move(other.momentum);
    }
    return *this;
  }

  // Destructor
  ~FourMomentum() = default;

  // Setters
  void set_energy(double energy) 
  { 
    if (energy > 0) 
    {
      momentum[0] = energy; 
    } 
    else 
    {
      throw std::invalid_argument("Energy must be greater than 0");
    }
  }
  void set_px(double px) { momentum[1] = px; }
  void set_py(double py) { momentum[2] = py; }
  void set_pz(double pz) { momentum[3] = pz; }

  // Getters
  double get_energy() const { return momentum[0]; }
  double get_px() const { return momentum[1]; }
  double get_py() const { return momentum[2]; }
  double get_pz() const { return momentum[3]; }
};

#endif 

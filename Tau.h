// Description: Defines the Tau class, inheriting from Lepton, with specific decay modes and products.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef TAU_H
#define TAU_H

#include "Lepton.h"
#include <memory>
#include <vector>

enum class TauDecayMode { Hadronic, Leptonic };

class Tau : public Lepton 
{
private:
  TauDecayMode decay_mode;
  std::vector<std::shared_ptr<Lepton>> decay_products;

public:
  Tau(double mass, int charge, double energy, double px, double py, double pz, TauDecayMode mode)
    : Lepton(mass, charge, energy, px, py, pz), decay_mode(mode) {}

  void set_decay_mode(TauDecayMode mode) 
  {
    decay_mode = mode;
  }

  TauDecayMode get_decay_mode() const 
  {
    return decay_mode;
  }

  void add_decay_product(std::shared_ptr<Lepton> product) 
  {
    if (decay_mode == TauDecayMode::Leptonic) 
    {
      decay_products.push_back(product);
    }
  }

  const std::vector<std::shared_ptr<Lepton>>& get_decay_products() const 
  {
    return decay_products;
  }

  std::string get_particle_type() const override 
  {
    return "Tau";
  }
};

#endif // TAU_H
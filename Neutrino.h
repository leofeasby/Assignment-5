// Description: Defines the Neutrino class, inheriting from Lepton, with additional flavor and interaction properties.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include "Lepton.h"

class Neutrino : public Lepton 
{
private:
  std::string flavor; // "muon" or "electron"
  bool has_interacted;

public:
  Neutrino(double mass, int charge, double energy, double px, double py, double pz, const std::string& flavor, bool interacted = false)
    : Lepton(mass, charge, energy, px, py, pz), flavor(flavor), has_interacted(interacted) 
  {
  }

  void set_has_interacted(bool interacted) 
  {
    has_interacted = interacted;
  }

  bool get_has_interacted() const 
  {
    return has_interacted;
  }

  std::string get_particle_type() const override 
  {
    return flavor + " neutrino";
  }
};

#endif // NEUTRINO_H
// Description: Defines the Muon class, inheriting from Lepton, with an additional isolation property.
// Author: Leo Feasby
// Date: 18/04/2024

#include "Lepton.h"

class Muon : public Lepton 
{
private:
  bool is_isolated;

public:
  // Declaration of Muon constructor
  Muon(double mass, int charge, double energy, double px, double py, double pz, bool isolated = false);

  void set_isolated(bool isolated);

  bool get_isolated() const;

  std::string get_particle_type() const override 
  {
    return "Muon";
  }

  Muon operator+(const Muon& other) const 
  {
    return Muon(this->get_rest_mass() + other.get_rest_mass(),
                this->get_charge() + other.get_charge(),
                this->get_e() + other.get_e(),
                this->get_px() + other.get_px(),
                this->get_py() + other.get_py(),
                this->get_pz() + other.get_pz(),
                this->is_isolated && other.is_isolated);
  }
};

// Description: Defines the Electron class, inheriting from Lepton, and manages calorimeter layer energies.
// Author: Leo Feasby
// Date: 18/04/2024

#include "Lepton.h"
#include <array>

class Electron : public Lepton 
{
private:
  std::array<double, 4> calorimeter_layers; // EM_1, EM_2, HAD_1, HAD_2

public:
  Electron(double mass, int charge, double energy, double px, double py, double pz); // Constructor declaration only

  void set_layer_energies(const std::array<double, 4>& energies); // Method declaration only

  std::array<double, 4> get_layer_energies() const; // Method declaration only

  void adjust_layer_energies();

  void set_energy(double energy);

  std::string get_particle_type() const override 
  {
    return "Electron";
  }

  void print_info() const override; // Declaration only

  Electron operator+(const Electron& other) const 
  {
    return Electron(this->get_rest_mass() + other.get_rest_mass(),
                    this->get_charge() + other.get_charge(),
                    this->get_e() + other.get_e(),
                    this->get_px() + other.get_px(),
                    this->get_py() + other.get_py(),
                    this->get_pz() + other.get_pz());
  }
  // Additional electron-specific methods can be added here
};

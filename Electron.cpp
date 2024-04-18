// Description: Defines the Electron class, inheriting from Lepton, and manages calorimeter layer energies.
// Author: Leo Feasby
// Date: 18/04/2024

#include "Electron.h"
#include <numeric>

// Constructor with initial energy validation
Electron::Electron(double mass, int charge, double energy, double px, double py, double pz)
  : Lepton(mass, charge, (energy > 0 ? energy : throw std::invalid_argument("Energy must be greater than 0")), px, py, pz), calorimeter_layers{0, 0, 0, 0} 
{
}

// Sets the calorimeter layer energies and adjusts them to match the electron's total energy
void Electron::set_layer_energies(const std::array<double, 4>& energies) 
{
  calorimeter_layers = energies;
  adjust_layer_energies();
}

// Returns the current energies of the calorimeter layers
std::array<double, 4> Electron::get_layer_energies() const 
{
  return calorimeter_layers;
}

// Adjusts each layer's energy to ensure the sum matches the electron's total energy
void Electron::adjust_layer_energies() 
{
  double total_layer_energy = std::accumulate(calorimeter_layers.begin(), calorimeter_layers.end(), 0.0);
  double energy_difference = this->get_e() - total_layer_energy;

  for (auto& layer_energy : calorimeter_layers) 
  {
    layer_energy += energy_difference / calorimeter_layers.size();
  }
}

// Sets the electron's total energy, ensuring it matches the sum of the calorimeter layers' energies
void Electron::set_energy(double energy) 
{
  if (energy <= 0) 
  {
    throw std::invalid_argument("Energy must be greater than 0");
  }
  double total_layer_energy = std::accumulate(calorimeter_layers.begin(), calorimeter_layers.end(), 0.0);
  if (energy != total_layer_energy) {
    throw std::invalid_argument("Energy must match the sum of the calorimeter layers' energies.");
  }
  this->four_momentum->set_energy(energy);
}
void Electron::print_info() const
{
  Lepton::print_info(); // Call base class print function
  std::cout << "Calorimeter Layers: [";
  for (const auto& layer : calorimeter_layers) 
  {
    std::cout << layer << " ";
  }
  std::cout << "]\n";
}

// Simulating particle detection using classes and objects
// Author: Leo Feasby
// Date: 18/04/2024

#include "Electron.h"
#include "Muon.h"
#include "Detector.h"
#include "Neutrino.h"
#include "Tau.h"
#include "TauNeutrino.h"
#include <vector>
#include <iostream>
#include <memory>

int main() 
{
  std::cout << "=== Particle Detection Simulation Program Started ===\n\n";

  // Creating leptons
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Creating leptons...\n";
  Electron electron(0.511, -1, 10.2, 3, 2, 1); // mass in MeV, charge, and four-momentum components
  Muon muon1(105.7, -1, 502.3, 20, 15, 5);
  Electron antielectron(0.511, 1, 12.4, 4, 1, 3);
  Muon antimuon(105.7, 1, 480.5, 25, 10, 8);
  Electron electron2(0.511, -1, 8.9, 2, 3, 2); // Second electron
  Muon muon2(105.7, -1, 510.2, 18, 12, 6); // Second muon
  Muon muon3(105.7, -1, 495.8, 22, 14, 7); // Third muon
  Muon muon4(105.7, -1, 520.1, 19, 11, 9); // Fourth muon
  std::cout << "[SUCCESS] Leptons created successfully.\n";
  std::cout << "--------------------------------------------------\n\n";

  // Storing them in a vector
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Storing leptons in a vector...\n";
  std::vector<std::unique_ptr<Lepton>> particles;
  particles.push_back(std::make_unique<Electron>(0.511, -1, 10.2, 3, 2, 1));
  particles.push_back(std::make_unique<Electron>(0.511, -1, 8.9, 2, 3, 2));
  particles.push_back(std::make_unique<Muon>(105.7, -1, 502.3, 20, 15, 5));
  particles.push_back(std::make_unique<Muon>(105.7, -1, 510.2, 18, 12, 6));
  particles.push_back(std::make_unique<Muon>(105.7, -1, 495.8, 22, 14, 7));
  particles.push_back(std::make_unique<Muon>(105.7, -1, 520.1, 19, 11, 9));
  particles.push_back(std::make_unique<Electron>(0.511, 1, 12.4, 4, 1, 3));
  particles.push_back(std::make_unique<Muon>(105.7, 1, 480.5, 25, 10, 8));
  particles.push_back(std::make_unique<Neutrino>(0.0, 0, 10.0, 1, 2, 3, "muon", false));
  particles.push_back(std::make_unique<Neutrino>(0.0, 0, 20.0, 4, 5, 6, "electron", true));
  std::cout << "[SUCCESS] Leptons stored in vector successfully.\n";
  std::cout << "--------------------------------------------------\n\n";

  // Adding Tau particles and their decay products
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Adding Tau particles and their decay products...\n";
  auto tau_decay_muon = std::make_shared<Muon>(105.7, -1, 502.3, 20, 15, 5);
  auto tau_decay_muon_neutrino = std::make_shared<Neutrino>(0.0, 0, 10.0, 1, 2, 3, "muon", false);
  auto tau_decay_tau_neutrino = std::make_shared<TauNeutrino>(0.0, 0, 20.0, 4, 5, 6, false);

  auto tau = std::make_unique<Tau>(1776.86, -1, 700.0, 30, 20, 10, TauDecayMode::Leptonic);
  tau->add_decay_product(tau_decay_muon);
  tau->add_decay_product(tau_decay_muon_neutrino);
  tau->add_decay_product(tau_decay_tau_neutrino);
  particles.push_back(std::move(tau));

  auto anti_tau_decay_electron = std::make_shared<Electron>(0.511, 1, 12.4, 4, 1, 3);
  auto anti_tau_decay_electron_neutrino = std::make_shared<Neutrino>(0.0, 0, 10.0, 1, 2, 3, "electron", true);
  auto anti_tau_decay_tau_neutrino = std::make_shared<TauNeutrino>(0.0, 0, 20.0, 4, 5, 6, true);

  auto anti_tau = std::make_unique<Tau>(1776.86, 1, 800.0, 35, 25, 15, TauDecayMode::Leptonic);
  anti_tau->add_decay_product(anti_tau_decay_electron);
  anti_tau->add_decay_product(anti_tau_decay_electron_neutrino);
  anti_tau->add_decay_product(anti_tau_decay_tau_neutrino);
  particles.push_back(std::move(anti_tau));
  std::cout << "[SUCCESS] Tau particles added successfully.\n";
  std::cout << "--------------------------------------------------\n\n";

  // Creating a unique_ptr for a new Electron and moving its data to another Electron using std::move
  std::unique_ptr<Electron> electron_ptr = std::make_unique<Electron>(0.511, -1, 11.3, 3, 3, 2);
  std::unique_ptr<Electron> another_electron_ptr = std::move(electron_ptr);

  // Demonstrating shared_ptr for a new Tau lepton with shared ownership
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Demonstrating shared_ptr for a new Tau lepton...\n";
  std::shared_ptr<Tau> tau_ptr = std::make_shared<Tau>(1776.86, -1, 700.0, 30, 20, 10, TauDecayMode::Leptonic);
  std::cout << "Initial use_count: " << tau_ptr.use_count() << " (should be 1)\n";

  std::cout << "Sharing ownership with another_tau_ptr...\n";
  std::shared_ptr<Tau> another_tau_ptr = tau_ptr; // another_tau_ptr shares ownership of the Tau object
  std::cout << "Use count after sharing with another_tau_ptr: " << tau_ptr.use_count() << " (should be 2)\n";

  std::cout << "Sharing ownership with yet_another_tau_ptr...\n";
  std::shared_ptr<Tau> yet_another_tau_ptr = tau_ptr; // yet_another_tau_ptr also shares ownership
  std::cout << "Final use_count after sharing with yet_another_tau_ptr: " << tau_ptr.use_count() << " (should be 3)\n";
  std::cout << "--------------------------------------------------\n\n";
  
  // Summing the four-vectors of the two electrons and printing the result
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Calculating sum of electron four-vectors...\n";
  auto sum = sum_four_momenta(electron, electron2);
  std::cout << "Sum of electron four-vectors: Energy=" << sum.get_energy() 
            << ", Px=" << sum.get_px() << ", Py=" << sum.get_py() << ", Pz=" << sum.get_pz() << "\n";
  std::cout << "--------------------------------------------------\n\n";

  // Taking the dot product of the antielectron and antimuon four-vector and printing the result
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Calculating dot product of antielectron and antimuon four-vectors...\n";
  double dot_product = dot_product_four_momenta(antielectron, antimuon);
  std::cout << "Dot product of antielectron and antimuon four-vectors: " << dot_product << "\n";
  std::cout << "--------------------------------------------------\n\n";

  // Print all particles
  std::cout << "--------------------------------------------------\n";
  std::cout << "[INFO] Printing all particle information...\n";
  for (const auto& particle : particles) 
  {
      particle->print_info();
  }
  std::cout << "[SUCCESS] All particle information printed successfully.\n";
  std::cout << "--------------------------------------------------\n\n";

  std::cout << "=== Particle Detection Simulation Program Completed ===\n";
  return 0;
}


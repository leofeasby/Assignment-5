// Description: Models particles with attributes like mass, charge, and four-momentum.
// Author: Leo Feasby
// Date: 18/04/2024

#include "Lepton.h"
#include <iostream>
#include <vector>
#include <memory> // Include for smart pointers

// Speed of light
const double Lepton::light_speed = 2.99792458e8;

// Default constructor initializing default values for a Lepton object
Lepton::Lepton()
  : rest_mass(0.511), charge(-1), four_momentum(std::make_unique<FourMomentum>(0.0, 0.0, 0.0, 0.0))
{
  std::cout << "Default Lepton constructor called. Initialized with mass: " << rest_mass << ", charge: " << charge << ", and four_momentum: [0, 0, 0, 0]" << std::endl;
}

// Parameterized constructor for custom initialization of a Lepton object
Lepton::Lepton(double mass, int charge, double energy, double px, double py, double pz)
  : rest_mass(mass), charge(charge), four_momentum(std::make_unique<FourMomentum>(energy, px, py, pz))
{
  std::cout << "Parameterized Lepton constructor called. Initialized with mass: " << rest_mass << ", charge: " << charge << ", and four_momentum: [" << energy << ", " << px << ", " << py << ", " << pz << "]" << std::endl;
}

// Copy constructor for creating a deep copy of another Lepton object
Lepton::Lepton(const Lepton& other)
  : rest_mass(other.rest_mass), charge(other.charge), four_momentum(std::make_unique<FourMomentum>(*other.four_momentum))
{
  std::cout << "Calling Copy Constructor" << std::endl;
}

// Copy assignment operator for assigning one Lepton object to another
Lepton& Lepton::operator=(const Lepton& other)
{
  std::cout << "Calling Assignment Operator" << std::endl;
  if(this != &other) 
  {
    rest_mass = other.rest_mass;
    charge = other.charge;
    four_momentum = std::make_unique<FourMomentum>(*other.four_momentum);
  }
  return *this;
}

// Move constructor for transferring ownership of resources from one Lepton object to another
Lepton::Lepton(Lepton&& other) noexcept
  : rest_mass(other.rest_mass), charge(other.charge), four_momentum(std::move(other.four_momentum))
{
  // Logging the use of the move constructor
  std::cout << "Calling Move Constructor" << std::endl;
}

// Move assignment operator for transferring ownership of resources between Lepton objects
Lepton& Lepton::operator=(Lepton&& other) noexcept
{
  std::cout << "Calling Move Assignment Operator" << std::endl;
  if(this != &other) 
  {
    rest_mass = other.rest_mass;
    charge = other.charge;
    four_momentum = std::move(other.four_momentum);
  }
  return *this;
}

// Destructor for cleaning up dynamically allocated memory
Lepton::~Lepton() 
{
}

// Setter methods for updating Lepton object attributes
void Lepton::set_rest_mass(double mass) 
{
  if(mass > 0) 
  {
    rest_mass = mass;
    std::cout << "Rest mass set to: " << mass << std::endl;
  } 
  else 
  {
    std::cout << "Invalid mass. It must be positive.\n";
  }
}

void Lepton::set_charge(int charge) 
{
  this->charge = charge;
  std::cout << "Charge set to: " << charge << std::endl;
}

void Lepton::set_four_momentum(double energy, double px, double py, double pz) 
{
  if(energy > 0) 
  {
    four_momentum->set_energy(energy);
    four_momentum->set_px(px);
    four_momentum->set_py(py);
    four_momentum->set_pz(pz);
    std::cout << "Four_momentum set to: [" << energy << ", " << px << ", " << py << ", " << pz << "]" << std::endl;
  }
  else 
  {
    std::cout << "Invalid energy. It must be positive.\n";
  }
}

// Getter methods for accessing Lepton object attributes
double Lepton::get_e() const 
{
  std::cout << "Getting energy: " << four_momentum->get_energy() << std::endl;
  return four_momentum->get_energy();
}

double Lepton::get_px() const 
{ 
  std::cout << "Getting Px: " << four_momentum->get_px() << std::endl;
  return four_momentum->get_px(); 
}

double Lepton::get_py() const 
{ 
  std::cout << "Getting Py: " << four_momentum->get_py() << std::endl;
  return four_momentum->get_py(); 
}

double Lepton::get_pz() const 
{ 
  std::cout << "Getting Pz: " << four_momentum->get_pz() << std::endl;
  return four_momentum->get_pz(); 
}

double Lepton::get_rest_mass() const 
{
  std::cout << "Getting rest mass: " << rest_mass << std::endl;
  return rest_mass;
}

int Lepton::get_charge() const 
{
  std::cout << "Getting charge: " << charge << std::endl;
  return charge;
}

// Method for printing detailed information about the Lepton object
void Lepton::print_info() const 
{
  std::cout << "Particle Type: " << get_particle_type()
            << "\nRest Mass (MeV): " << rest_mass
            << "\nCharge: " << charge
            << "\nEnergy (MeV): " << get_e()
            << "\nMomentum px (MeV/c): " << get_px()
            << "\nMomentum py (MeV/c): " << get_py()
            << "\nMomentum pz (MeV/c): " << get_pz() << '\n';
}

// Friend function definition for summing two four-vectors
FourMomentum sum_four_momenta(const Lepton& lepton1, const Lepton& lepton2) {
    return FourMomentum(
        lepton1.get_e() + lepton2.get_e(),
        lepton1.get_px() + lepton2.get_px(),
        lepton1.get_py() + lepton2.get_py(),
        lepton1.get_pz() + lepton2.get_pz()
    );
}

// Friend function definition for dot product of two four-vectors
double dot_product_four_momenta(const Lepton& lepton1, const Lepton& lepton2) {
    return lepton1.get_e() * lepton2.get_e() -
           (lepton1.get_px() * lepton2.get_px() +
            lepton1.get_py() * lepton2.get_py() +
            lepton1.get_pz() * lepton2.get_pz());
}


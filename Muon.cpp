// Description: Defines the Muon class, inheriting from Lepton, with additional isolation property.
// Author: Leo Feasby
// Date: 18/04/2024

#include "Muon.h"

Muon::Muon(double mass, int charge, double energy, double px, double py, double pz, bool isolated)
    : Lepton(mass, charge, energy, px, py, pz), is_isolated(isolated) {}

bool Muon::get_isolated() const 
{
    return is_isolated;
}
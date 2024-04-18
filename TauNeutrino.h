// Description: Defines the TauNeutrino class, inheriting from Lepton, with interaction properties.
// Author: Leo Feasby
// Date: 18/04/2024

#ifndef TAUNEUTRINO_H
#define TAUNEUTRINO_H

#include "Lepton.h"

class TauNeutrino : public Lepton 
{
private:
    bool hasInteracted;

public:
    TauNeutrino(double mass, int charge, double energy, double px, double py, double pz, bool interacted = false)
        : Lepton(mass, charge, energy, px, py, pz), hasInteracted(interacted) 
        {}

    void setHasInteracted(bool interacted) 
    {
        hasInteracted = interacted;
    }

    bool getHasInteracted() const 
    {
        return hasInteracted;
    }

    std::string get_particle_type() const override 
    {
        return "tau neutrino";
    }
};

#endif 
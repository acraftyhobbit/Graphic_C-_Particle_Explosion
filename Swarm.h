//
// Created by user on 2/27/18.
//

#ifndef SDL2_SWARM_H
#define SDL2_SWARM_H


#include "Particles.h"

class Swarm {
private:
    Particles *m_pParticles;
    int lastTime;
public:
    Swarm();
    const static int NPARTICLES = 5000;
    ~Swarm();
    Particles * const getParticles(){ return m_pParticles;  };
    void update(int elapsed);
};


#endif //SDL2_SWARM_H

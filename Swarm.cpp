//
// Created by user on 2/27/18.
//

#include "Swarm.h"

Swarm::Swarm(): lastTime(0) {
    m_pParticles = new Particles [NPARTICLES];

}

Swarm::~Swarm() {
    delete [] m_pParticles;

}
void Swarm::update(int elapsed) {

    int interval = elapsed - lastTime;
    for(int i=0; i<Swarm::NPARTICLES;i++){
    m_pParticles[i].update(interval);
    }
    lastTime = elapsed;
}

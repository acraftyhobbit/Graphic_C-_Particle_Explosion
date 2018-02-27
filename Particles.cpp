//
// Created by user on 2/27/18.
//
#include <stdlib.h>

#include "Particles.h"

Particles::Particles() {
    m_x = ((2.0 * rand())/RAND_MAX)- 1;
    m_y = ((2.0 * rand())/RAND_MAX)- 1;


}

void Particles::update() {

}

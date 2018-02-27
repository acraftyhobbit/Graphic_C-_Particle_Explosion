//
// Created by user on 2/27/18.
//
#include <stdlib.h>
#include <math.h>
#include "Particles.h"

Particles::Particles(): m_x(0), m_y(0) {
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.001 * rand())/RAND_MAX;


}

void Particles::update() {
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed;
    m_y += yspeed;
}

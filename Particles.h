//
// Created by user on 2/27/18.
//

#ifndef SDL2_PARTICLES_H
#define SDL2_PARTICLES_H


class Particles {

public:
    Particles();
    void update(int interval);
    double m_x;
    double m_y;
private:
    double m_speed;
    double m_direction;
    void init();
};


#endif //SDL2_PARTICLES_H

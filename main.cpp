#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include "Swarm.h"
#include "Particles.h"
using namespace std;



int main() {

    srand(time(NULL));

    Screen screen;

    if(!screen.init()){
        cout << "Error has occurred" << endl;
    }

    Swarm swarm;

    while(true){

        int elapsed = SDL_GetTicks();
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        const Particles * const pParticles = swarm.getParticles();

        for(int i=0; i<Swarm::NPARTICLES;i++){
            Particles particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREENWIDTH/2;
            int y = (particle.m_y + 1) * Screen::SCREENHEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }


        screen.update();

        if(!screen.processEvent()){
            break;
        }


    }

    screen.close();

    return 0;
}

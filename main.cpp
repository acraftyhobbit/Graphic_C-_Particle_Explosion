#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
using namespace std;



int main() {

    Screen screen;

    if(!screen.init()){
        cout << "Error has occurred" << endl;
    }


    while(true){
        int elapsed = SDL_GetTicks();
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        for(int y = 0; y < Screen::SCREENHEIGHT; y++){
            for(int x=0; x < Screen::SCREENWIDTH; x++){
                screen.setPixel(x, y, red, green, blue);
            }
        }


        screen.update();

        if(!screen.processEvent()){
            break;
        }


    }

    screen.close();

    return 0;
}

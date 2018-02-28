//
// Created by user on 2/26/18.
//

#ifndef SDL2_SCREEN_H
#define SDL2_SCREEN_H

#include<SDL.h>


class Screen {
public:
    const static int SCREENWIDTH = 800;
    const static int SCREENHEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;

public:
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvent();
    void close();
    void boxBlur();

};


#endif //SDL2_SCREEN_H

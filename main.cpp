#include <iostream>
#include <SDL.h>
using namespace std;



int main() {
    const int SCREENWIDTH = 800;
    const int SCREENHEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREENWIDTH,SCREENHEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL){
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREENWIDTH, SCREENHEIGHT);

    if(renderer == NULL){
        cout << "Couldn't render file." << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if(texture == NULL){
        cout << "Couldn't texture file." << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    Uint32 *buffer = new Uint32[SCREENWIDTH*SCREENHEIGHT];

    memset(buffer, 0xFF, SCREENWIDTH*SCREENHEIGHT* sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREENWIDTH* sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);


    bool quit = false;

    SDL_Event event;

    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

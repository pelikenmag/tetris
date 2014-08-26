#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(){

  SDL_Window* gWindow = NULL;
  SDL_Renderer* gRenderer = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  gWindow=SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640,480,SDL_WINDOW_SHOWN);
  gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear( gRenderer );
  while(1)
    SDL_RenderPresent(gRenderer);


  return 0;
}
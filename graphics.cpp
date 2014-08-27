#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
const int SCREEN_HEIGHT=640;
const int SCREEN_WIDTH=320;

int main(){

  bool quit=false;
  SDL_Window* gWindow = NULL;
  SDL_Renderer* gRenderer = NULL;
  SDL_Event event_handle;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  gWindow=SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,\
   SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

  gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear( gRenderer );

  while(!quit){
    
    while(SDL_PollEvent(&event_handle)!=0){
      if (event_handle.type == SDL_QUIT){

        quit=true;
      }
    }

    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_WIDTH / 4, SCREEN_WIDTH / 4, SCREEN_WIDTH / 4 };
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );    
    SDL_RenderFillRect( gRenderer, &fillRect );
    //SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0x00,0xFF);
    //SDL_RenderClear( gRenderer );
    SDL_RenderPresent(gRenderer);
  }

  return 0;
}
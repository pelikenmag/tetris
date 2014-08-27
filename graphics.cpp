#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
const int CELL_SIZE=20;
const int SCREEN_HEIGHT=CELL_SIZE*20;
const int SCREEN_WIDTH=CELL_SIZE*10;

const int test_matrix[10*10]={0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,1,0,0,0,0,0,
                              0,0,0,0,1,1,0,0,0,0,
                              0,0,0,0,0,1,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              1,0,0,0,0,0,0,0,0,0,
                              1,0,0,0,0,0,0,0,0,0,
                              1,0,0,1,0,0,0,0,1,1,
                              1,0,0,1,1,1,0,0,0,1 };


int main(){

  bool quit=false;
  int i,j;
  SDL_Window* gWindow = NULL;
  SDL_Renderer* gRenderer = NULL;
  SDL_Event event_handle;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  gWindow=SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,\
   320,640,SDL_WINDOW_SHOWN);

  gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear( gRenderer );

  while(!quit){
    for(i=0;i<10;i++){
      for(j=0;j<10;j++){

        if (test_matrix[i*10+j]==1){
          SDL_Rect fillRect = { j*20, i*20, 20, 20 };
          SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );    
          SDL_RenderFillRect( gRenderer, &fillRect );
        }
        SDL_Rect outRect= {i*20,j*20,20,20};
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer,&outRect);

        
      }
    }

    while(SDL_PollEvent(&event_handle)!=0){
      if (event_handle.type == SDL_QUIT){

        quit=true;
      }
    }
    SDL_RenderPresent(gRenderer);
  }
  return 0;
}
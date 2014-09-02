#include "tetris.h"


void DrawWorld::Init(){

  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  gWindow=SDL_CreateWindow("SDL Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,\
   320,640,SDL_WINDOW_SHOWN);
  gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear( gRenderer );

}
void DrawWorld::Draw(Field &gamefield){
  int i,j;
  int n=gamefield._n;
  int m=gamefield._m;
  bool quit=false;
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
  SDL_RenderClear( gRenderer );
  
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){

        if (gamefield.showme[i*m+j]==1){
          SDL_Rect fillRect = { j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE };
          SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );    
          SDL_RenderFillRect( gRenderer, &fillRect );
        }
        SDL_Rect outRect= {j*CELL_SIZE,i*CELL_SIZE,CELL_SIZE,CELL_SIZE};
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer,&outRect);
      }
    }
    SDL_RenderPresent(gRenderer);
}

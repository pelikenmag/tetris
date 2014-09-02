#include "tetris.h"


int main(){

  Field gamefield;
  Shape myshape;
  st_MERGEME mergeme;
  SDL_Event event_handle;

  gamefield.Init(FIELD_SIZE_N,FIELD_SIZE_M);
  int i,j,x=DEFAULT_X,y=DEFAULT_Y,mergeresult,protox=x;
  char arrow;
  bool quit=false;

  myshape.Generate(SHAPE_STICK);
  DrawWorld window2D;

  window2D.Init();

  
  while (!quit){
 
    while (1){ 
      
      mergeme.shape=myshape.GetShape();mergeme.sn=myshape.GetShapeN();mergeme.sm=myshape.GetShapeM();
      mergeme.x=x;mergeme.y=y;
      mergeresult=gamefield.Merge(mergeme);

      if (mergeresult==FIELD_OK)
        break;
      if (mergeresult==FIELD_BORDER || mergeresult==FIELD_BORDER|FIELD_BOTTOM){
        std::cout<<"Border!"<<endl;
        x=protox;
      }
      if (mergeresult==FIELD_BOTTOM){
        std::cout<<"Bottom!"<<endl;
        myshape.Generate(SHAPE_ANGLE);
        x=DEFAULT_X;y=DEFAULT_Y;
      }
    }
    int *filled_lines=gamefield.FindFilledLines();
    if (filled_lines){
      gamefield.DelFilledLines(filled_lines);    
      gamefield.NormalizeLines(filled_lines);
    }
    gamefield.CreateShowField(mergeme);
    
    
    protox=x;
    window2D.Draw(gamefield);
    

    while(SDL_PollEvent(&event_handle)!=0){
      if (event_handle.type==SDL_QUIT){
        quit=true;
        break;
      }
      if(event_handle.type==SDL_KEYDOWN)
        switch(event_handle.key.keysym.sym){
        case SDLK_LEFT:
          x--;
          break;
        case SDLK_RIGHT:
          x++;
          break;
        case SDLK_DOWN:
          y++;
          break;
        case SDLK_UP:
          myshape.Rotate();
          break;
        default:
          break;
        }
  
    }

  }
  return 0;
}

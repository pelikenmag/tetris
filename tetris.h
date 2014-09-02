#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
//=====common

//=====graphics

  const int CELL_SIZE=20;
  const int SCREEN_HEIGHT=CELL_SIZE*20;
  const int SCREEN_WIDTH=CELL_SIZE*10;

class DrawWorld{

private:
SDL_Window* gWindow;
SDL_Renderer* gRenderer;

public:
void Init();
void Draw(class Field &);
void Close();

};
//=====core


//Structure for Merge and other functions
struct st_MERGEME{
  int *shape;
  int sn,sm;
  int x,y;
};
//Constants
  //Sizes and defaults
  const int FIELD_SIZE_N=20;
  const int FIELD_SIZE_M=10;
  const int DEFAULT_X=4;
  const int DEFAULT_Y=0;
  //Variables for Field::Merge()
  const int FIELD_OK=0;
  const int FIELD_BOTTOM=1;
  const int FIELD_BORDER=2;
  //Variables for Field::Show()
  const int FIELD_AS_TEXT=0;
  const int FIELD_AS_2D=1;
  const int SHOWME_AS_TEXT=2;
  const int SHOWME_AS_2D=3;
  //Variables for Shape::Generate()
  const int SHAPE_ANGLE=0;
  const int SHAPE_STICK=1;

  //Game field class
class Field{

  
  private:
    int *_field;
    int fn,fm;
    int *showme;
    int _n,_m;



  public:
    void Init(int, int);
    int Merge(struct st_MERGEME);
    void Show(int);
    void CreateShowField(struct st_MERGEME);
    friend class DrawWorld;
    int *FindFilledLines();
    void DelFilledLines(int *);
    void NormalizeLines(int *);
};
//Shapes class
class Shape{

  private:

    int *shapepointer;
    int shapesize;
    int shape_n,shape_m;

    int anglesize;
    int *angle;
    int angle_n,angle_m;

    int sticksize;
    int stick_n,stick_m;
    int *stick;


  void ShowShapePointer(){
    int i,j;
    if (!shapepointer){
      std::cout<<"Shapepointer is not initialized"<<endl;
    }
    else{
      for (i=0;i<shape_n;i++){
        for (j=0;j<shape_m;j++){
          std::cout<<shapepointer[i*shape_m+j];
        }
        std::cout<<endl;
      }
    }
  }

  public:
    Shape();
    void Generate(int);
    void Rotate();
    int* GetShape(){return shapepointer;}
    int  GetShapeN(){return shape_n;}
    int  GetShapeM(){return shape_m;}
};

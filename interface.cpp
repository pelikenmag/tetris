#include <iostream>
using namespace std;

//Struct for Field::Merge()
struct _mergeresult{
int *showme;
int bottom;
int border;
};
typedef _mergeresult mergeresult;
//Variables for Field::Show()
const int FIELD_AS_TEXT=0;
const int FIELD_AS_2D=1;
//Variables for Shape::Generate()
const int SHAPE_ANGLE=0;
const int SHAPE_STICK=1;

//Game main matrix class
class Field{

  private:
    int *_field;
    int fn,fm;


  public:
    void Init(int, int);
    mergeresult* Merge(int*,int);
    void Show(int);
};

//Shapes class
class Shape{

  private:

    int *shapepointer;
    int shapesize;

    int anglesize;
    int *angle;

    int sticksize;
    int *stick;

 
  void ShowShapePointer(){
    int i,j;
    if (!shapepointer){
      std::cout<<"Shapepointer is not initialized"<<endl;
    }
    else{
      for (i=0;i<shapesize;i++){
        for (j=0;j<shapesize;j++){
          std::cout<<shapepointer[i*shapesize+j];
        }
        std::cout<<endl;
      }
    }
  }

  public:
    Shape();
    void Generate(int);
};

//-----------------------------------
int main(){

  //Field main;
  //main.Init(20,10);
  //main.Show(FIELD_AS_TEXT);
  
  class Shape myshape;
  myshape.Generate(SHAPE_STICK);


  return 0;
}
//------------------------------------
/*
Functions
*/
//Generates new shape, deletes an old one
void Shape::Generate(int shapename){
  int i;
  if (!shapepointer)
    delete shapepointer;

  switch(shapename){

    case SHAPE_ANGLE:
      shapepointer=new int [anglesize*anglesize];
      for(int i=0;i<anglesize*anglesize;i++)
        shapepointer[i]=angle[i];
      shapesize=anglesize;
      break;
    case SHAPE_STICK:
      shapepointer=new int [sticksize*sticksize];
      for(int i=0;i<sticksize*sticksize;i++)
        shapepointer[i]=stick[i];
      shapesize=sticksize;
      break;
    default:
      break;
  }
  ShowShapePointer();
}
//Shape default constructor
Shape::Shape(){

      int i;
      shapepointer=0;
      
      /*
      Angle
      { 0,1,
        1,1 };
      */

      anglesize=2;
      angle=new int[anglesize*anglesize];
      for (i=0;i<anglesize*anglesize;i++)
        angle[i]=1;
      angle[0]=0;
      

      /*
      Stick
      { 0,0,0,0,0,
        0,0,0,0,0,
        0,0,1,1,0,
        0,0,1,0,0,
        0,0,1,0,0 };
      */

      sticksize=5;
      stick=new int[sticksize*sticksize];
      for (i=0;i<sticksize*sticksize;i++)
        stick[i]=0;
      stick[12]=stick[13]=stick[17]=stick[22]=1;
      }
//Creates game field
void Field::Init(int n,int m){
  int i,j;
  fn=n+1;fm=m+6;
  _field=new int [fn*fm];

  for (i=0;i<fn;i++){
    for(j=0;j<fm;j++){
      if((j<3 || j>=fm-3)||(i==fn-1))
        _field[i*fm+j]=1;
      else
        _field[i*fm+j]=0;
    }
  }
}
//Shows game field
void Field::Show(int look){
  int i,j;
  if (look==FIELD_AS_TEXT){
    for(i=0;i<fn;i++){
      for(j=0;j<fm;j++){
        cout<<_field[i*fm+j]<<"|";
        }

      cout<<endl;
    }
  }
}
#include <iostream>
#include <time.h>
using namespace std;

//Variables for Field::Merge()
const int FIELD_BOTTOM=1;
const int FIELD_BORDER=2;
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
    int Merge(int*,int,int,int,int);
    void Show(int);
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

//-----------------------------------
int main(){

  int t=clock();
  Field main;Shape myshape;
  main.Init(20,10);
  
  myshape.Generate(SHAPE_STICK);
  cout<<endl;
  myshape.Rotate();
  
  int mergeres=main.Merge(myshape.GetShape(),myshape.GetShapeN(),myshape.GetShapeM(),4,2);
  cout<<mergeres<<endl;
  main.Show(FIELD_AS_TEXT);


  return 0;
}
/*
Functions
*/
//
//TODO- delete unused memory
int Field::Merge(int *shape, int sn,int sm,int x,int y){
  int result=0,i,j;
  
  x+=3;//converting to _field size, jumping through the first three "1" symbols
  for (i=0;i<sn;i++){
    for(j=0;j<sm;j++){
      if (_field[x+j+(i+y)*fm]>0 && shape[i*sm+j]>0)
                return result|=FIELD_BORDER;
      if (_field[x+(y+i+1)*fm+j]>0 && shape[i*sm+j]>0)
                result|=FIELD_BOTTOM;
    }
  }
  if (result!=FIELD_BOTTOM){
      for (i=0;i<sn;i++)
        for(j=0;j<sm;j++)
          _field[x+j+(i+y)*fm]=shape[i*sm+j];
  }


  return result;
}
//Rotates the shape
//TODO- delete unused memory 
void Shape::Rotate(){
  int i,j,tmp;
  int *matrix=new int [shapesize];

  for (i=0;i<shape_m;i++)
    for(j=shape_n-1;j>=0;j--)
      matrix[i*shape_n+shape_n-1-j]=shapepointer[j*shape_m+i];

  shapepointer=matrix;
  tmp=shape_n;
  shape_n=shape_m;
  shape_m=tmp;

  ShowShapePointer();
}
//Generates new shape, deletes an old one
//TODO- delete unused memory 
void Shape::Generate(int shapename){
  int i;
  if (!shapepointer)
    delete shapepointer;

  switch(shapename){

    case SHAPE_ANGLE:
      shapepointer=new int [anglesize];
      for(int i=0;i<anglesize;i++)
        shapepointer[i]=angle[i];
      shapesize=anglesize;
      shape_n=angle_n;
      shape_m=angle_m;
      break;
    case SHAPE_STICK:
      shapepointer=new int [sticksize];
      for(int i=0;i<sticksize;i++)
        shapepointer[i]=stick[i];
      shapesize=sticksize;
      shape_n=stick_n;
      shape_m=stick_m;
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
      angle_n=2;angle_m=2;
      anglesize=angle_n*angle_m;
      angle=new int[anglesize];
      angle[1]=angle[2]=angle[3]=1;
      angle[0]=0;
      

      /*
      Stick
      { 1,0,
        1,0,
        1,1 };
      */

      stick_n=3,stick_m=2;
      sticksize=stick_n*stick_m;
      stick=new int[sticksize];
      stick[0]=stick[2]=stick[4]=stick[5]=1;
      stick[1]=stick[3]=0;
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
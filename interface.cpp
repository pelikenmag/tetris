#include <iostream>
#include <time.h>
using namespace std;

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

//Game main matrix class
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

  //int t=clock();
  Field main;
  Shape myshape;
  st_MERGEME mergeme;

  main.Init(FIELD_SIZE_N,FIELD_SIZE_M);
  int i,j,x=DEFAULT_X,y=DEFAULT_Y,mergeresult,protox=x;
  char arrow;

  myshape.Generate(SHAPE_STICK);
  cout<<endl;
  while (arrow!='z'){

    while (1){
      mergeme.shape=myshape.GetShape();mergeme.sn=myshape.GetShapeN();mergeme.sm=myshape.GetShapeM();
      mergeme.x=x;mergeme.y=y;
      mergeresult=main.Merge(mergeme);
      cout<<"Mergeresult= "<<mergeresult<<endl;

      if (mergeresult==FIELD_OK)
        break;
      if (mergeresult==FIELD_BORDER && mergeresult==FIELD_BORDER|FIELD_BOTTOM){
        cout<<"Border!"<<endl;
        x=protox;
      }
      if (mergeresult==FIELD_BOTTOM){
        cout<<"Bottom!"<<endl;
        myshape.Generate(SHAPE_ANGLE);
        x=DEFAULT_X;y=DEFAULT_Y;
      }

    }
    main.CreateShowField(mergeme);
    main.Show(SHOWME_AS_TEXT);

    cout<<"Enter the direction:"<<endl;
    cin>>arrow;
    protox=x;

    switch(arrow){
    case 'a':x--;break;
    case 'd':x++;break;
    case 's':y++;break;
    case 'w':myshape.Rotate();
    default:;
    }

  }

  return 0;
}

//*Functions
void Field::CreateShowField(struct st_MERGEME st){

  int i,j;

  for (i=0;i<_n;i++){
    for (j=0;j<_m;j++){
      showme[i*_m+j]=_field[i*fm+j+3];
    }
  }
      for (i=0;i<st.sn;i++)
        for(j=0;j<st.sm;j++)
          showme[st.x+j+(i+st.y)*_m]+=st.shape[i*st.sm+j];

}

//TODO- delete unused memory
int Field::Merge(struct st_MERGEME st){
  int result=0,i,j;

  st.x+=3;//converting to _field size, jumping through the first three "1" symbols
  for (i=0;i<st.sn;i++){
    for(j=0;j<st.sm;j++){
      if (_field[st.x+j+(i+st.y)*fm]>0 && st.shape[i*st.sm+j]>0)
                return result|=FIELD_BORDER;
      if (_field[st.x+(st.y+i+1)*fm+j]>0 && st.shape[i*st.sm+j]>0)
                result|=FIELD_BOTTOM;
    }
  }
  if (result==FIELD_BOTTOM){
      for (i=0;i<st.sn;i++)
        for(j=0;j<st.sm;j++)
          _field[st.x+j+(i+st.y)*fm]+=st.shape[i*st.sm+j];
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

  //ShowShapePointer();
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
  _n=n;_m=m;
  showme=new int [_n*_m];
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
  if (look==SHOWME_AS_TEXT){
    for(i=0;i<_n;i++){
      for(j=0;j<_m;j++){
        cout<<showme[i*_m+j]<<"|";
        }
      cout<<endl;
    }
  }
}

#include "tetris.h"

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
//TODO- put the code related with showme to the DrawWorld class
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
int *Field::FindFilledLines(){
  int i,j;
  int *line_numbers=new int[fn-1];
  bool empty=true;
  for (i=0;i<fn-1;i++){
    
    for (j=0;j<fm;j++){
      if (!_field[i*fm+j])
          break;

    }
    if (j==fm){
      line_numbers[i]=1;
      empty=false;
    }
    else
      line_numbers[i]=0;
  }
if (empty)
  return 0;  
return line_numbers;  
}

void Field::DelFilledLines(int *line_numbers){
  int i,j;

  for (i=0;i<fn-1;i++){
    if (line_numbers[i]==0)
      continue;
    for (j=0;j<fm-3;j++)
      _field[i*fm+j+3]=0;
  }

}
void Field::NormalizeLines(int *line_numbers){

  int i,j,k;

  for (k=0;k<fn;k++){
    if (line_numbers[k]==1){
      for (i=k;i>0;i--){
        for (j=0;j<fm;j++){
          _field[i*fm+j]=_field[(i-1)*fm+j];
          if (j>=3 && j<fm-3)
            _field[(i-1)*fm+j]=0;

        }
      }
    }
  }
}

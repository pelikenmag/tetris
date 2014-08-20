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



int main(){

  Field main;
  main.Init(20,10);
  main.Show(FIELD_AS_TEXT);
  return 0;
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
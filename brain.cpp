#include <iostream>
using namespace std;
void draw_matrix(int *,int);
void turn_matrix(int *,int );
void merge(int *,int,int *,int,int,int);


int main(){

  int x,y;
  char arrow=0;
	int main[16*21]={	2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,
										1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1	};
	int shape1[2*2]={	0,1,
										1,1};

  int

  x=5;y=0;
/*
  while (arrow!='z'){
    cout<<"Enter the direction:"<<endl;
    cin>>arrow;
    cout<<y<<endl;

    switch(arrow){
    case 'a':
      x--;
      break;
    case 'd':
      x++;
      break;
    case 's':
      y++;
      break;
    default:;

    }
    merge(main,0,shape1,2,x,y);
  }
*/
	return 0;
}
void merge(int *main,int main_size, int *shape,int shape_size,int x,int y){
	int i=0,j=0;
	bool collision,bottom;


	//turn_matrix(shape,shape_size);

	for (i=0,collision=bottom=false;i<shape_size;i++){
		for(j=0;j<shape_size;j++){
			if (main[x+(i+y)*16+j]>0 && shape[i*shape_size+j]>0)
                collision=true;
            if (main[x+(y+i+1)*16+j]>0 && shape[i*shape_size+j]>0)
                bottom=true;
		}
	}
	if (bottom==true && collision==false){
      for (i=0;i<shape_size;i++)
        for(j=0;j<shape_size;j++)
          main[x+(i+y)*16+j]=shape[i*shape_size+j];
	}
  cout<<"-----------------------------"<<endl;
	for(i=0;i<21;i++){
		for(j=0;j<16;j++){
			cout<<main[i*16+j]<<"|";
		}
		cout<<endl;
	}
    cout<<"collision: "<<collision<<" bottom: "<<bottom<<endl;


}
//Функция поворота матрицы (вправо)
//Вход: матрица, размер
void turn_matrix(int *matrix,int n){
  int i=0,j=0,k,tmp,on=n;

  for(;n>1;i=0,j=0){
    for(;j<n-1;j++){            //цикл прохода по элементам верхней строки матрицы
                                    //взаимообмен значениями 4-х элементов
                                    //начиная с [0,j]
      tmp=matrix[j*(on)+n-1-i];
      matrix[j*(on)+n-1-i]=matrix[i*(on)+j];
      matrix[i*(on)+j]=matrix[(n-1-j)*(on)+i];
      matrix[(n-1-j)*(on)+i]=matrix[(n-1-i)*(on)+n-1-j];
      matrix[(n-1-i)*(on)+n-1-j]=tmp;
    }
  matrix=matrix+on+1;n=n-2;//переход к более меньшей подматрице размера N-2
  }
}
//Функция вывода содержимого матрицы в консоль
//Вход: матрица, размер
void draw_matrix(int matrix[],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<matrix[i*size+j]<<" ";
		}
		cout<<endl;
	}
}

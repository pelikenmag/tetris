#include <iostream>
using namespace std;
void draw_matrix(int *,int);
void turn_matrix(int *,int );
void merge(int *,int,int *,int,int,int);


int main(){

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
	merge(main,0,shape1,2,5,0);									
    

	
	return 0;
}
void merge(int *main,int main_size, int *shape,int shape_size,int x,int y){
	int i=0,j=0;
	
	/*
	for(i=0;i<21;i++){
		for(j=0;j<16;j++){
			cout<<main[1*16+j]<<"	";
		}
		cout<<endl;
	}
	*/
	turn_matrix(shape,shape_size);

	for (i=0;i<shape_size;i++){
		for(j=0;j<shape_size;j++){
			main[x+y+i*16+j]=shape[i*shape_size+j];

		}


	}
	for(i=0;i<21;i++){
		for(j=0;j<16;j++){
			cout<<main[i*16+j]<<"|";
		}
		cout<<endl;
	}



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

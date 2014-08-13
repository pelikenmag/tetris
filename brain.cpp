#include <iostream>
using namespace std;
void draw_matrix(int *,int);
void turn_matrix(int *,int );

int main(){

	int i;
	int m2_size=2;
	int m3_size=3;
	int m2[]={	1,2,
						 	3,4	};
	int m3[9],m4[16];

	for (i=0;i<16;i++)
		m4[i]=i;

	//draw_matrix(m2,2);
	
	draw_matrix(m4,4);
	turn_matrix(m4,4);
	draw_matrix(m4,4);
	return 0;
}
//чтобы сделать рекурсию нужно передавать матрицу в функцию, прибавляя к указателю n+1
void turn_matrix(int *matrix,int n){

	int i=0,j=0,k,tmp,fel;
	
		fel=i*n+j;
		for (k=1;k<=4;k++){

			i=j;j=n-1-i;
			tmp=matrix[j+i*n];
			matrix[j+i*n]=matrix[fel];
			matrix[fel]=tmp;
			
		}





	

	
	

}

void draw_matrix(int matrix[],int size){

	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<matrix[i*size+j]<<"	";


		}
		cout<<endl;

	}
}
#include <iostream>
using namespace std;
void draw_matrix(int *,int);
void turn_matrix(int *,int );

int main(){

	int i,size=4,m[size*size];
    for (i=0;i<size*size;i++)
		m[i]=i;

	//draw_matrix(m2,2);

	draw_matrix(m,size);
	turn_matrix(m,size);
	cout<<endl;
	draw_matrix(m,size);
	return 0;
}

void turn_matrix(int *matrix,int n){

	int i=0,j=0,k,tmp,on=n;
    //matrix=matrix+n+1;n=n-2;//для теста
    for(;n>1;i=0,j=0){
        for(;j<n-1;j++){
            tmp=matrix[j*(on)+n-1-i];
            matrix[j*(on)+n-1-i]=matrix[i*(on)+j];
            matrix[i*(on)+j]=matrix[(n-1-j)*(on)+i];
            matrix[(n-1-j)*(on)+i]=matrix[(n-1-i)*(on)+n-1-j];
            matrix[(n-1-i)*(on)+n-1-j]=tmp;
        }


    cout<<n<<endl;
    matrix=matrix+on+1;n=n-2;
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

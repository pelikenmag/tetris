#include <iostream>
using namespace std;

const int IS_BORDER=1;
const int IS_BOTTOM=2;
const int IS_SMTH=4;

void draw_matrix(int *,int);
void turn_matrix(int *,int );
void merge(int *,int,int *,int,int,int);
int testme(){
	int xxx=IS_BORDER|IS_SMTH|IS_BOTTOM;
	return xxx;
}


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
     case 'w':
     	turn_matrix(shape1,2);
     	break;
    default:;

    }
    merge(main,0,shape1,2,x,y);
  }
  //merge(main,0,shape1,2,x,y);
	*/

  cout<<"::: "<<testme()<<endl;
	return 0;
}
void merge(int *main,int main_size, int *shape,int shape_size,int x,int y){
	int i=0,j=0;
	bool collision,bottom;
	int showme[200];

	//Оставляем

	/*for (i=0,collision=bottom=false;i<shape_size;i++){
		for(j=0;j<shape_size;j++){
			if (main[x+(i+y)*16+j]>0 && shape[i*shape_size+j]>0)
                collision=true;
            if (main[x+(y+i+1)*16+j]>0 && shape[i*shape_size+j]>0)
                bottom=true;
		}
	}
	//Оставляем
	if (bottom==true && collision==false){
      for (i=0;i<shape_size;i++)
        for(j=0;j<shape_size;j++)
          main[x+(i+y)*16+j]=shape[i*shape_size+j];
	}
  

    cout<<"collision: "<<collision<<" bottom: "<<bottom<<endl;*/
	//В функцию добавить определение линии
	//Выносим из функции все, что ниже
  for(i=0;i<20;i++){
  	for(j=0;j<10;j++){
  		showme[i*10+j]=main[i*16+j+3];
  	}
  }
  for (i=0;i<shape_size;i++){
        for(j=0;j<shape_size;j++){
          showme[(x-3)+(i+y)*10+j]=shape[i*shape_size+j];
        }
	}

  cout<<"-----------------------------"<<endl;
	for(i=0;i<20;i++){
		for(j=0;j<10;j++){
			cout<<showme[i*10+j]<<"|";
		}
		cout<<endl;
	}

}
//Ôóíêöèÿ ïîâîðîòà ìàòðèöû (âïðàâî)
//Âõîä: ìàòðèöà, ðàçìåð
void turn_matrix(int *matrix,int n){
  int i=0,j=0,k,tmp,on=n;

  for(;n>1;i=0,j=0){
    for(;j<n-1;j++){            //öèêë ïðîõîäà ïî ýëåìåíòàì âåðõíåé ñòðîêè ìàòðèöû
                                    //âçàèìîîáìåí çíà÷åíèÿìè 4-õ ýëåìåíòîâ
                                    //íà÷èíàÿ ñ [0,j]
      tmp=matrix[j*(on)+n-1-i];
      matrix[j*(on)+n-1-i]=matrix[i*(on)+j];
      matrix[i*(on)+j]=matrix[(n-1-j)*(on)+i];
      matrix[(n-1-j)*(on)+i]=matrix[(n-1-i)*(on)+n-1-j];
      matrix[(n-1-i)*(on)+n-1-j]=tmp;
    }
  matrix=matrix+on+1;n=n-2;//ïåðåõîä ê áîëåå ìåíüøåé ïîäìàòðèöå ðàçìåðà N-2
  }
}
//Ôóíêöèÿ âûâîäà ñîäåðæèìîãî ìàòðèöû â êîíñîëü
//Âõîä: ìàòðèöà, ðàçìåð
void draw_matrix(int matrix[],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<matrix[i*size+j]<<" ";
		}
		cout<<endl;
	}
}

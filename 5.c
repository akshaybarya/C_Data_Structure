#include<stdio.h>
#define SIZE 10

int arr[SIZE]={15,66,44,555,77,99,2,43,79,21};

void print_array();
void qsort(int,int);
void swap(int,int);
int partition(int,int,int);

void main()
{
	print_array();

	qsort(0,SIZE-1);

	print_array();
}

int partition(int min,int max,int pivot)
{
	int maxPoint=max+1;
	int minPoint=min;

	do{
		do{
			minPoint++;
		  }while(arr[minPoint] < pivot  && minPoint<SIZE-1);

		do{
			maxPoint--;
		  }while(arr[maxPoint] > pivot && maxPoint >= 0);

		if(minPoint < maxPoint){
			swap(minPoint,maxPoint);
			}

		else{
			swap(maxPoint,min);
			}
	  }while(minPoint < maxPoint);
		return maxPoint;
}

void qsort(int min,int max){
	int p;
	int pivot;

	if(max > min){

		pivot=arr[min];
		p=partition(min,max,pivot);

		qsort(min,p-1);
		qsort(p+1,max);
	}else{
			return;
		}

}

void swap(int pos1 , int pos2)
{
	int temp = arr[pos1];
	arr[pos1]= arr[pos2];
	arr[pos2]= temp;
}

void print_array()
{
	printf("\n****************************************\n");

	for(int i=0 ; i<SIZE ; i++){
		printf(" %d ",arr[i]);
	}

	printf("\n****************************************\n");
}



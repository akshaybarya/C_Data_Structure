//Using Quick  Sort
#include<stdio.h>
#define SIZE 10

int arr[SIZE] =  {99,44,77,88,22,66,33,11,55,10};

int partition(int , int ,int);
void qsort(int , int);
void swap(int,int);

void main()
{
	qsort(0,SIZE-1);

	printf("\nMin  Element : %d\n",arr[0]);
	printf("Max  Element : %d\n",arr[SIZE-1]);
}

int partition(int min , int max , int pivot)
{
	int maxpoint = max+1;
	int minpoint = min;

	do{
			do{
					minpoint++;
				}while(arr[minpoint]<pivot && minpoint<SIZE);

			do{
					maxpoint--;
				}while(arr[maxpoint]>pivot && maxpoint>-1);

			if(minpoint < maxpoint)
			{
				swap(minpoint,maxpoint);
			}else{
				swap(min,maxpoint);
			}

		}while(minpoint < maxpoint);
	return maxpoint;
}

swap(int pos1 , int pos2)
{
	int temp = arr[pos1];
	arr[pos1]=arr[pos2];
	arr[pos2]=temp;
}

qsort(int min , int max){
	int p,pivot ;

		if(min<max){
		pivot= arr[min];

		p=partition(min,max,pivot);
		qsort(min,p-1);
		qsort(p+1,max);
		}
}

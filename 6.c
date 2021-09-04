// Quick Sort
#include<stdio.h>
#define SIZE 10

int arr[SIZE]={15,66,44,555,77,99,2,43,79,21};

void print_array();
void swap(int , int);

void qsort(int , int);
int partition(int , int , int);

void main()
{
	print_array();

	qsort(0,SIZE-1);

	print_array();
}

int partition(int min , int max , int pivot)
{
	int maxindex = max+1;//max index pehle minus hoga fir 
	int minindex = min ;
	do{
			do{
					minindex++;
				}while(arr[minindex] < pivot && minindex<SIZE);
		
			do{
					maxindex--;				
				}while(arr[maxindex] > pivot && maxindex > -1);

			if(maxindex > minindex)
				{
					swap(maxindex , minindex);
				}else{
					swap(maxindex , min);
				}			
			
		}while(minindex < maxindex);
	return maxindex;
}

void qsort(int min , int max)
{
	int p , pivot;
	if(min < max)
		{
			pivot = arr[min] ;
			p=partition(min , max , pivot);

			qsort(min , p-1);
			qsort(p+1 , max);
		}
}

void swap(int pos1 , int pos2)
{
	int temp = arr[pos1];
	arr[pos1]=arr[pos2];
	arr[pos2]=temp;
}

void print_array()
{
	printf("\n****************************************\n");

	for(int i=0 ; i<SIZE ; i++){
		printf(" %d ",arr[i]);
	}

	printf("\n****************************************\n");
}



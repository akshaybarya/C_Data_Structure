#include<stdio.h>
#define SIZE 10

int arr[SIZE]={87,76,42,11,92,66,32,46,72,52};
int b[SIZE];

void print_array();
void msort(int,int);
void merge(int , int , int);

void main()
{
	print_array();

	msort(0,SIZE-1);

	print_array();
}

void merge(int min , int mid , int max)
{
	int i,minpoint,maxpoint;
    minpoint = min ;
	maxpoint = mid+1;

	for(i = min ; minpoint <= mid && maxpoint <= max ; i++){
			if(arr[minpoint] <= arr[maxpoint])
			{
				b[i] = arr[minpoint];
				minpoint++;
			}else{
				b[i] = arr[maxpoint];
				maxpoint++;
			}
		}

	while(minpoint <= mid)
		{
			b[i]=arr[minpoint];
			i++;
			minpoint++;
		}

	while(maxpoint <= max)
		{
			b[i]=arr[maxpoint];
			i++;
			maxpoint++;
		}

	for(i= min ; i<= max ; i++)
		{
			arr[i] = b[i] ;
		}
}

void msort(int min , int max)
{
	int mid;

	if(min < max)
		{
			mid=(min+max)/2;
			msort(min , mid);
			msort(mid+1,max);

			merge(min , mid , max);
		}
}

void print_array()
{
	printf("\n*********************************************************\n");

	for(int i=0 ; i<SIZE ; i++){
		printf(" %d  ",arr[i]);
		}

	printf("\n*********************************************************\n");
}





// BINARY SEARCH

#include<stdio.h>
#define SIZE 10

int arr[SIZE]={1,2,3,4,5,6,7,8,9,10};

void main()
{
	int n,mid,min=0,max=SIZE-1;
	int flag=1;
	printf("\nEnter Number : \n");
	scanf("%d",&n);

	for(int i = 0 ; i < SIZE ; i++)
	{	
		mid = (min+max)/2;
		if(n < arr[mid])
			{
				max=mid;
			}
		else if(n > arr[mid])
			{
				min=mid;
			}
		else if(n==arr[mid])
			{
				printf("\nElement found !\n");
				flag=0;
				break;
			}
	}
if(flag==1)
	{
		printf("Element Not Found inside array !");
	}
}






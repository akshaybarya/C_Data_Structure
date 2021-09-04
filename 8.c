// LINEAR SEARCH

#include<stdio.h>
#define SIZE 10

int arr[SIZE]={87,76,42,11,92,66,32,46,72,52};

void print_array();

void main()
{
	int n,flag=1;
	print_array();

	printf("\nEnter Number : \n");
	scanf("%d",&n);

	for(int i = 0 ; i < SIZE ; i++)
	{
		if(n==arr[i])
		{
			flag=0;
			printf("\nElement %d found at %d index\n",n,i);
			break;
		}
	}

	if(flag==1)
	{
		printf("\nWrong Element !\n");
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





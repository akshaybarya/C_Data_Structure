#include<stdio.h>
#define SIZE 10

void main()
{
    int i,num,position, Size=10;
    int arr[SIZE]={88,77,99,44,55,44,66,33,11,7};
    printf("Array before Sorting\n\n");
    for(int i=0 ; i<SIZE ; i++){
    printf("%d ,",arr[i]);
    }
    for( i=0 ; i<SIZE ; i++){
        num=arr[i];
        position=i;

        while(position>0 && num<arr[position-1])
        {
            arr[position]=arr[position-1];
            position--;
        }
        if(i!=position){
            arr[position]=num;
        }
    }
    printf("\nArray after Sorting\n\n");
    for(int i=0 ; i<SIZE ; i++){
    printf("%d ,",arr[i]);
    }
}

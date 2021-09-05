#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct DataItem
{
    int key;
    int value;
};
typedef struct DataItem dataitem;

dataitem *arr[SIZE];

int hashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int value)
{
    dataitem *item = (dataitem *)malloc(sizeof(dataitem));
    item->key = key;
    item->value = value;

    int index = hashCode(key);

    while (arr[index] != NULL)
    {
        index++;
        index = index % SIZE;
    }

    arr[index] = item;
}

void show()
{
    int x;
    printf("\nData : ");
    for (x = 0; x < 20; x++)
    {
        if (arr[x] != NULL)
        {
            printf("%d ", arr[x]->value);
        }
    }
    printf("\n");
}

void main()
{
    insert(56, 23); // 56%10 : 6
    insert(1, 3);   // 1%10 : 1
    insert(23, 43); // 23%10 : 3

    insert(62, 66);
    insert(99, 73);
    insert(79, 11);
    insert(89, 78);
    show();
}

#include<stdio.h.>
#include<stdlib.h>
#include<string.h>

struct Student{
 int roll;
 char name[50];
 float per;

 struct Student* next;
 struct Student* prev;
};

typedef struct Student node;

node* createNode();

void printMenu();
void insertAtStart();
void insertAtEnd();
void insertAtPosition();
void deleteAtStart();
void deleteAtEnd();
void deleteAtPosition();
void traversefromStart();
void traversefromEnd();
void swap(node *x,node *y);
void sort();

node* start;
node* end;
int listindex=-1;

void main()
{
	int choice;

	while(1)
	{
		printMenu();
		scanf("%d",&choice);
		if(choice==10){break;}
		else{
				switch(choice){
						case 1: insertAtStart();break;
						case 2: insertAtEnd(); break;
						case 3: insertAtPosition(); break;
						case 4: deleteAtStart(); break;
						case 5: deleteAtEnd(); break;
						case 6: deleteAtPosition();break;
						case 7: traversefromStart();break;
						case 8: traversefromEnd();break;
						case 9: sort();break;
						default: printf("\nWrong Choice !\n");
				}
		}
	}
	printf("\n ** thanks **\n");
}
void printMenu(){
    printf("\n1. Insert at start.");
	printf("\n2. Insert at end.");
	printf("\n3. Insert at position.");
	printf("\n4. Delete at start.");
	printf("\n5. Delete at end.");
	printf("\n6. Delete at position.");
	printf("\n7. Traverse From Start.");
	printf("\n8. Traverse From End.");
	printf("\n9. Sort.");
	printf("\n10. Exit.");
	printf("\n>> ");}


node* createNode()
{
    node* p=(node*)malloc(sizeof(node));

    int roll;
    char name[50];
    float per;
    printf("\nRoll : ");
	scanf("%d",&roll);
	printf("Name : ");
	scanf("%s",name);
	printf("Marks : ");
	scanf("%f",&per);

	p->roll=roll;
	strcpy(p->name,name);
    p->per=per;

    p->next=NULL;
    p->prev=NULL;

    return p;
}

void insertAtStart()
{
    node* newnode=createNode();
    if(start==NULL){
        start=end=newnode;
    }else{
      newnode->next=start;
      start->prev=newnode;
      start=newnode;
    }
    printf("\nNode Inserted !\n");
    listindex++;
}
void insertAtEnd()
{
    node* newnode=createNode();
    if(start==NULL){
        start=end=newnode;
    }else{
     newnode->prev=end;
     end->next=newnode;
     end=newnode;
    }
   printf("\nNode Inserted !\n");
    listindex++;
}
void insertAtPosition()
{
    if(listindex==-1){insertAtStart();}
    else{
        int position ;
        printf("\nEnter Position :\n");
        scanf("%d",&position);

        if(position>listindex+2){printf("\nPosition Not feasible !\n");}
        else if(position==listindex+2){insertAtEnd();}
        else{
            int x;
            node* p=start;
            while(x<position){
                p=p->next;
            }
            node* newnode = createNode();
            newnode->next=p->next;
            p->next=newnode;
            newnode->next->prev=newnode;
            newnode->prev=p;
            listindex++;
            printf("\nNode Inserted !\n");
        }
    }
}

void deleteAtStart()
{
    if(start==NULL){printf("\nList is Empty !\n");}
    else {
        node* p=start;
        if(p->next==NULL){
            start=end=NULL;
        }else{
         p->next->prev=NULL;
         start=p->next;
        }
        printf("\nElement Deleted !\n");
        free(p);
        listindex--;
    }
}

void deleteAtEnd()
{
  if(start==NULL){printf("\nList is Empty !\n");}
    else {
        node* p=start;
        if(start->next==NULL){start=end=NULL;free(p);}
        else{while(p->next!=end){
            p=p->next;
        }
        end=p;
        p->next=NULL;
        free(p->next);
        }
        printf("\nElement Deleted !\n");

        listindex--;
    }
}
void deleteAtPosition()
{
    if(start==NULL){printf("\nList is Empty !\n");}
    else{
        int position ;
        printf("\nEnter Position :\n");
        scanf("%d",&position);

        if(position>listindex+1){printf("\nPosition Not feasible !\n");}
        else if(position==1){deleteAtStart();}
        else if(position==listindex+1){deleteAtEnd();}
        else{
                int x;
                node* p=start;
                while(x<position){
                    p=p->next;
                }
            node* q=p->next;
            q->next->prev=p;
            p->next=q->next;
            free(q);
           printf("\nElement Deleted !\n");
           listindex--;
        }
    }
}
void traversefromStart()
{
    if(start==NULL){printf("\nList Empty !\n");}
    else{
        node* p=start;
        do{
            printf("\nRoll no : %d\n",p->roll);
            printf("Name :%s\n",p->name);
            printf("Percentage :%f\n",p->per);
            p=p->next;
        }while(p!=NULL);
    }
}

void traversefromEnd()
{
    if(start==NULL){printf("\nList Empty !\n");}
    else{
        node* p=end;
        do{
            printf("\nRoll no : %d\n",p->roll);
            printf("Name :%s\n",p->name);
            printf("Percentage :%f\n",p->per);
            p=p->prev;
        }while(p!=NULL);
    }
}

void swap(node *x,node *y){
int roll;
char name[50];
float per;

roll=x->roll;
strcpy(name,x->name);
per=x->per;

x->roll=y->roll;
strcpy(x->name,y->name);
x->per=y->per;

y->roll=roll;
strcpy(y->name,name);
y->per=per;
}
void sort()
{
    if(start==NULL){printf("\nList Empty !\n");}
    else if(start->next==NULL){printf("\nNo need of Sorting !\n");}else{
    node* p=start;
    do{
        node* q=p->next;
    do{
       if(p->per>q->per){
            swap(p,q);
         q=q->next;
        }
    }while(q!=NULL);
        p=p->next;
    }while(p->next!=NULL);
    printf("\nSorting Done !\n");
    }
}

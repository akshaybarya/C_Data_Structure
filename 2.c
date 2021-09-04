// Circular Single Linked List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
 int roll;
 char name[50];
 float per;

 struct Student *next;
};
typedef struct Student node;


void insertAtStart();
void insertAtEnd();
void insertAtPosition();
void deleteFromStart();
void deleteFromEnd();
void deleteFromPosition();
void traverse();
void Sort();
void Exchange(node* p,node* q);

node* createnode();
int listindex=-1;
node* front=NULL;
node* end=NULL;
void main()
{
    int choice;
    while(1){
        printf("\n1)Insert at Start\n");
        printf("2)Insert at End\n");
        printf("3)Insert at Position\n");
        printf("4)Delete from Start\n");
        printf("5)Delete from End\n");
        printf("6)Delete from Position\n");
        printf("7)Traverse\n");
        printf("8)Sort\n");
        printf("9)Exit\n");
        scanf("%d",&choice);
        if(choice==9){printf("*********");break;}
        else{
            switch(choice){
            case 1: insertAtStart();break;
            case 2: insertAtEnd();break;
            case 3: insertAtPosition();break;
            case 4: deleteFromStart();break;
            case 5: deleteFromEnd();break;
            case 6: deleteFromPosition();break;
            case 7: traverse();break;
            case 8: Sort();break;
            default:printf("\nWrong Choice\n");
            }
        }
    }
}

node* createnode()
{
    node *p=(node *)malloc(sizeof(node));

    int roll;
    char name[50];
    float per;
    printf("\nEnter rollno : ");
    scanf("%d",&roll);
    printf("\nEnter name : ");
    scanf("%s",name);
    printf("\nEnter Percentage : ");
    scanf("%f",&per);

    p->roll=roll;
    strcpy(p->name,name);
    p->per=per;
    p->next=NULL;

    return p;
}
insertAtEnd(){
   node* newnode=createnode();
   if(front==NULL){
    front=end=newnode;
   }else{
   end->next=newnode;
   end=newnode;
   end->next=front;
   }
   printf("\n Node is Inserted\n");
   listindex++;
}

insertAtStart(){
    node* newnode = createnode();
if(front==NULL){
   front=end=newnode;
}
else{
    newnode->next=front;
    front = newnode;
    end->next=newnode;
}
 printf("\n Node is Inserted\n");
 listindex++;
}

deleteFromStart(){
  if(front==NULL){
    printf("\nList is Empty !\n");
  }
  else{
      node* p = front;
        if(front==end){
    front=end=NULL;
  }else{
    front=front->next;
    end->next=front;
  }
  free(p);
  printf("\nNode Deleted\n");
  listindex--;
  }
}

void deleteFromEnd(){
  if(front==NULL){printf("\nList Empty !\n");}
  else{
        node* p = front;
    //node* q=end;
        if(p->next==NULL){
           front=end=NULL;
           free(p);
        }else{
    while(p->next!=end){
        p=p->next;
    };
    end=p;
    free(p->next);
    p->next=front;

        }
  printf("\nNode Deleted\n");
  listindex--;
  }
}

traverse(){
if(front==NULL){
    printf("\nList is Empty !\n\n");
}else{
    node* p=front;
do{
    printf("\nRoll No : %d\n",p->roll);
    printf("Name : %s\n",p->name);
    printf("Percentage : %f\n",p->per);
    p=p->next;
}while(p!=front);
}
}
insertAtPosition(){
    if(front==NULL){insertAtStart();}else{
    int position,x=1;
printf("\nEnter Position :");
scanf("%d",&position);

 if(position<1 || position>listindex+2){printf("\nPosition is not feasible\n");}
 else if(position==1){insertAtStart();}
 else if(position==listindex+2){insertAtEnd();}
else{
    node* p=front;
    while(x!=position-1){
        p=p->next;
        x++;
    }
    node* newnode = createnode();
    newnode->next=p->next;
    p->next=newnode;
    printf("\nnew Node Inserted\n");
    listindex++;
}
}
}

void deleteFromPosition(){
if(front==NULL){printf("\nList is Empty !\n");}
else{
     int position,x=1;
printf("\nEnter Position :");
scanf("%d",&position);

 if(position<1 || position>listindex+1){printf("\nPosition is not feasible\n");}
 else if(position==1){deleteFromStart();}
 else if(position==listindex+1){deleteFromEnd();}
else{
       node* p=front;
    while(x!=position-1){
        p=p->next;
        x++;
    }
    p->next=p->next->next;
    free(p);
    printf("\nNode Deleted !\n");
    }
}
}

void Sort(){
if(listindex==-1){printf("\nList Empty !\n");}
else if(listindex==0){printf("\nNo need of Sorting !\n");}
else{

       node* p=front;
    do{
        node* q=p->next;
        do{
        if(p->roll>q->roll){
            Exchange(p,q);
        }
        q=q->next;
        }while(q!=front);
        p=p->next;
    }while(p->next!=front);
    printf("\nSorting Done !\n");
}
}

void Exchange(node* p,node* q){
    int roll;
    float per;
    char name[50];
            roll=p->roll;
            strcpy(name,p->name);
            per=p->per;

            p->roll=q->roll;
            strcpy(p->name,q->name);
            p->per=q->per;

            q->roll=roll;
            strcpy(q->name,name);
            q->per=per;
}

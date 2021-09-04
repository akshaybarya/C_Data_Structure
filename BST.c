//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
struct Student
{
	int data;
		struct Student *left;
 		struct Student *right;
};

typedef struct Student node;

node* rootNode = NULL;

node* createNode();
void print_menu();
void Insert();
void inorder();
void postorder();
void preorder();
node* delete(node*, int);
node* minValue(node*);

node* createNode()
{
	int data;
	node* p = (node*)malloc(sizeof (node));

	printf("\nEnter Number :");
	scanf("%d",&data);

	p->data=data;

	p->left=NULL;
	p->right=NULL;

	return p;
}

void main()
{
	while(1){
		int choice;
		print_menu();
		scanf("%d",&choice);

		if(choice==6){break;}
		else{
			switch(choice){
					case 1: Insert(); break;
					case 2: printf("Number : ");
							            scanf("%d",&num);
							            root = deleteNode(root,num); break;
					case 3: inorder(rootNode);break;
					case 4: preorder(rootNode);break;
					case 5: postorder(rootNode);break;
				}
		}
	}
}

void print_menu()
{
	printf("\n1) Insert Element\n");
	printf("2) Delete Element\n");
	printf("3) inorder \n");
	printf("4) preorder \n");
	printf("5) postorder \n");
	printf("6) Exit\n");
}

void Insert()
{
	node* current = rootNode;
	node* parent = current;
	node* newNode = createNode();

	if(rootNode==NULL){
			rootNode = newNode;
		}
		else{
				parent = current;
				while(1){
					if(newNode->data > current->data){
								current = current->right;

								if(current == NULL){
									parent->right=newNode;
									break;
								}
					}else{
								current = current->left;

								if(current == NULL){
									parent->left=newNode;
									break;
								}
							}
				}
		}

}

void inorder(node* Node)
{
	if(Node!=NULL)
		{
			inorder(Node->left);
			printf("%d ",Node->data);
			inorder(Node->right);
		}
}

void postorder(node* Node)
{
	if(Node!=NULL)
		{
			inorder(Node->left);

			inorder(Node->right);
			printf("%d ",Node->data);
		}
}


void preorder(node* Node)
{
	if(Node!=NULL)
		{
            printf("%d ",Node->data);
            inorder(Node->left);
            inorder(Node->right);
		}
}

void preorder(node* Node)
{
	if(Node!=NULL)
		{
            inorder(Node->left);
            inorder(Node->right);
            printf("%d ",Node->data);

		}
}

node* delete(node* Node , int data)
{
	if(Node==null){return Node;}
	
	if(data < Node->data){
		Node = delete(Node->left , data);return Node;
	}

	else if(data > Node->data){
		Node = delete(Node->right , data);return Node;
	}

	else{
//		Case of one child  or no child
		if(Node->left == NULL){
			int temp = Node->right;
			free(Node);
			return temp ; 
		}
		else if(Node->right == NULL){
			int temp = Node->left ;
			free(Node);
			return temp;
		}

		else{
//			Case of two Child

			node* temp  = minValue(Node->right);

			Node -> data = temp->data;

			Node->right = delete(Node->right , temp->data);
			
			return Node;
		}

	}
}

node* minValue(node* Node)
{
	node* current = Node;
	
	while(current->left != NULL){
			current = current->left;
		}
	return current;
}

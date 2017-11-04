
/*
Author:- Yashovardhan Siramdas & Nipun Bharti

Programming and Data Strucutres Assignment (Dr. V Masilamani)

B-Tree(3,3)

B-Tree Properties:-

(i) Root is either a leaf or has atleast 2 children
(ii) All the interior nodes and root node should have atleast 2 children and at max 3 children
(iii) Each Leaf node should have atleast 2 keys and at max 3 keys
(iv) Length of all paths from root to leaves are the same
(v) Each Node will be in the form l1,k1,l2,k2,l3,k3,k4,pt,size
(vi) All the keys in l1 subtree are less than k1
(vii) All the keys in l2 subtree are more than or equal to k1 and less than k2
(viii) All the keys in l3 subtree are more than or equal to k2

Multi Purpose Struct:-

Type 1:- Node
Type 2:-Bucket
If type=1 k1,k2 are keys for Node
If type=2 k1,k2,k3 are data inside bucket and k4 acts as buffer
size indicates number of occupied keys in Node or Bucket
pt links to parent of Node or Bucket

*/

#include <stdio.h>
#include <stdlib.h>

//Node Structure
struct node
{
	int type;
	struct node *l1;
	int k1;
	struct node *l2;
	int k2;
	struct node *l3;
	int k3;
	int k4;
	struct node *pt;
	int size;	

};


struct node *root = NULL;


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert()
{
	int x;
	printf("Enter Integer\n");
	scanf("%d",&x);
	if(root==NULL)
	{
		struct node *init=(struct node *)malloc(sizeof(struct node));
		root=init;
		init->type=2;
		init->k1=x;
		init->size=init->size+1;	
	}
	else
	{
		if(root->type==2)
		{
			if(root->size==1)
			{
				root->k2=x;
				root->size=root->size+1;
				if(root->k1 > root->k2)
					swap(&(root->k1),&(root->k2));	
			}
			else if(root->size==2)
			{
				root->k3=x;
				root->size=root->size+1;
				if(root->k3<=root->k1)
				{
					swap(&(root->k1),&(root->k3));
					swap(&(root->k3),&(root->k2));
				}
				else if(root->k3>root->k1 && root->k3<=root->k2)
				{
					swap(&(root->k3),&(root->k2));	
				}

			}
			else if(root->size==3)
			{
				root->k4=x;
				if(root->k4<=root->k1)
				{
					swap(&(root->k1),&(root->k4));
					swap(&(root->k4),&(root->k3));
					swap(&(root->k2),&(root->k3));
				}
				else if(root->k4>root->k1 && root->k4<=root->k2)
				{
					swap(&(root->k2),&(root->k4));
					swap(&(root->k3),&(root->k4));
				}
				else if(root->k4>root->k2 && root->k4<=root->k3)
				{
					swap(&(root->k3),&(root->k4));
				}
				struct node *sibling=(struct node *)malloc(sizeof(struct node));
				struct node *parent=(struct node *)malloc(sizeof(struct node));
				sibling->type=2;
				parent->type=1;
				sibling->k1=root->k3;
				sibling->k2=root->k4;
				root->k3=root->k4=0;
				root->size=sibling->size=2;
				root->pt=sibling->pt=parent;
				parent->l1=root;
				parent->l2=sibling;
				root=parent;


			}
		}
		else
		{}
	}
	printf("%d is inserted into B-Tree\n",x);
	

}

void display()
{
	
}

//Driver Function
int main()
{
	int i;

	int ch=0;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Print\n4.Exit\n");  //Menu
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				//delete();
				break;
			}
			case 3:
			{
				//display();
				break;
			}
			case 4:
			{
				exit(0);
				break;
			}
			default:
			{
				printf("Wrong choice :( \n");
			}
		}
	}
	return 0;
}




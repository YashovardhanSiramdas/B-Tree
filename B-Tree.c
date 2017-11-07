
/*
Author:- Yashovardhan Siramdas

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
				parent->k1=sibling->k1;
				parent->size=1;
				root=parent;

			}
		}
		else
		{
			struct node *t=root;
			while(t->type!=2)
			{
				
				if(t->size==1)
				{
					if(x<t->k1)
					{
						t=t->l1;
					}
					else
					{
						t=t->l2;
					}
				}
				else if(t->size==2)
				{
					if(x<t->k1)
					{
						t=t->l1;
					}
					else if(x>=t->k1 && x<t->k2)
					{
						t=t->l2;
					}
					else if(x>=t->k2)
					{
						t=t->l3;
					}
					
				}
				
			}

			if(t->size==2)
			{
				t->k3=x;
				t->size=t->size +1;
				if(t->k3 <= t->k1)
				{
					swap(&(t->k1),&(t->k3));
					swap(&(t->k2),&(t->k3));
				}
				else if(t->k3 > t->k1 && t->k3<=t->k2)
				{
					swap(&(t->k2),&(t->k3));
				}
			}
			else if(t->size==3)
			{
				t->k4=x;
				if(t->k4<=t->k1)
				{
					swap(&(t->k1),&(t->k4));
					swap(&(t->k4),&(t->k3));
					swap(&(t->k2),&(t->k3));
				}
				else if(t->k4>t->k1 && t->k4<=t->k2)
				{
					swap(&(t->k2),&(t->k4));
					swap(&(t->k3),&(t->k4));
				}
				else if(t->k4>t->k2 && t->k4<=t->k3)
				{
					swap(&(t->k3),&(t->k4));
				}
				if(t->pt->size==1)
				{
					if(x<t->pt>-k1)
					{
						struct node *bucket=(struct node *)malloc(sizeof(struct node));
						bucket->type=2;
						bucket->k1=t->k3;
						bucket->k2=t->k4;
						t->k3=t->k4=0;
						bucket->pt=t->pt;
						bucket->size=t->size=2;
						t->pt->l3=t->pt->l2;
						t->pt->l2=bucket;


					}
					else
					{
						struct node *bucket=(struct node *)malloc(sizeof(struct node));
						bucket->type=2;
						bucket->k1=t->k3;
						bucket->k2=t->k4;
						t->k3=t->k4=0;
						bucket->pt=t->pt;
						bucket->size=t->size=2;
						t->pt->l3=bucket;
					}
					t->pt->size=2;
					t->pt->k1=t->l2->k1;
					t->pt->k2=t->l3->k1;

				}
				else if(t->pt->size==2)
				{

				}
				
			}



		}
	}
	printf("%d is inserted into B-Tree\n",x);
	

}

void display()
{
	
}

int main()
{
	int i;

	int ch=0;
	while(1)
	{
		printf("1.Insert\n2.Display\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				insert();
			}
			break;

			case 2:
			{
				//display();
			}
			break;

			case 3:
			{
				return 0;
			}
			break;

			default:
			{
				printf("Wrong choice\n");
			}
		}
	}
	return 0;
}




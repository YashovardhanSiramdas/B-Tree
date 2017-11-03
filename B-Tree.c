/*
Author:- Yashovardhan Siramdas & Nipun Bharti

Programming and Data Strucutres Assignment (Dr. V Masilamani)

B-Tree(3,3)

Insertion Algorithm:-

(i) Root is either a leaf or has atleast 2 children
(ii) All the interior nodes and root node should have atleast 2 children and at max 3 children
(iii) Each Leaf node should have atleast 2 keys and at max 3 keys
(iv) Length of all paths from root to leaves are the same
(v) Each Node will be in the form l1,k1,l2,k2,l3
(vi) All the keys in l1 subtree are less than k1
(vii) All the keys in l2 subtree are more than or equal to k1 and less than k2
(viii) All the keys in l3 subtree are more than or equal to k2

*/

#include <stdio.h>
#include <stdlib.h>

//Node Structure
struct node
{
	void *l1;
	int k1;
	void *l2;
	int k2;
	void *l3;
	void *pt;

};

/*
Bucket Structure:-

1st integer
2nd integer
3rd integer
Buffer integer
Bucket Size
*/


struct node *root = NULL;
int init_b[5],bucket[5];
int Bucket[100][5];
int bcntr=0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void setBucket(int bucket[])
{
	int i;
	for(i=0;i<4;i++)
		bucket[i]=999;
	bucket[4]=0;
}


void insert()
{
	int x;
	printf("Enter Integer\n");
	scanf("%d",&x);
	if(root==NULL)
	{
		init_b[init_b[4]]=x;
		init_b[4]++;
		quickSort(init_b,0,3);
		if(init_b[4]==4)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			root=temp;
			//int bucket[5];
			setBucket(bucket);
			bucket[0]=init_b[2];
			bucket[1]=init_b[3];
			bucket[4]=2;
			init_b[2]=init_b[3]=999;
			init_b[4]=2;
			temp->l1=init_b;
			temp->l2=bucket;
			temp->l3=NULL;
			temp->k1=bucket[0];
			temp->pt=NULL;

		}
	}
	else
	{

	}
	printf("%d is inserted into B-Tree\n",x);
	

}

void display()
{
	int i;
	if(root==NULL)
	{
		printf("b1\n");
		for(i=0;i<init_b[4];i++)
			printf("%d\n",init_b[i]);
	}
	else
	{
		printf("b1\n");
		int *x=(int *)root->l1;
		for(i=0;i<*(x+4);i++)
			printf("%d\n",*(x+i));
		printf("b2\n");
		x=(int *)root->l2;
		//printf("test %d\n",*(x+4));
		for(i=0;i<*(x + 4);i++)
			printf("%d\n",*(x+ i));	
	}
}

//Driver Function
int main()
{
	int i;
	setBucket(Bucket[0][5]);
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
				display();
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




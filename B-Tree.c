/*
Author:- Yashovardhan Siramdas & Nipun Bharti

<<<<<<< HEAD
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
=======
PDS Assignment

#include <stdio.h>
#include <stdlib.h>

//Basic Structure
struct node{
	struct node *link1;
	int key1;
	struct node *link2;
	int key2;
	struct node *link3;
};

struct node *head = NULL;

//Function Definitions
void insert();
void delete();
void display();

//Driver Function
int main()
{
	int ch=0;
	while(1){
		printf("1.Insert\n2.Delete\n3.Print\n4.Exit\n");  //Menu
		scanf("%d",&ch);
		switch(ch){
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				delete();
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


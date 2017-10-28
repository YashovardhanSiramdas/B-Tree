/*
Author:- Yashovardhan Siramdas & Nipun Bharti

PDS Assignment
*/

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
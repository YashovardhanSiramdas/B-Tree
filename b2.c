#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int flag;
    int size;
    int arr[4];
    int x,y,z;
    struct node* p1;
    struct node* p2;
    struct node* p3;
    struct node* p4;
    int value;
    struct node *a1;
    struct node *a2;
    };
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n; i++)
   {
    for (j = 0; j < n-i-1; j++)
    {
           if (arr[j] > arr[j+1])
           {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
}
   }
}
struct node* bucketinsert(struct node* hptr,int x)
{
    hptr->arr[hptr->size]=x;
    hptr->size+=1;
    bubbleSort(hptr->arr,hptr->size);
    return hptr;
}
struct node* nodesplit(struct node* hptr,struct node* hptr1,int c)
{
    if(c==1)
    {
        if(hptr->y==-1)
        {
            hptr->y=hptr->x;
            hptr->p3=hptr->p2;
            hptr->x=hptr1->value;
            hptr->p2=hptr1->a2;
            hptr->p1=hptr1->a1;
            return hptr;
        }
        else
        {
            hptr->z=hptr->y;
            hptr->p4=hptr->p3;
            hptr->y=hptr->x;
            hptr->p3=hptr->p2;
             hptr->x=hptr1->value;
            hptr->p2=hptr1->a2;
            hptr->p1=hptr1->a1;
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp2=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp3=(struct node*)(malloc(sizeof(struct node)));
            temp1->p1=NULL;
            temp1->p2=NULL;
            temp1->p3=NULL;
            temp1->x=-1;
            temp1->y=-1;
            temp1->z=-1;
            temp3->x=-1;
            temp3->y=-1;
            temp3->z=-1;
            temp1->p4=NULL;
            temp3->p1=NULL;
            temp3->p2=NULL;
            temp3->p3=NULL;
            temp3->p4=NULL;

           temp1->flag=2;
           temp3->flag=2;
             temp1->x=hptr->x;
                temp1->p1=hptr->p1;
                temp1->p2=hptr->p2;
                temp3->x=hptr->z;
                temp3->p1=hptr->p3;
                temp3->p2=hptr->p4;
            temp2->flag=3;
            temp2->a1=temp1;
            temp2->a2=temp3;
            temp2->value=hptr->y;
            return temp2;
          }
    }
    else if(c==2)
    {
      if(hptr->y==-1)
        {
            hptr->y=hptr1->value;
            hptr->p2=hptr1->a1;
            hptr->p3=hptr1->a2;
            return hptr;
        }
        else
        {
            hptr->z=hptr->y;
            hptr->p4=hptr->p3;
            hptr->y=hptr1->value;
            hptr->p2=hptr1->a1;
            hptr->p3=hptr1->a2;
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp2=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp3=(struct node*)(malloc(sizeof(struct node)));
             temp1->x=-1;
            temp1->y=-1;
            temp1->z=-1;
            temp3->x=-1;
            temp3->y=-1;
            temp3->z=-1;
            temp1->p1=NULL;
            temp1->p2=NULL;
            temp1->p3=NULL;
            temp1->p4=NULL;
            temp3->p1=NULL;
            temp3->p2=NULL;
            temp3->p3=NULL;
            temp3->p4=NULL;
           temp1->flag=2;
           temp3->flag=2;
             temp1->x=hptr->x;
                temp1->p1=hptr->p1;
                temp1->p2=hptr->p2;
                temp3->x=hptr->z;
                temp3->p1=hptr->p3;
                temp3->p2=hptr->p4;
            temp2->flag=3;
            temp2->a1=temp1;
            temp2->a2=temp3;
            temp2->value=hptr->y;
            return temp2;
          }
    }
    else if(c==3)
    {



            hptr->z=hptr1->value;
            hptr->p3=hptr1->a1;
            hptr->p4=hptr1->a2;
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp2=(struct node*)(malloc(sizeof(struct node)));
            struct node* temp3=(struct node*)(malloc(sizeof(struct node)));
             temp1->x=-1;
            temp1->y=-1;
            temp1->z=-1;
            temp3->x=-1;
            temp3->y=-1;
            temp3->z=-1;
            temp1->p1=NULL;
            temp1->p2=NULL;
            temp1->p3=NULL;
            temp1->p4=NULL;
            temp3->p1=NULL;
            temp3->p2=NULL;
            temp3->p3=NULL;
            temp3->p4=NULL;
           temp1->flag=2;
           temp3->flag=2;
             temp1->x=hptr->x;
                temp1->p1=hptr->p1;
                temp1->p2=hptr->p2;
                temp3->x=hptr->z;
                temp3->p1=hptr->p3;
                temp3->p2=hptr->p4;
            temp2->flag=3;
            temp2->a1=temp1;
            temp2->a2=temp3;
            temp2->value=hptr->y;
            return temp2;

    }
    return hptr;
}
struct node* insert(struct node* hptr,int x)
{
	int choice;
    if(hptr==NULL)
    {
        struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
        temp1->flag=1;
        temp1->size=0;
        hptr=temp1;
         hptr=bucketinsert(hptr,x);
         hptr->p1 = hptr->p2 = hptr->p3 = NULL;
        return hptr;
    }
    if(hptr->flag==2)
    {
        if(x<hptr->x)
        {
            hptr->p1=insert(hptr->p1,x);
            choice=1;
         }
        else if(x>=hptr->x&&hptr->y==-1)
        {  	
        	hptr->p2=insert(hptr->p2,x);
        	choice=2;
        	
         }
        else if(x>=hptr->x&&x<hptr->y)
        {
            hptr->p2=insert(hptr->p2,x);
            choice=2;
         }
        else
        {
            hptr->p3=insert(hptr->p3,x);
            choice=3;
         }


    }
    else
    {
        if(hptr->size<=2)
        {
            hptr=bucketinsert(hptr,x);
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            temp1->flag=4;
            temp1->value=hptr->arr[0];
            temp1->a1=hptr;
            return temp1;
        }
        else
        {
            hptr=bucketinsert(hptr,x);
            struct node* temp;
            temp=(struct node*)(malloc(sizeof(struct node)));
            temp->flag=1;
            temp->arr[0]=hptr->arr[2];
            temp->arr[1]=hptr->arr[3];
            temp->size=2;
            hptr->size=2;
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            temp1->flag=3;
            temp1->value=temp->arr[0];
            temp1->a1=hptr;
            temp1->a2=temp;
            return temp1;
        }
    }
 
         if(choice==1)
         {
		 
        if((hptr->p1)->flag==3)
        {
           hptr=nodesplit(hptr,hptr->p1,1);
        }
         else if((hptr->p1)->flag==4)
        {
           hptr->p1=(hptr->p1)->a1;

        }
    }
    if(choice==2)
    {
	
          if((hptr->p2)->flag==3)
        {
           hptr=nodesplit(hptr,hptr->p2,2);
        }
        else if((hptr->p2)->flag==4)
        {
        
           if(hptr->x>(hptr->p2)->value)
           {
               hptr->x=(hptr->p2)->value;
           }
             hptr->p2=(hptr->p2)->a1;

        }
    }
        if(choice==3)
        {
		
          if((hptr->p3)->flag==3)
        {
           hptr=nodesplit(hptr,hptr->p3,3);
        }
        else if((hptr->p3)->flag==4)
        {
             if(hptr->y>(hptr->p3)->value)
           {
               hptr->y=(hptr->p3)->value;
           }
             hptr->p3=(hptr->p3)->a1;
        }
    }


    
    return hptr;

}
void printtree(struct node* hptr)
{
    if(hptr->flag!=1)
    {
        if(hptr->p1!=NULL)
       printtree(hptr->p1);
        if(hptr->p2!=NULL)
       printtree(hptr->p2);
        if(hptr->p3!=NULL)
       printtree(hptr->p3);
    }
    else
    {
        for(int i=0;i<hptr->size;i++)
        {
            printf("%d ",hptr->arr[i]);
        }
        printf("\n");

    }
}
int main()
{
    struct node* hptr;
    hptr=NULL;
    int h;
    FILE* file = fopen ("rand.txt", "r");
  int input[40],input_size=0;
  while (!feof (file))
    {  
      fscanf (file, "%d", &input[input_size]);  
      input_size++;    
    }
  fclose (file);
  int inpc=0;
	for (int i = 1; i <= 40; i++)
	{
		h=input[inpc];
        inpc++;
		hptr = insert(hptr, h);
	   
	    if (hptr->flag == 4)
	    	hptr = hptr->a1;
	    else if (hptr->flag == 3)
	    {
	    	struct node *temp = (struct node*)malloc(sizeof(struct node));
	    	temp->flag = 2;
	    	temp->p1 = hptr->a1;
	    	temp->p2 = hptr->a2;
	    	temp->p3 = NULL;
	    	temp->p4 = NULL;
	    	temp->x = hptr->value;
	    	temp->y=-1;
	    	hptr=temp;
		}
		
	     
	    
	}
    printtree(hptr);
    return 0;
}
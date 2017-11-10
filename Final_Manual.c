#include <stdio.h>
#include <stdlib.h>

struct node
{
    int type;
    int size;
    int bucket[4];
    int x,y,z;
    struct node* p1;
    struct node* p2;
    struct node* p3;
    struct node* p4;
    int value;
    struct node *a1;
    struct node *a2;
};

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int low, int high)
{
    int pivot = a[high];  
    int i = (low - 1); 
    

    for (int j = low; j <= high- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;  
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
 
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

struct node* bucketInsert(struct node* root,int key)
{
    root->bucket[root->size]=key;
    root->size=root->size+1;
    quickSort(root->bucket,0,(root->size)-1);
    return root;
}

struct node* nodeSplit(struct node* root,struct node* root1,int position)
{
    if(position==1)
    {
        if(root->y==-1)
        {
            root->y=root->x;
            root->p3=root->p2;
            root->x=root1->value;
            root->p2=root1->a2;
            root->p1=root1->a1;
            return root;
        }
        else
        {
            root->z=root->y;
            root->p4=root->p3;
            root->y=root->x;
            root->p3=root->p2;
            root->x=root1->value;
            root->p2=root1->a2;
            root->p1=root1->a1;

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
            temp1->type=2;
            temp3->type=2;

            temp1->x=root->x;
            temp1->p1=root->p1;
            temp1->p2=root->p2;
            temp3->x=root->z;
            temp3->p1=root->p3;
            temp3->p2=root->p4;
            temp2->type=3;
            temp2->a1=temp1;
            temp2->a2=temp3;
            temp2->value=root->y;
            return temp2;
        }
    }
    else if(position==2)
    {
      if(root->y==-1)
        {
            root->y=root1->value;
            root->p2=root1->a1;
            root->p3=root1->a2;
            return root;
        }
        else
        {
            root->z=root->y;
            root->p4=root->p3;
            root->y=root1->value;
            root->p2=root1->a1;
            root->p3=root1->a2;

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
            temp1->type=2;
            temp3->type=2;

            temp1->x=root->x;
            temp1->p1=root->p1;
            temp1->p2=root->p2;
            temp3->x=root->z;
            temp3->p1=root->p3;
            temp3->p2=root->p4;
            temp2->type=3;
            temp2->a1=temp1;
            temp2->a2=temp3;
            temp2->value=root->y;
            return temp2;
        }
    }
    else if(position==3)
    {
        root->z=root1->value;
        root->p3=root1->a1;
        root->p4=root1->a2;

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
        temp1->type=2;
        temp3->type=2;

        temp1->x=root->x;
        temp1->p1=root->p1;
        temp1->p2=root->p2;
        temp3->x=root->z;
        temp3->p1=root->p3;
        temp3->p2=root->p4;
        temp2->type=3;
        temp2->a1=temp1;
        temp2->a2=temp3;
        temp2->value=root->y;
        return temp2;

    }
    return root;
}
struct node* insert(struct node* root,int key)
{
    int position;
    if(root==NULL)
    {
        struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
        temp1->type=1;
        temp1->size=0;
        root=temp1;
        root=bucketInsert(root,key);
        root->p1 = root->p2 = root->p3 = NULL;
        return root;
    }
    if(root->type==2)
    {
        if(key<root->x)
        {
            root->p1=insert(root->p1,key);
            position=1;
        }
        else if(key>=root->x && root->y==-1)
        {   
            root->p2=insert(root->p2,key);
            position=2;
            
        }
        else if(key>=root->x && key<root->y)
        {
            root->p2=insert(root->p2,key);
            position=2;
        }
        else
        {
            root->p3=insert(root->p3,key);
            position=3;
        }


    }
    else
    {
        if(root->size<=2)
        {
            root=bucketInsert(root,key);
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            temp1->type=4;
            temp1->value=root->bucket[0];
            temp1->a1=root;
            return temp1;
        }
        else
        {
            root=bucketInsert(root,key);
            struct node* temp;
            temp=(struct node*)(malloc(sizeof(struct node)));
            temp->type=1;
            temp->bucket[0]=root->bucket[2];
            temp->bucket[1]=root->bucket[3];
            temp->size=2;
            root->size=2;
            struct node* temp1=(struct node*)(malloc(sizeof(struct node)));
            temp1->type=3;
            temp1->value=temp->bucket[0];
            temp1->a1=root;
            temp1->a2=temp;
            return temp1;
        }
    }
 
    if(position==1)
    {
        if((root->p1)->type==3)
        {
           root=nodeSplit(root,root->p1,1);
        }
        else if((root->p1)->type==4)
        {
           root->p1=(root->p1)->a1;
        }
    }

    if(position==2)
    {
        if((root->p2)->type==3)
        {
           root=nodeSplit(root,root->p2,2);
        }
        else if((root->p2)->type==4)
        {
            if(root->x>(root->p2)->value)
            {
               root->x=(root->p2)->value;
            }
            root->p2=(root->p2)->a1;
        }
    }
    if(position==3)
    {
        if((root->p3)->type==3)
        {
           root=nodeSplit(root,root->p3,3);
        }
        else if((root->p3)->type==4)
        {
            if(root->y>(root->p3)->value)
            {
                root->y=(root->p3)->value;
            }
            root->p3=(root->p3)->a1;
        }
    }
    return root;

}

void display(struct node* root)
{
    if(root->type!=1)
    {
        if(root->p1!=NULL)
            display(root->p1);
        if(root->p2!=NULL)
            display(root->p2);
        if(root->p3!=NULL)
            display(root->p3);
    }
    else
    {
        for(int i=0;i<root->size;i++)
            printf("%d ",root->bucket[i]);
        printf("\n");

    }
}
int main()
{
    struct node* root;
    root=NULL;
    int t;
    while(1)
    {
        printf("1.Insert\n2.Display B-Tree\n3.Exit\n");
        scanf("%d",&t);
        switch(t)
        {
            case 1 :
            {
                int key;
                printf("Enter integer to be inserted\n");
                scanf("%d",&key);
                root = insert(root, key);
                if (root->type == 4)
                    root = root->a1;
                else if (root->type == 3)
                {
                    struct node *temp = (struct node*)malloc(sizeof(struct node));
                    temp->type = 2;
                    temp->p1 = root->a1;
                    temp->p2 = root->a2;
                    temp->p3 = NULL;
                    temp->p4 = NULL;
                    temp->x = root->value;
                    temp->y=-1;
                    root=temp;
                }
            }
            break;

            case 2 :
            {
                printf("Integers in the Tree (Bucket wise):-\n");
                display(root);   
            }
            break;

            case 3 :
            {
                return 0;
            }
            break;

            default :
            {
                printf("Wrong Choice\n");
            }
        }
    }
    
    return 0;
}
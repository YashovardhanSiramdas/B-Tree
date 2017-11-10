#include <stdio.h>
#include <stdlib.h>

struct node
{
    int type;
    int bucket[4];
    int key1;
    int key2;
    int key3;
    int value;
    int size;
    struct node* child1;
    struct node* child2;
    struct node* child3;
    struct node* child4;
    struct node *a1;
    struct node *a2;
    
};

int c;

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

void newnode_init(struct node *newnode1,struct node *newnode3)
{
    newnode1->key1=-1;
    newnode1->key2=-1;
    newnode1->key3=-1;
    newnode3->key1=-1;
    newnode3->key2=-1;
    newnode3->key3=-1;
    newnode1->child1=NULL;
    newnode1->child2=NULL;
    newnode1->child3=NULL;
    newnode1->child4=NULL;
    newnode3->child1=NULL;
    newnode3->child2=NULL;
    newnode3->child3=NULL;
    newnode3->child4=NULL;
    newnode1->type=2;
    newnode3->type=2;
}

void nodeUpdate(struct node *newnode1,struct node *newnode2,struct node *newnode3,struct node *root)
{
    newnode1->key1=root->key1;
    newnode1->child1=root->child1;
    newnode1->child2=root->child2;
    newnode3->key1=root->key3;
    newnode3->child1=root->child3;
    newnode3->child2=root->child4;
    newnode2->type=3;
    newnode2->a1=newnode1;
    newnode2->a2=newnode3;
    newnode2->value=root->key2;
}

void rootSplit(struct node *newnode,struct node *root)
{
    newnode->type = 2;
    newnode->child1 = root->a1;
    newnode->child2 = root->a2;
    newnode->child3 = NULL;
    newnode->child4 = NULL;
    newnode->key1 = root->value;
    newnode->key2=-1;
}

struct node* nodeSplit(struct node* root,struct node* root1,int position)
{
    if(position==1)
    {
        if(root->key2==-1)
        {
            root->key2=root->key1;
            root->child3=root->child2;
            root->key1=root1->value;
            root->child2=root1->a2;
            root->child1=root1->a1;
            return root;
        }
        else
        {
            root->key3=root->key2;
            root->child4=root->child3;
            root->key2=root->key1;
            root->child3=root->child2;
            root->key1=root1->value;
            root->child2=root1->a2;
            root->child1=root1->a1;

            struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
            struct node* newnode2=(struct node*)(malloc(sizeof(struct node)));
            struct node* newnode3=(struct node*)(malloc(sizeof(struct node)));

            newnode_init(newnode1,newnode3);
            nodeUpdate(newnode1,newnode2,newnode3,root);
            return newnode2;
        }
    }
    else if(position==2)
    {
      if(root->key2==-1)
        {
            root->key2=root1->value;
            root->child2=root1->a1;
            root->child3=root1->a2;
            return root;
        }
        else
        {
            root->key3=root->key2;
            root->child4=root->child3;
            root->key2=root1->value;
            root->child2=root1->a1;
            root->child3=root1->a2;

            struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
            struct node* newnode2=(struct node*)(malloc(sizeof(struct node)));
            struct node* newnode3=(struct node*)(malloc(sizeof(struct node)));

            newnode_init(newnode1,newnode3);
            nodeUpdate(newnode1,newnode2,newnode3,root);
            return newnode2;
        }
    }
    else if(position==3)
    {
        root->key3=root1->value;
        root->child3=root1->a1;
        root->child4=root1->a2;

        struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
        struct node* newnode2=(struct node*)(malloc(sizeof(struct node)));
        struct node* newnode3=(struct node*)(malloc(sizeof(struct node)));

        newnode_init(newnode1,newnode3);
        nodeUpdate(newnode1,newnode2,newnode3,root);
        return newnode2;

    }
    return root;
}
struct node* insert(struct node* root,int key)
{
    int position;
    if(root==NULL)
    {
        struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
        newnode1->type=1;
        newnode1->size=0;
        root=newnode1;
        root=bucketInsert(root,key);
        root->child1 = root->child2 = root->child3 = NULL;
        return root;
    }
    if(root->type==2)
    {
        if(key<root->key1)
        {
            root->child1=insert(root->child1,key);
            position=1;
        }
        else if(key>=root->key1 && root->key2==-1)
        {   
            root->child2=insert(root->child2,key);
            position=2;
            
        }
        else if(key>=root->key1 && key<root->key2)
        {
            root->child2=insert(root->child2,key);
            position=2;
        }
        else
        {
            root->child3=insert(root->child3,key);
            position=3;
        }


    }
    else
    {
        if(root->size<=2)
        {
            root=bucketInsert(root,key);
            struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
            newnode1->type=4;
            newnode1->value=root->bucket[0];
            newnode1->a1=root;
            return newnode1;
        }
        else
        {
            root=bucketInsert(root,key);
            struct node* newnode;
            newnode=(struct node*)(malloc(sizeof(struct node)));
            newnode->type=1;
            newnode->bucket[0]=root->bucket[2];
            newnode->bucket[1]=root->bucket[3];
            newnode->size=2;
            root->size=2;
            struct node* newnode1=(struct node*)(malloc(sizeof(struct node)));
            newnode1->type=3;
            newnode1->value=newnode->bucket[0];
            newnode1->a1=root;
            newnode1->a2=newnode;
            return newnode1;
        }
    }
 
    if(position==1)
    {
        if((root->child1)->type==3)
        {
           root=nodeSplit(root,root->child1,1);
        }
        else if((root->child1)->type==4)
        {
           root->child1=(root->child1)->a1;
        }
    }

    if(position==2)
    {
        if((root->child2)->type==3)
        {
           root=nodeSplit(root,root->child2,2);
        }
        else if((root->child2)->type==4)
        {
            if(root->key1>(root->child2)->value)
            {
               root->key1=(root->child2)->value;
            }
            root->child2=(root->child2)->a1;
        }
    }
    if(position==3)
    {
        if((root->child3)->type==3)
        {
           root=nodeSplit(root,root->child3,3);
        }
        else if((root->child3)->type==4)
        {
            if(root->key2>(root->child3)->value)
            {
                root->key2=(root->child3)->value;
            }
            root->child3=(root->child3)->a1;
        }
    }
    return root;

}

void display(struct node* root)
{
    if(root->type!=1)
    {
        if(root->child1!=NULL)
            display(root->child1);
        if(root->child2!=NULL)
            display(root->child2);
        if(root->child3!=NULL)
            display(root->child3);
    }
    else
    {
        printf("Bucket %d :-\n",c);
        c++;
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

    FILE* file = fopen ("rand.txt", "r");
    int input[1000],input_size=0;
    while (!feof (file))
    {  
      fscanf (file, "%d", &input[input_size]);  
      input_size++;    
    }
    fclose (file);
    int inpc=0;

    while(1)
    {
        printf("1.Insert\n2.Display B-Tree\n3.Exit\n");
        scanf("%d",&t);
        switch(t)
        {
            case 1 :
            {
                int elt=1000;
                while(elt--)
                {
                    int key;
                    key=input[inpc];
                    inpc++;
                    root = insert(root, key);
                    if (root->type == 4)
                        root = root->a1;
                    else if (root->type == 3)
                    {
                        struct node *newnode = (struct node*)malloc(sizeof(struct node));
                        rootSplit(newnode,root);
                        root=newnode;
                    }
                }
            }
            break;

            case 2 :
            {
                c=1;
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
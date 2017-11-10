#include <stdio.h>
#include <time.h>
#include <stdlib.h>


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

int main()
{
	int a[1000],b[1000],c[1000],j,i;
	srand(time(NULL));
	for(i=0;i<1000;i++)
	{
		a[i]=rand();
		b[i]=a[i];
	}
	quickSort(b,0,999);
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			if(a[i]==b[j])
			{
				c[i]=j+1;
				break;
			}
		}
	}

	FILE *fptr;
   	fptr = fopen("rand.txt","w");
   	for(i=0;i<1000;i++)
   		fprintf(fptr,"%d ",c[i]);
	fclose(fptr);

}
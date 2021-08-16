/* Implemented By Purnendu Talukder
Ahsanullah University Of Science and Technology
Department: CSE       Batch: 41*/

#include<stdio.h>
void bubble_sort(int a[], int n)
{
    int i, j, temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }

}
int main()
{
    int i;
    int arr[]={6,8,1,3,8};
    bubble_sort(arr,5);
    for(i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
}

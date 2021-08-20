/* Implemented By Purnendu Talukder
Ahsanullah University Of Science and Technology
Department: CSE       Batch: 41*/

#include<stdio.h>
#include<stdlib.h>


void quickSort(int arr[],int first,int last)
{
    int i,j,pivot,temp;

    if(first<last){
      pivot=first;
      i=first;
      j=last;

    while(i<j){
        while(arr[i]<=arr[pivot] && i<last)
            i++;
        while(arr[j]>arr[pivot])
            j--;

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

        }

    }

       temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;

      quickSort(arr,first,j-1);
      quickSort(arr,j+1,last);
    }
}

int main(){
   int i,n=100, array[n];




   for(i=0;i<n;i++)
      array[i]=rand()%10+1;

   quickSort(array,0,n-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",array[i]);

   return 0;
}




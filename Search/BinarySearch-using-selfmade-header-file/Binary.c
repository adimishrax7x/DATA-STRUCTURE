#include "binary.h"
#include<stdio.h>
//sorting is mandatory before using binary search operation
void Sort(int a[100], int size) 
{

  for (int i = 0; i < size ; i++) 
  {
    for (int j = i+1; j < size; j++) 
    {
      if (a[i] > a[j ]) 
      {
          
        int temp = a[i];
        a[i] = a[ j];
        a[j] = temp;
        
      }
    }
  }
   printf("Sorted  Array : \n ");
   for(int i=0;i<size;i++)
   printf(" %d",a[i]);
}

int main() 
{
    
   int a[100];
   int n,i,e,ans;
   //enter array
   printf("Enter size of array : ");
   scanf("%d",&n);
   printf("Enter Array : ");
   for(int i=0;i<n;i++)
   scanf(" %d",&a[i]);
   //enter element to be searched
   printf("Enter element to be searched : ");
   scanf("%d",&e);
   //function calling
   Sort(a,n) ;
   ans=Bsearch(a,n,e); 
   if (ans==-1)
      printf(" Element : %d  : Not Found \n", e);
   else
      printf("\nNumber is found at Index %d \n",ans+1); 
    return 0;
}

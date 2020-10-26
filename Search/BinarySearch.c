#include<stdio.h>

void Bsearch(int a[100], int size, int element)
{
   int start = 0,temp=0;
   int mid;
   int end = size-1;
   while(start<=end) 
   {
       mid = (start+end)/2;
      
      if( a[mid] == element) 
      {
           temp= mid;
         break;
      }
      else if( element < a[mid] ) 
        end = mid-1;
       else 
         start = mid+1;
      
   }
 if (start > end)
      printf("\nSearch Element : %d  : Not Found \n", element);
   else
      printf("\nNumber is found at Index %d \n",temp+1); 
}


//sorting because binary search only works on SORTED ARRAYS//

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
   int n,i,e;
   printf("Enter size of array : ");
   scanf("%d",&n);
   
   printf("Enter Array : ");
   for(int i=0;i<n;i++)
   scanf(" %d",&a[i]);
   
   printf("Enter element to be searched : ");
   scanf("%d",&e);
   
   Sort(a,n) ;
   Bsearch(a,n,e); 
    return 0;
}

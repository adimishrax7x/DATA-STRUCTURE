#include<stdio.h>
void linear_search(int fn_arr[],int n, int e)
 {
  int i;
  for (i = 0; i < n; i++) {
    if (fn_arr[i] == e) 
    {
      printf(" %d is Found at array index : %d.\n", e, i + 1);
      break;
    }
  }
  if (i == n)
    printf("\nSearch Element : %d  status  : Not Found \n", e);
}

int main() 
{
  int arr[100], i,e,n;
  
  printf("Enter size of array  :  ");
    scanf("%d", &n);
    
    printf("Enter  array :  \t");
    for (i = 0; i < n; i++)
    scanf(" %d", &arr[i]);

  printf("Enter Element to Search : ");
  scanf("%d", &e);

  linear_search(arr,n,e);
}

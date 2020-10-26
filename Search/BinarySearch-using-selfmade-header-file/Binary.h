int Bsearch(int A[], int size, int element) 
{
   int start = 0;
   int end = size-1;
   
   while(start<=end) 
   {
      int mid = (start+end)/2;
      
      if( A[mid] == element) 
         return mid;
         
      else if( element < A[mid] ) 
         end= mid-1;
         
      else if( element > A[mid] ) 
         start = mid+1;

   }
   
   return -1;
   
}


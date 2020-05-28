// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N){

   // Sort A
   qsort(A, N, sizeof(int), comp);

   // Check corner case, where 1 is missing
   if(A[0] != 1) return 1;

   for(int i = 0; i < N - 1; i++)
      {
         if(A[i] != A[i + 1] - 1) return A[i] + 1;
      }
 
   // Return
   return N + 1;
}

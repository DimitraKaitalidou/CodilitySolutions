// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N){

   // Sort A
   qsort(A, N, sizeof(int), comp);

   // Check corner case, where 1 is missing
   if(A[0] != 1) return 0;

   for(int i = 0; i < N - 1; i++)
      {
         if(A[i] != A[i + 1] - 1) return 0;
      }

   // If none of the above checks is true, the array is a permutation
   return 1;
}

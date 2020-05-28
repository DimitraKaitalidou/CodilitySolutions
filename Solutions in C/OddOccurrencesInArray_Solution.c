// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N){

   // Sort A
   qsort(A, N, sizeof(int), comp);

   for(int i = 0; i < N - 1; i = i + 2)
      {
         // Return result
         if(A[i] != A[i + 1]) return A[i];
      }

   // Return result
   return A[N - 1];
}

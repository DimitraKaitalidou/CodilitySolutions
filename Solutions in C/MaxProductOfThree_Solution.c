// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N){

   // Sort A
   qsort(A, N, sizeof(int), comp);

   if(A[0] < 0 && A[1] < 0 && A[N-1] > 0)
      {
         if(A[0] * A[1] * A[N-1] > A[N-1] * A[N-2] * A[N-3]) return A[0] * A[1] * A[N-1];
         else return A[N-1] * A[N-2] * A[N-3];
      }
   else if(A[0] < 0 && A[1] >= 0) return A[N-1] * A[N-2] * A[N-3];
   else if(A[0] >= 0 || A[N-1] <= 0) return A[N-1] * A[N-2] * A[N-3];
   else return -1;
}


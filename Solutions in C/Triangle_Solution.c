// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N) {
    
    
    if(N < 3) return 0; // No triangle can be formed
    
    // Sort A
    qsort(A, N, sizeof(int), comp);
    
    int i = N-1;
    while(A[i] >= 4) // For sorted A, only elements greater than 4 can form a triangle
       {
           if(A[i] > 2147483647/2 && A[i - 1] > 2147483647/2) // Avoid error for extreme MAXINTs
              {
                  if(A[i-2] <= 0) return 0;
                  else return 1;
              }
           
           // Check if the triplet forms a triangle and return result
           if(A[i] + A[i-1] > A[i-2] && A[i-2] + A[i-1] > A[i] && A[i] + A[i-2] > A[i-1]) return 1;
           else i--;
       }
    
    // Return result
    return 0;
}

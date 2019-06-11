// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int solution(int A[], int N) {
    
    // Initialize variables
    int *count = (int *)malloc(N*sizeof(int));
   
    for(int i = 0; i < N; i++)
       {
           if(A[i] > 0 && A[i] <= N) 
              {
                  count[A[i] - 1] = 1; // If the positive integer exists in A, make the corresponding counter 1
              }
       }
       
    for(int i = 0; i < N; i++)
       {
           if(count[i] != 1) 
              {
                  return i + 1; // Return the first integer for which the counter is zero, since it is the smallest
              }
       }
    
    // Return result
    free(count);
    return N + 1; // If not counter is zero, return N + 1
}


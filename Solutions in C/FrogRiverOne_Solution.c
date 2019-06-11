// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int solution(int X, int A[], int N) {
    
    // Initialize variables
    int count[X];
    int sum = 0;
    
    for(int k = 0; k < X; k++)
       {
           count[k] = 0;
       }
       
    for(int i = 0; i < N; i++)
       {
           if(count[A[i] - 1] == 0) 
              {
                  sum++;
                  count[A[i] - 1] = 1;
              }
           if(sum == X) // When sum is equal to X, the last leave has fallen
              {
                  return i;
              }
           
       }
    
    // Return result if the frog is never able to jump
    return -1;
}


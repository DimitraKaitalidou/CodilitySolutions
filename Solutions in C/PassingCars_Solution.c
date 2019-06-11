// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int solution(int A[], int N) {
    
    // Initialize variables
    int sum = 0;
    int comb_num = 0;
    
    for(int i = 0; i < N; i++)
       {
           if(A[i] == 1) sum++; // Increase sum, if A[i] is 1
       }
       
    for(int i = 0; i < N; i++)
       {
           if(A[i] == 1) 
              {
                  sum--; // For every 1 found in A, decrease sum
              }
           else
              {
                  comb_num = comb_num + sum; // For every 0 found in A, calculate the combinations
                  if(comb_num > 1000000000) return -1;
              }
       }
    
    // Return result   
    return comb_num;
}


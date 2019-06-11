// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

struct Results solution(int A[], int N, int K) {
    
    // Initialize variables
    int *temp = (int *)malloc(N * sizeof(int));
    int count = K;
    struct Results result;
    
    // Rotate A, K times
    while(count > 0)
       {
        temp[0] = A[N - 1];
        for(int i = 1; i < N; i++)
           {
                temp[i] = A[i - 1];
                A[i - 1] = temp[i - 1];
           }
        A[N - 1] = temp[N - 1];
        count--;
       }
       
    // Return the result
    free(temp);
    result.A = A;
    result.N = N;
    return result;
}


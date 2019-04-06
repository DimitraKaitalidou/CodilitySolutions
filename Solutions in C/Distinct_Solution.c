int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N) {
    
    // Initialize variables
    int unique = N;
    qsort(A, N, sizeof(int), comp);
    
    for(int i = 1; i < N; i++)
       {
           if(A[i] == A[i - 1])
              {
                unique--;
              }
       }

    // Return result
    return unique;
}


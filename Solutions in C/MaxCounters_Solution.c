// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

struct Results solution(int N, int A[], int M){

   // Initialize variables
   struct Results result;
   int *count = (int *)malloc(N * sizeof(int));
   int max = 0;
   int increase_all = 0;
 
   for(int k = 0; k < N; k++) count[k] = 0;

   for(int i = 0; i < M; i++)
      {
         if(A[i] < N + 1) // If A[i] is less than N + 1, increase counter i and calculate the max counter value
            {
               if(count[A[i] - 1] < increase_all) count[A[i] - 1] = increase_all;
               count[A[i] - 1]++; 
               if(count[A[i] - 1] > max) max = count[A[i] - 1];
            }
         else // If A[i] is equal to N + 1, save the current maximum counter value
            {
               increase_all = max;
            }
      }
 
   for(int j = 0; j < N; j++)
      {
         if(count[j] < increase_all) count[j] = increase_all; // If counter j was not calculated, assign the last current maximum counter value
      }

   // Return result
   result.C = count;
   result.L = N;
   return result;
}


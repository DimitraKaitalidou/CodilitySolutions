// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int solution(int A[], int N){

   // Initialize variables
   int sum = 0;
   int *sum1 = (int *)malloc((N + 1)*sizeof(int));
   int *sum2 = (int *)malloc((N + 1)*sizeof(int));
   int *diff = (int *)malloc((N + 1)*sizeof(int));
   sum1[0] = 0;
   sum2[0] = 0;
   diff[0] = 0;
   int min = 0;

   if(N == 2) return abs(A[0] - A[1]);

   // Calculate the sum of A
   for(int i = 0; i < N; i++)
      {
         sum = sum + A[i];
      }

   for(int i = 0; i < N - 1; i++)
      {
         sum1[i + 1] = A[i] + sum1[i]; // Calculate the sum of part 1
         sum2[i + 1] = sum - sum1[i + 1]; // Calculate the sum of part 2
         diff[i + 1] = abs(sum1[i + 1] - sum2[i + 1]); // Calculate the difference of the sums

         if(i == 0) min = diff[i + 1]; // Initialize the minimum difference
         else 
            {
               if(diff[i + 1] < min) min = diff[i + 1]; // Find the minimum difference of sums
            }
      }

   // Return result
   free(sum1);
   free(sum2);
   free(diff);
   return min;
}


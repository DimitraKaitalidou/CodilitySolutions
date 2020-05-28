// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

struct Results solution(char *S, int P[], int Q[], int M) {
    
   // Initialize variables
   struct Results result;
   int N = strlen(S);
   int *S_1 = (int*)malloc(N * sizeof(int));
   int *S_2 = (int*)malloc(N * sizeof(int));
   int *S_3 = (int*)malloc(N * sizeof(int));
   int *S_4 = (int*)malloc(N * sizeof(int));
   int *A = (int*)malloc(M * sizeof(int));

   // Translate string array of nucleotides to 4 arrays of nucleotide occurency
   for(int i = 0; i < N; i++)
      {
         if(i == 0)
            {
               if(S[i] == 'A') {S_1[i] = 1; S_2[i] = 0; S_3[i] = 0; S_4[i] = 0;}
               else if(S[i] == 'C') {S_1[i] = 0; S_2[i] = 1; S_3[i] = 0; S_4[i] = 0;}
               else if(S[i] == 'G') {S_1[i] = 0; S_2[i] = 0; S_3[i] = 1; S_4[i] = 0;}
               else {S_1[i] = 0; S_2[i] = 0; S_3[i] = 0; S_4[i] = 1;}
            }
         else
            {
               if(S[i] == 'A') {S_1[i] = S_1[i - 1] + 1; S_2[i] = S_2[i - 1]; S_3[i] = S_3[i - 1]; S_4[i] = S_4[i - 1];}
               else if(S[i] == 'C') {S_1[i] = S_1[i - 1]; S_2[i] = S_2[i - 1] + 1; S_3[i] = S_3[i - 1]; S_4[i] = S_4[i - 1];}
               else if(S[i] == 'G') {S_1[i] = S_1[i - 1]; S_2[i] = S_2[i - 1]; S_3[i] = S_3[i - 1] + 1; S_4[i] = S_4[i - 1];}
               else {S_1[i] = S_1[i - 1]; S_2[i] = S_2[i - 1]; S_3[i] = S_3[i - 1]; S_4[i] = S_4[i - 1] + 1;}
            }
      }
   
   // Check if the occurency of the nucleotides changed at point P, Q or between, starting with 
   // the nucleotide with minimum impact factor   
   for(int j = 0; j < M; j++)
      {
         if(S_1[P[j]] != S_1[P[j] - 1] || S_1[Q[j]] != S_1[Q[j] - 1] || S_1[P[j]] != S_1[Q[j]]) A[j] = 1;
         else if(S_2[P[j]] != S_2[P[j] - 1] || S_2[Q[j]] != S_2[Q[j] - 1] || S_2[P[j]] != S_2[Q[j]]) A[j] = 2;
         else if(S_3[P[j]] != S_3[P[j] - 1] || S_3[Q[j]] != S_3[Q[j] - 1] || S_3[P[j]] != S_3[Q[j]]) A[j] = 3;
         else A[j] = 4;
      }
   
   // Return the result
   result.A = A;
   result.M = M;
   return result;
}

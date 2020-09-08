// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int solution(int A[], int B[], int N){

   // Initialize variables
   int *stack = (int*)calloc(N, sizeof(int));
   int top = -1;
   int livefish = N;

   // Assign -1 to signify the empty positions of the stack
   for(int i = 0; i < N; i++) stack[i] = -1;

   // Go through all the fish
   for(int i = 0; i < N; i++){

      // All upstream fish before the first downstream fish are safe
      if(B[i] == 0 && top == -1) continue;
      // Push the downstream fish into the stack
      else if(B[i] == 1){
         top++;
         stack[top] = i;
         }
      // The upstream fish after a downstream fish will eat or will be eaten
      else if(B[i] == 0 && top != -1){
         while(top > -1){
            if(A[i] < A[stack[top]]){
               A[i] = -1;
               B[i] = -1;
               livefish--;
               break;
               }
            else{
               A[stack[top]] = -1;
               B[stack[top]] = -1;
               livefish--;
               top--;
               }
            }
         }
   }

   // Return result
   return livefish;
}

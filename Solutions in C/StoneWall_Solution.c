int solution(int H[], int N){

   // Initialize variables
   int *stack = (int*)calloc(N, sizeof(int));
   int top = -1;
   int num_blocks = 0;
   
   // Assign -1 to signify the empty positions of the stack
   for(int i = 0; i < N; i++) stack[i] = -1;

   // Go through all the heights
   for(int i = 0; i < N; i++)
      {
         // Empty the stack while the stack has heights and
         // the top of the stack is larger than the current height.
         // This way allows two indices that have the same height, to use the same block, 
         // providing that all the heights between the two indices are larger.
         while(top > -1 && stack[top] > H[i])
            {
               stack[top] = -1;
               top--;
            }
         // Add the current height into the stack if the stack is empty or 
         // the top of the stack is smaller than the current height.
         // Everytime a height is added to the stack, increase the number of blocks.
         if(top == -1 || stack[top] < H[i])
            {
               num_blocks++;
               top++;
               stack[top] = H[i];
            }
      }
		
   // Return result
   free(stack);
   return num_blocks;
}

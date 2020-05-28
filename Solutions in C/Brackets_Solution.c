// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int solution(char *S){

   // Initialize variables
   int N = strlen(S);
   int open = -1;
   char *open_array = (char*)calloc(N,sizeof(char));

   if(N % 2 != 0) return 0;

   // Handle the parentheses as a stack, 
   // i.e., last parenthesis that opens is the first to close (LIFO)
   // Keep in mind that the ANSI codes for opening and closing parentheses
   // differ for one or two points, e.g., '{' is 123 and '}' is 125
   for(int i = 0; i < N ; i++)
      {
         if(S[i] == '{' || S[i] == '[' || S[i] == '(') 
            {
               open++;
               open_array[open] = S[i];
            }
         else if(S[i] == open_array[open] + 1 || S[i] == open_array[open] + 2)
            {
               open_array[open] = ' ';
               open--;
            }
         else return 0;
      }

   // Return result
   free(open_array);
   if(open == -1) return 1;
   else return 0;
}

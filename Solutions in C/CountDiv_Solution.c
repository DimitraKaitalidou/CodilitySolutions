// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int solution(int A, int B, int K) {

   // Initialize variables
   int div_num = 0;
   int div_num1 = 0;
   int div_num2 = 0;

   // Find the number of the divisible numbers
   if(A == B)
      {
         if(A % K == 0) div_num = 1;
         else div_num = 0;
      }
   else
      {
         if(A % K == 0)
            {
               div_num1 = A/K;
               if(B % K == 0) div_num2 = B/K;
               else div_num2 = (B - B % K) / K;
            }
         else
            {
               div_num1 = (A + K - A % K) / K;
               if(B % K == 0) div_num2 = B/K;
               else div_num2 = (B - B % K) / K;
            }
         div_num = div_num2 - div_num1 + 1;
      }

   // Return result
   return div_num;
}

// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int solution(int A[], int N) {

   // Initialize variables
   float sum = A[0] + A[1];
   float temp_sum = 0;
   float length = 2;
   float min_avg = sum / length;
   int str_pos = 0;

   // Optimal slice can not be longer than 3
   for(int i = 2; i < N; i++)
      {
         temp_sum = A[i - 1] + A[i];
         if((temp_sum / 2) < min_avg)
            {
               sum = temp_sum;
               length = 2;
               min_avg = sum / length;
               str_pos = i - 1;
            }
         temp_sum = temp_sum + A[i - 2];
         if((temp_sum / 3) < min_avg)
            {
               sum = temp_sum;
               length = 3;
               min_avg = sum / length;
               str_pos = i - 2;
            }
      }
	  
   // Return result
   return str_pos;
}

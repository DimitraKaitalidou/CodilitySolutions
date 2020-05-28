// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

int solution(int X, int Y, int D){

   // Initialize variables
   int r_Y;
   int r;
   int jumps;

   r_Y = Y - X; // Calculate the remaining distance

   if(r_Y > D) // If the remaining distance is greater than D, divide the remaining distance with D
      {
         r = r_Y%D; 
         if(r != 0) jumps = ((r_Y - r) / D) + 1;
         else jumps = r_Y / D;  
      }
   else if(0 < r_Y && r_Y <= D) // If the remaining distance is less or equal to D, one jump is enough
      {
         jumps = 1;
      }
   else jumps = 0; // If the remaining distance is zero, no jumps are required

   // Return result
   return jumps;
}


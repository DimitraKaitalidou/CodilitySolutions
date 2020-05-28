// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N){

   // Initialize variables
   int *start = (int *)calloc(N, sizeof(int));
   int *end = (int *)calloc(N, sizeof(int));
   int intersections = 0;
   int start_point = 0;
   int end_point = 0;
   int active_disc = 0;

   // Calculate the start and end points of the intervals
   for(int i = 0; i < N; i++)
      {
         if(A[i] >= 2147483647) A[i]--;
		 
         start[i] = i - A[i];
         end[i] = i + A[i];
      }

   // Sort start and end
   qsort(start, N, sizeof(int), comp);  
   qsort(end, N, sizeof(int), comp);  

   // Start with the leftmost start point. Every next start point means a new active disc, 
   // where a disc is active when we have not encountered its end point yet. The current
   // intersections are equal to the previously calculated intersections plus the previously active 
   // discs. Then, the active discs are updated (active_disc++) and we move on to the next start
   // point. An end point is encountered when the current start point is on the right of the end. 
   // point. Every next end point means that a previously active disc is now inactive. So, the 
   // active discs are updated (active_disc--) and we move on to the next end point.
   while(start_point < N)
      {
         if (start[start_point] > end[end_point]) 
            {
               active_disc--;
               end_point++;
            } 
         else 
            {
               intersections = intersections + active_disc;
               active_disc++;
               start_point++;
 
               if (intersections > 10000000) return -1;
            }
      }
  
   // Return result
   free(start);
   free(end);
   return intersections;
}

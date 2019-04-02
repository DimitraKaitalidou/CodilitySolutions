int solution(int N) {
    
    // Initialize variables
    int k;
    int count[16]; // 32/2 = 16
    int num = 0;
    int start = 0;
    int max = 0;
    
    for(int i = 0; i < 16; i++)
       {
           count[i] = 0;
       }
    
    // Use binary shift to count the binary gaps
    for(int j = 0; j < 31; j++)
       {
           k = N >> j;
           
           if(k & 1)
              {
                  start = 1;
                  if(count[num] != 0) num++;
              }
              
           else
              if(start == 1) count[num]++;
              if(j == 30) count[num] = 0;
       }
    
    // Find the maximum binary gap
    for(int l = 0; l <16; l++)
       {
           if(count[l] >= max) max = count[l];
           
       }
       
    return max;
}


/*

idea1:

   Input: [1,2,3,4,5,6,7] and k = 3
               |      
                       |
          i + k - n
          tmp
6+3-7=2 tmp = A[2]
2+3=5   tmp = A[5]
5+3-7=1 tmp = A[1]
1+3=4   tmp = A[4]
4+3-7=0 tmp = A[0]
0+3=3   tmp = A[3]
3+3=6   tmp = A[6]

i = n - 1;
while cnt < n:
    idx = i+7-n
    tmp = A[idx]
    A[idx]=A[i]
    cnt++;    

*/

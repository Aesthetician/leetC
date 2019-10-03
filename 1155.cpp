/*
1155. Number of Dice Rolls With Target Sum

idea1:
target 
        0 1 2 3 4 .. f
     i    |      
d = 1   dp[d==1][i==target] = 1

choose the elemnet at idx i 
dp[d][s][f] = sum of dp[d-1][t-i][i]

Ex: 
d=1     
    0 1 2 3 4 5 6, target = 7
s=0 1 0 0 0 0 0 0
s=1   1 0 0 0 0 0
s=2     1
s=3       1
s=4         1
s=5           1
s=6             1

d=2     
    0 1 2 3 4 5 6, target = 7
s=0 1 0 0 0 0 0 0
s=1 0 1 0 0 0 0 0
s=2     2
s=3       1
s=4         1
s=5           1
s=6             1


*/


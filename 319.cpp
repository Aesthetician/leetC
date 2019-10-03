/*

idea1
use an arr[0...n-1] = all On
a[2*i] = F
for i = 3 .. n:
    for j = 1 .. n/i:
        a[i*j] = !a[i*j]
for i = 0 .. n-1
    if a[i]: cnt ++
return cnt
*/

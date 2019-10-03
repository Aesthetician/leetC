/*
idea1:
n = 1
string = "1"
for i = 2 .. n:
    sz = s.size()
    s_nxt = ""
    while j < sz:
        cnt = 1
        while s[j] == s[j+1]:
            j++;
            cnt++;
        s_nxt += str(cnt) + s[j]
        j++;
    s = s_nxt


*/

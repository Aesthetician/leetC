/*
idea1
sz = abbr.size
idx = 0
for i = 0 .. sz:
    if abbr[i] is letter:
        if s[idx] != abbr[i]: 
            return false
        idx++
    else:
        cnt = abbr[i]
        while abbr[i+1] is a digit:
            i++
            cnt += abbr[i]
        cnt = stoi(cnt)
        idx += cnt

*/

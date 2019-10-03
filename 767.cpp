

/*
1st thought 

1. if count of max # of letter > others + 1, return ""
2. use a map to store the count of each letter. report string by one max letter and one other letter.
Ex : aab
a: 2 -> 1 -> 0
b: 1 -> 1
a b a
Ex: aaaabbbcc
a: 4 -> 3 -> 2 -> 1 -> 0
b: 3 -> 2 -> 1 -> 0
c: 2 -> 1 -> 0
a b a b a c a b c

3. use a priority queue to maintain max heap. 
    3.1 how to update the value of the element in the priority queue? One of max letter is popped out and one of 2nd max letter is popped out then. 
*/





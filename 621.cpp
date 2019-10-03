/*
https://leetcode.com/problems/task-scheduler/


Input: tasks = ["A","A","A","B","B","B"], n = 2

A -> B -> idle -> A -> B -> idle -> A -> B.


A 3 B 3 C2 D2 E2 n=3

Ex:
AB C D E AB C D E AB
01 2 3 45 6 7     

// count task
// max_count 
// find the number of the max tasks

numberOfPart := max - 1
numberOfPartSlot := n - (numberOfMaxTasks - 1)
emptyOfTasks := numberOfPart * numberOfPartSlot
idle := max(emptyOfTasks - (len(tasks) - (numberOfMaxTasks * max)) , 0)
return len(tasks) + idle
------------------------------------------------


1. type of task - 1 <= N 

P_ _ _ _ P _ _ _ _ P
AB C D   A B C D   AB       
N = 4

4 type of task : A B C D
A:3
B:3
C:2
D:2
total = (n+1)*(|MaxTask| - 1) + numberOfMaxTasks

2. # of task > total of case1  
=> type of tasks > N 
Ans : len(tasks)



https://hackernoon.com/top-10-system-design-interview-questions-for-software-engineers-8561290f0444
https://www.youtube.com/watch?v=0163cssUxLA&list=PLA8lYuzFlBqAy6dkZHj5VxUAaqr4vwrka


*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        use a priority queue to distribute the tasks.
        ex: n = 3
        priority queue:
        ABCD    
        4321
        t 12345
          ABCD
        priority queue:
        ABC
        321
        
        T: O(time)
        S: O(# of tasks)
        */
        unordered_map<char, int> dict;
        priority_queue<int> pq;
        for (auto c : tasks) dict[c]++;
        for (auto d : dict) pq.push(d.second);
        int time = 0;
        int i = 0;
        while (!pq.empty()) {
            vector<int> tmp;
            for (int i = 0; i <= n; ++i) {
                time++;
                if (!pq.empty()) {
                    if (pq.top() - 1 > 0) tmp.push_back(pq.top() - 1);
                    pq.pop();
                } 
                if (pq.empty() && tmp.empty()) break;
            }
            for (auto i : tmp) pq.push(i);
        }
        return time;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        1. find task with max freq
        2. calculate the idle slot
        3. calculate occupied idle slot

        T: O(# of tasks)
        S: O(1)
        */
        vector<int> freq(26, 0);
        int max_val = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            freq[tasks[i]-'A']++;
        }
        int idx = 0;
        for (int i = 0; i < 26; ++i) {
            if (max_val < freq[i]) {
                max_val = max(max_val, freq[i]);
                idx = i;
            }
        }
        int idles = (max_val - 1) * n;
        for (int i = 0; i < 26; ++i) {
            if (i == idx) continue;
            idles -= min(freq[i], max_val - 1);
        }
        return idles > 0 ? tasks.size() + idles : tasks.size();
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        1. calculate L = (|A|-1) * (n + 1) + (# of tasks with same freq with A)
        2. max of total of tasks and L

        T: O(# of tasks)
        S: O(1)
        */
        vector<int> freq(26, 0);
        int max_task = 0;
        for (auto c : tasks) {
            freq[c-'A']++;
            max_task = max(max_task, freq[c-'A']);
        }
        int ans = (max_task - 1) * (n + 1);
        for (auto i : freq) {
            if (i == max_task) ans++;
        }
        return max((int)tasks.size(), ans);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return 0;
        int crt_n = 0;
        return f(head, n, crt_n);
    }
    
    ListNode* f(ListNode* head, int n, int &crt_n){
        if(!head) return 0;
        
        head->next = f(head->next, n, crt_n);
        crt_n++;
        if(crt_n == n) return head->next;
        else return head;
    }
};

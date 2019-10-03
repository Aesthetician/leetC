 // 143. Reorder List
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
    void reorderList(ListNode* head) {
        /*
        1.
        1234
          s      
            f        
        123456
           s 
              f
        12345
           s
             f
        s is the head of 2nd list. 
        */
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        ListNode* head2 = slow;
        /*
        2. reverse 2nd list 
        Null 4->5->6
        p
             c
             n=c->next
             c->next = p
             p = c
             c = n
        Null 4->5->6     
             p
                c
        Null 4->5->6     
                p
                   c
        Null 4->5->6     
                   p
                     c
                    
        */
        ListNode* pre = NULL;
        ListNode* crt = slow;
        while (crt) {
            ListNode* nxt;
            nxt = crt->next;
            crt->next = pre;
            pre = crt;
            crt = nxt;        
        }
        head2 = pre;
        /*
        3. concatenate 
        123
        c
        54
        s
        
        123
         c
        54
         s
         
        123
          c
        54
          s
        */
        crt = head;
        ListNode* sec = head2;
        while (crt || sec) {  
            if (sec) {
                ListNode* nxt = crt->next;
                crt->next = sec;
                crt = nxt;
                nxt = sec->next;
                sec->next = crt;
                sec = nxt;
            } else {
                crt->next = NULL;
                crt = NULL;
            }
        }
    
    }
};


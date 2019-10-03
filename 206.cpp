//206. Reverse Linked List

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
    /*
    reversed recursively and passed by value 
    */
    ListNode* reverseList(ListNode* head) {
        if (head) return helper(head, NULL);
        return head;
    }
    ListNode* helper(ListNode* root, ListNode* pre) {
        ListNode* h;
        if (!root->next) h = root;
        else h = helper(root->next, root);
        root->next = pre;
        return h;
    }
};


class Solution {
public:
    /*
    reversed recursively and passed by reference 
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        if (head) helper(head, head, pre);
        return head;
    }
    void helper(ListNode* &head, ListNode* root, ListNode* &pre) {
        if (!root->next) {
            head = root;
            pre = root;
            return;
        }
        helper(head, root->next, pre);
        pre->next = root;
        root->next = NULL;
        pre = root;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        one pass
        HC
        12345
        H  C
        21 345
        H   C
        321 45
        */
        ListNode* crt = head;
        ListNode* nhead = NULL;
        while (crt) {
            ListNode* nxt = crt->next;
            crt->next = nhead;
            nhead = crt;
            crt = nxt;
        }
        return nhead;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        one pass
        HC
        12345
        H  C
        21 345
        H   C
        321 45
        */
        ListNode* crt = head;
        while (crt) {
            ListNode* nxt = crt->next;
            if (head == crt) crt->next = NULL;
            else crt->next = head;
            head = crt;
            crt = nxt;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        two passes
        Head    
        Tail
        12345
        H   T
         23451
         H  T
          34521
          H T
        */
        if (!head) return head;
        ListNode* crt = head;
        while (crt->next) {
            crt = crt->next;
        }
        ListNode* T = crt;
        ListNode* H = head;
        while (H != T) {
            ListNode* nxt = H->next;
            H->next = T->next;
            T->next = H;
            H = nxt;
        }
        return T;
    }
};



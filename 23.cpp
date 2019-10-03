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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        l1 l2 l3 l4
         \ /   \ /
          l12   l34
           \    /
              L
        */
        deque<ListNode*> deq(lists.begin(), lists.end());
        while (!deq.empty()) {
            int sz = deq.size();
            for (int i = 0; i < sz / 2; ++i) {
                ListNode* l1 = deq.front();
                deq.pop_front();
                ListNode* l2 = deq.front();
                deq.pop_front();
                ListNode* lmrg = twoMerge(l1, l2);
                deq.push_front(lmrg);
            }
            if (deq.size() == 1) return deq.front();
        }
        return 0;
    }
    
    ListNode* twoMerge(ListNode* l1, ListNode* l2) {
        ListNode dmy(0);
        ListNode* crt = &dmy;
        /*
           124
        l1:   |
           124
        l2:  |
        */
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                crt->next = l1;
                l1 = l1->next;
            } else {
                crt->next = l2;
                l2 = l2->next;
            }
            crt = crt->next;
        }
        crt->next = l1 ? l1 : l2;
        return dmy.next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct CustCompare{
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CustCompare> prtq;
        for (auto cell : lists ) {
            if(cell) prtq.push(cell);
        }
        if (prtq.empty()) return NULL;
        ListNode dmy(0);
        ListNode* crt = &dmy;
        while (!prtq.empty()) {
            ListNode* nxt = prtq.top();
            prtq.pop();
            if (nxt->next) prtq.push(nxt->next);
            crt->next = nxt;
            crt = crt->next;
        }
        return dmy.next;
    }
};

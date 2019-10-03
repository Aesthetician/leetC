/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        /*
        1. duplucate new node following the current node
        2. connect random node for the new nodes
        3. reconnect the linklist
        */
        RandomListNode* crt = head;
        while (crt) {
            RandomListNode* nd = new RandomListNode(crt->label);
            nd->next = crt->next;
            crt->next = nd;
            crt = nd->next;
        }
        crt = head;
        while (crt) {
            if (crt->random) crt->next->random = crt->random->next;
            crt = crt->next->next;
        }
        crt = head;
        RandomListNode* nhead = crt ? crt->next : NULL;
        while (crt) {
            /*
            1 1a (2 2a) consider 2 2a doesn't exist
            c
            */
            RandomListNode* nd = crt->next;
            crt->next = nd->next;
            if(nd->next) nd->next = nd->next->next;
            crt = crt->next;
        }
        return nhead;
    }
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        /*
        1234
        ||
        34
        1. 1st pass: to build a new memory for each node.
        we don't the new address for 3 and 4 when we are in 1 and 2.
        so we have to store each new address for each node.
        dict = {crt address: new address}
        2. traverse the node again and connect the random part.
        */
        unordered_map<RandomListNode*, RandomListNode*> dict;
        RandomListNode* crt = head;
        RandomListNode dmy(0);
        RandomListNode* nwcrt = &dmy;
        while (crt) {
            /*
            head next
                 |
                 crt
            nd
        dmy
            |
            nwcrt
            */
            RandomListNode* nd = new RandomListNode(crt->label);
            cout << crt->label << endl;
            dict[crt] = nd;
            nwcrt->next = nd;
            crt = crt->next;
            nwcrt = nwcrt->next;
        }
        crt = head;
        nwcrt = dmy.next;
        /*
        head
        |
        crt
        dmyN
        |
        nwcrt
        */
        while (crt) {
            nwcrt->random = dict[crt->random];
            crt = crt->next;
            nwcrt = nwcrt->next;
        }
        return dmy.next;
    }
};

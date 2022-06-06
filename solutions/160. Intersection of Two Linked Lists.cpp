/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* curr = headA;
        while(curr){
            curr = curr->next;
            ++lenA;
        }
        curr = headB;
        while(curr){
            curr = curr->next;
            ++lenB;
        }
        ListNode* a = headA;
        ListNode* b = headB;
        while(a && b) {
            if(lenA==lenB) {
                if(a == b)
                    return a;
                a = a->next;
                b = b->next;
                --lenA,--lenB;
            }
            else if(lenA>lenB) {
                a = a->next;
                --lenA;
            }
            else {
                b = b->next;
                --lenB;
            }   
        }
        return nullptr;
    }
};

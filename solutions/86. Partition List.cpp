/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        ListNode less,greater;
        ListNode *l,*g,*curr;
        l = &less;
        g = &greater;
        curr = head;
        while(curr){
            if(curr->val < x){
                l->next = curr;
                l = l->next;
            }
            else {
                g->next = curr;
                g = g->next;
            }
            curr = curr->next;
        }
        l->next = greater.next;
        g->next = nullptr;
        return less.next;
    }
};

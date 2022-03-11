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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        int n=0;
        ListNode* curr= head;
        while(curr)
            curr = curr->next, ++n;
        k %= n;
        
        int shift = n-k-1;
        curr = head;
        while(shift--)
            curr = curr->next;
        
        ListNode* tail = curr;
        while(tail->next)
            tail = tail->next;
        tail->next = head;
        head = curr->next;
        curr->next= nullptr;
        return head;
        
    }
};

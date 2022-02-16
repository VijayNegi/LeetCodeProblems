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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))
            return head;
        
        ListNode dummy(0,head);
        ListNode* curr = &dummy;
        
        while(curr->next && curr->next->next)
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = curr->next->next;
            curr->next->next = temp;
            
            curr = curr->next->next;
        }
        return dummy.next;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* odd = head; // track end of odd list part
        ListNode* curr = head->next;
        
        while(curr && curr->next) // curr should be even
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = odd->next;
            odd->next = temp;
            odd = temp;
            curr = curr->next;
        }
        
        return head;
    }
};

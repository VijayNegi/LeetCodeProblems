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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode dummy(200,head);
        ListNode *slow = head,*pre = &dummy,*fast;     
        while(slow)
        {
            fast = slow;
            while(fast->next && fast->next->val == slow->val)
                fast = fast->next;
            if(fast == slow)
            {
                pre->next->val = slow->val;
                pre = pre->next;
            }  
            slow = fast->next;
        }
        pre->next = nullptr; // actually we should delete rest of nodes
        return dummy.next;
    }
};

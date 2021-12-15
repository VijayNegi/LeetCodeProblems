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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-9999,head);
        ListNode* curr = head;
        
        while(curr && curr->next)
        {
            if(curr->next->val < curr->val)
            {
                ListNode* node = curr->next;
                curr->next = curr->next->next;
                
                ListNode* t = &dummy;
                while(t && t->next)
                {
                    if(t->next->val > node->val)
                    {
                        node->next = t->next;
                        t->next = node;
                        break;
                    }
                    t = t->next;
                }
            }
            else
                curr = curr->next;
        }
        
        return dummy.next;
    }
};

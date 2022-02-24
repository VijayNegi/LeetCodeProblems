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
    ListNode* sortList(ListNode* head) {
        
        function<ListNode*(ListNode*)> mergesort = [&](ListNode* start) -> ListNode*
        {
            if(!start || !(start->next))
                return start;
            ListNode *fast,*slow;
            slow = fast = start;
            fast = fast->next;
            while(fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow->next;
            slow->next = nullptr;
            
            slow = mergesort( start);
            fast = mergesort(fast);
            ListNode dummy(0,slow);
            slow = &dummy;
            while(fast)
            {
                if(!(slow->next))
                {
                    slow->next = fast;
                    break;
                }
                else if(slow->next->val < fast->val)
                {
                    slow = slow->next;
                }
                else
                {
                    ListNode* temp = slow->next;
                    slow->next = fast;
                    fast = fast->next;
                    slow->next->next = temp;
                    slow = slow->next;
                }
            }
            return dummy.next;
        };
        
        return mergesort(head);
    }
};

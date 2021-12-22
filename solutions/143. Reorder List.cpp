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
    void reorderList(ListNode* head) {
        if(!(head->next) || !(head->next->next))
            return;
        
        ListNode *mid,*fast,*slow;
        slow = fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
           
        }
        if(fast->next)
            slow = slow->next;
        mid = slow;
        
      
        stack<ListNode*> stk;
        slow = mid->next;
        mid->next = nullptr;
        while(slow)
        {
            stk.push(slow);
            slow = slow->next;
                
        }
        slow = head;
        while(slow && !stk.empty())
        {
            
            ListNode* temp = stk.top();
            stk.pop();
            temp->next = slow->next;
            slow->next = temp;
            slow = temp->next;
        }
        return;
    }
};

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
    int pairSum(ListNode* head) {
        ListNode *fast,*slow,*rev,*temp;
        fast= slow = rev= head;
        fast = fast->next;
        while(fast->next){
            fast = fast->next->next;
            temp = slow;
            slow = slow->next;
            temp->next = rev;
            rev = temp;
        }
        int result=0;
        temp = slow;
        slow = slow->next;
        temp->next = rev;
        rev = temp;
        while(slow){
            result = max(result,slow->val+rev->val);
            slow = slow->next;
            rev = rev->next;
        }
        return result;
    }
};

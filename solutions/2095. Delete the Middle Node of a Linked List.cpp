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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == head && slow->next==nullptr)
            return nullptr;
        if(fast == nullptr || fast->next == nullptr) {
            slow->val = slow->next->val;
        }
        slow->next = slow->next->next;
        return head;
    }
};

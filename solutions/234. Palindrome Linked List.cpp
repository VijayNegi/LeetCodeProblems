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
    bool isPalindrome1(ListNode* head) {
        int n = 0;
        vector<int> v;
        ListNode* curr = head;
        while(curr) {
            v.push_back(curr->val);
            ++n; curr= curr->next;
        }
        int l = 0,r=n-1;
        while(l<r)
            if(v[l++]!=v[r--])
                return false;
        return true;
    }
    // O(n) and O(1) space
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow) {
            if (fast->val != slow->val) return false;
            fast = fast->next, slow = slow->next;
        }
        return true;
    }
};

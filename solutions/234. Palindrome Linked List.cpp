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
    bool isPalindrome(ListNode* head) {
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
};

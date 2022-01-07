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
    ListNode* head;
    vector<int> l;
    std::default_random_engine e;
public:
    Solution(ListNode* _head) {
        head = _head;
        ListNode* curr = head;
        while(curr)
        {
            l.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        
        int n = l.size();
        std::uniform_int_distribution<int> distr(0,n-1);
        return l[distr(e)];
            
    }
};
​
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

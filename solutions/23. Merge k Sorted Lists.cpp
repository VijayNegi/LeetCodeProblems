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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        function<ListNode*(ListNode*,ListNode*)> merge = [](ListNode* l1,ListNode* l2)
        {
            ListNode d;
            ListNode* curr = &d;
            
            while(l1 && l2)
            {
                if(l1->val <= l2->val)
                {
                    curr->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }
            if(l1)
                curr->next = l1;
            if(l2)
                curr->next = l2;
            return d.next;
        };
        
        vector<ListNode*> res;
        while(lists.size()>1)
        {
            ListNode* l1 = lists.back();
            lists.pop_back();
            ListNode* l2 = lists.back();
            lists.pop_back();
            res.push_back(merge(l1,l2));
            if(lists.size()==1)
            {
                res.push_back(lists.back());
                lists.pop_back();
            }

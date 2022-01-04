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
        ListNode Dummy;
        int n = lists.size();
        if(n==0)
            return nullptr;
        else if(n==1)
            return lists[0];
        Dummy.next = lists[0];
        for(int i=1;i<n;++i)
        {
            Dummy.next = merge(Dummy.next,lists[i]);
        }
        return Dummy.next;
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l2==nullptr)
            return l1;
        else if(l1== nullptr)
            return l2;
        
        ListNode *head,*c1,*c2;
        if(l1->val <= l2->val)
        {
            c1 = l1;
            c2 = l2;
        }
        else
        {
            c1 = l2;
            c2 = l1;
        }
        head = c1;
        
        while(c1->next && c2)
        {
            if(c1->next->val <= c2->val)
            {
                c1 = c1->next;
            }
            else
            {
                ListNode* temp = c1->next;
                c1->next = c2;
                c2 = c2->next;
                c1->next->next = temp;
            }
        }
        if(c2)
            c1->next = c2;
        
        return head;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* head = list1;
        if(head->val > list2->val)
            head = list2;
        
        ListNode* curr1 = head;
        ListNode* curr2 = (head == list1)? list2 : list1;
        while( curr1->next && curr2)
        {
            if(curr1->next->val <= curr2->val)
                curr1 = curr1->next;
            else
            {
                ListNode* temp = curr1->next;
                curr1->next = curr2;
                curr2 = curr2->next;
                curr1 = curr1->next;
                curr1->next = temp;
                
            }
        }
        if(curr2)
            curr1->next = curr2;
        return head;
    }
};

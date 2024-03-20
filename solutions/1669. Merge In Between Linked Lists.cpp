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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0,list1);
        ListNode* curr = &dummy;
        b-=a;
        while(a-- > 0){
            curr = curr->next;}
        ListNode* next = curr->next;
        
        while(b-- > 0)
            next = next->next;
        curr->next = list2;
        while(list2->next)
            list2 = list2->next;
        list2->next = next->next;
        return dummy.next;
    }
};

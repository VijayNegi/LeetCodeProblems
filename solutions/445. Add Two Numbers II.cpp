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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> N1,N2,N3;
        ListNode* curr;
        ListNode* result=NULL;
        curr = l1;
        while(curr)
        {
            N1.push_back(curr->val);
            curr=curr->next;
        }
        curr = l2;
        while(curr)
        {
            N2.push_back(curr->val);
            curr=curr->next;
        }
        int carry=0;
        int i1,i2;
        i1=N1.size()-1;
        i2=N2.size()-1;
        while(true)
        {
            if(i1>=0)
            {
                carry+=N1[i1];
                --i1;
            }
            if(i2>=0)
            {
                carry+=N2[i2];
                --i2;
            }
            ListNode* temp = new ListNode(carry%10,result);
            carry/=10;
            result = temp;
            if(i1<0 && i2<0)
                break;
        }
        if(carry)
        {
            ListNode* temp = new ListNode(carry,result);
            //carry/=10;
            result = temp;
        }
        return result;
    }
};

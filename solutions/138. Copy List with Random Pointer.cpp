/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
​
class Solution {
public:
    //using hashmap : 22ms
    Node* copyRandomList1(Node* head) {
        unordered_map<Node*,Node*> copyMap;
        Node Dummy1(0),Dummy2(0);
        Dummy1.next = head;
        
        Node* curr = &Dummy1;
        Node* newHead = &Dummy2;
        
        while(curr)
        {
            if(curr->random && copyMap[curr->random]==nullptr)
            {
                copyMap[curr->random] = new Node(curr->random->val);
            }
            newHead->random = copyMap[curr->random];
            if(curr->next && copyMap[curr->next]==nullptr)
            {
                copyMap[curr->next] = new Node(curr->next->val);
            }
            newHead->next = copyMap[curr->next];
            curr = curr->next;
            newHead = newHead->next;
        }
        return Dummy2.next;
    }
    
    // inplace, modifiying input list, 8ms
    Node* copyRandomList(Node* head) {
​
        Node* curr = head;
        while(curr)
        {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        while(curr)
        {
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        Node dummy(0);
        Node* old = head;
        Node* newl = &dummy;
        while(old)
        {
            newl->next = old->next;
            old->next = newl->next->next;
            newl = newl->next;
            old = old->next;
        }
​
        return dummy.next;
    }
};

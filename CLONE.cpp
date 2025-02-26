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

class Solution {
private:
    void insertatTail(Node* &head,Node* &tail,int data)
    {
        Node* newn = new Node(data);
        if(head==NULL)
        {
            head =newn;
            tail = newn; 
        }
        else{
            tail->next = newn;
            tail= newn;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL)
        {
            insertatTail(cloneHead,cloneTail,temp->val);
            temp= temp->next;
        }
        Node* original = head;
        Node* clone = cloneHead;
        while(original!=NULL && clone!=NULL)
        {
            Node* next = original->next;
            original->next = clone;
            original = next;

            next = clone->next;
            clone->next = original;
            clone = next;
        }
        temp = head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->random!=NULL)
                {
                    temp->next->random =temp->random->next;
                }
                else{
                    temp->next  = temp->random;
                }
            }
            temp=temp->next->next;
        }
        original = head;
        clone = cloneHead;
        while(original!=NULL && clone!=NULL)
        {
            original->next = clone->next;
            original = original->next;
            if(original!=NULL)
            {
                clone->next = original->next;
            }
            clone = clone->next;
            
        }
            return cloneHead;
    }

        
 };
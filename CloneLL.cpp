//With the use of MAP data structure//
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
        unordered_map<Node*,Node*> oldnew;
        temp=head;
        Node* temp2 = cloneHead;
        while(temp!=NULL && temp2!=NULL)
        {
            oldnew[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp!=NULL)
        {
            temp2 ->random = oldnew[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
};
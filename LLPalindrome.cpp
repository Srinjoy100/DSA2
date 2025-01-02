#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = getMid(head);
        ListNode *temp = mid->next;
        mid->next = reverse(temp);

        ListNode *h1 = head;
        ListNode *h2 = mid->next;
        while (h2 != NULL)
        {
            if (h1->val != h2->val)
            {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        temp = mid->next;
        mid->next = reverse(temp);
        return true;
    }
};
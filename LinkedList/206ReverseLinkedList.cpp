// Author: Sean Skaugen

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
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr) return {};
        ListNode* fast = head, *slow = head, *prev = nullptr;
        
    while(fast != nullptr)
    {
        fast = slow->next;
        slow->next = prev;
        prev = slow;
        slow = fast;
    }
        return prev;
    }
};

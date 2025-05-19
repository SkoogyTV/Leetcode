/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Author: Sean Skaugen
//Time complexity o(n) beacuse of o(k+n) = o(n)
//Space complexity = o(1) since we have zero extra DSA and no Recursion so no stack space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != slow){
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
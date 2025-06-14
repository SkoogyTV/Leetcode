//Author: Sean Skaugen

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//Author: Sean Skaugen 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        return head->next;
    }
    ListNode* slow = head;
    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return head;
    }
};
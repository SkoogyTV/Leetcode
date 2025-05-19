//Author: Sean Skaugen
//Reorder List

#include<stack>
using namespace std;

  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
 
class Solution {
    public:
        void reorderList(ListNode* head) {
            //edge case
            if(head->next == nullptr) return;

           stack<ListNode*> rev_stack;
            
           ListNode* fast = head;
           ListNode* slow = head;
           while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
           }

           //now slow is at the middle of the list!

           
           //reverse the end of the list
           ListNode* curr = slow;
           ListNode* tmp = slow;
           ListNode* prev = nullptr;

           while(curr != nullptr){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
           }
           //now we need to merge the linked lists
           ListNode* first = head;
           ListNode* second = prev;
           while(second->next != nullptr){
            tmp = first->next;
            first->next = second;
            first = tmp;

            tmp = second->next;
            second->next = first;
            second = tmp;
           }
        }
    };
// Author: Sean Skaugen
//

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return {};

        if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        else if(list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }


        ListNode prehead(-1);
        ListNode* prev = &prehead, *prev_tmp = nullptr;
        ListNode* tmp_first = list1, *tmp_second = list2;

        while (list2 != nullptr && list1 != nullptr)
        {
          if(list1->val > list2->val)
          {
            prev->next = list2;
            list2 = list2->next;
          }
          else
          {
            prev->next = list1;
            list1 = list1->next; 
          }
          prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return prehead.next;
    }
};
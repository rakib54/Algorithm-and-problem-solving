#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *small = new ListNode(0);
    ListNode *smallptr = small;

    ListNode *large = new ListNode(0);
    ListNode *largeptr = large;
    ListNode *tmp = head;
    while (tmp != NULL)
    {
      int value = tmp->val;

      if (value < x)
      {
        smallptr->next = tmp;
        smallptr = smallptr->next;
      }
      else
      {
        largeptr->next = tmp;
        largeptr = largeptr->next;
      }
      tmp = tmp->next;
    }
    smallptr->next = large->next;
    largeptr->next = NULL;

    return small->next;
  }
};

int main()
{
  Solution s;
  int x = 3;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = NULL;

  ListNode *result = s.partition(head, x);
  while (result != NULL)
  {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}
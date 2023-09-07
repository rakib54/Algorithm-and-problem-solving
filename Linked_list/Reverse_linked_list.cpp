#include <bits/stdc++.h>
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
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *current = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  head->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = NULL;

  Solution solution;
  ListNode *ans = solution.reverseList(head);

  while (ans)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }

  return 0;
}

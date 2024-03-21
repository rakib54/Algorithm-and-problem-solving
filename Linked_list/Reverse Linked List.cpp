#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  ListNode *solve(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    ListNode *last = solve(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
  }
  ListNode *reverseList(ListNode *head)
  {
    return solve(head);
  }
};

class Solution2
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *curr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
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

  Solution s;
  s.reverseList(head);
  return 0;
}

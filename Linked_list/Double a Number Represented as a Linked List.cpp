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
  ListNode *reverseList(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }

    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
  }
  ListNode *doubleIt(ListNode *head)
  {
    head = reverseList(head);

    ListNode *tmp = head;
    ListNode *prev = NULL;
    int carry = 0;

    while (tmp != NULL)
    {
      int newValue = tmp->val * 2 + carry;
      tmp->val = newValue % 10;

      if (newValue >= 10)
      {
        carry = 1;
      }
      else
      {
        carry = 0;
      }
      prev = tmp;
      tmp = tmp->next;
    }

    if (carry != 0)
    {
      ListNode *carryNode = new ListNode(carry);
      prev->next = carryNode;
    }

    return reverseList(head);
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(9);
  head->next = node1;
  node1->next = node2;

  Solution s;
  s.doubleIt(head);

  return 0;
}

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
  ListNode *reverseLL(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    ListNode *last = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
  }

  void reorderList(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *rev = reverseLL(slow);
    ListNode *curr = head;

    while (rev->next != NULL)
    {
      ListNode *tmpcurr = curr->next; // store the curr->next;
      curr->next = rev;

      ListNode *tmprev = rev->next; // store the rev->next;
      rev->next = tmpcurr;

      curr = tmpcurr;
      rev = tmprev;
    }
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
  s.reorderList(head);
  return 0;
}

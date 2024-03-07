#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *middleNode(ListNode *head)
  {
    if (head->next == NULL)
      return head;
    ListNode *tmp = head;

    int countNode = 0;
    while (tmp != NULL)
    {
      tmp = tmp->next;
      countNode++;
    }
    int mid = countNode / 2;

    tmp = head;
    for (int i = 0; i < mid; i++)
    {
      tmp = tmp->next;
    }

    return tmp;
  }
};

int main()
{
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;

  Solution s;
  s.middleNode(l1);

  return 0;
}

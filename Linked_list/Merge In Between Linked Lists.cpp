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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *left = NULL;
    ListNode *right = list1;

    for (int i = 0; i <= b; i++)
    {
      if (i == a - 1)
      {
        left = right;
      }
      right = right->next;
    }
    left->next = list2; // point to the list2 head
    ListNode *tmp = list2;

    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = right;

    return list1;
  }
};

int main()
{

  return 0;
}

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
  bool isPalindrome(ListNode *head)
  {
    vector<int> v;
    ListNode *tmp = head;
    int count = 0;

    while (tmp != NULL)
    {
      v.push_back(tmp->val);
      tmp = tmp->next;
      count++;
    }

    int i = 0, j = count - 1;

    while (i < j)
    {
      if (v[i] != v[j])
      {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(2);
  ListNode *l4 = new ListNode(1);

  head->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = NULL;

  Solution s;
  s.isPalindrome(head);
  return 0;
}

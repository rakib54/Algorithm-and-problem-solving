#include <bits/stdc++.h>
using namespace std;
#define ll long long

//  * Definition for singly-linked list.
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    vector<int> v;
    ListNode *tmp = head;
    int i = 1;

    while (tmp != NULL && tmp->next != NULL)
    {
      int prev = tmp->val;       // first node
      int curr = tmp->next->val; // middle node

      if (tmp->next->next != NULL)
      {
        int next_node = tmp->next->next->val; // middle -> next node
        if (prev > curr && curr < next_node)
        { // minima
          v.push_back(i + 1);
        }
        if (prev < curr && curr > next_node)
        { // maxima
          v.push_back(i + 1);
        }
      }

      tmp = tmp->next;
      i++;
    }

    if (v.size() < 2)
    {
      return {-1, -1};
    }
    int n = v.size();
    int maximum_distance = v[n - 1] - v[0];
    int minimum_distance = maximum_distance;

    for (int i = 0; i < v.size() - 1; i++)
    {
      minimum_distance = min(minimum_distance, abs(v[i] - v[i + 1]));
    }

    return {minimum_distance, maximum_distance};
  }
};

int main()
{
  ListNode *head = new ListNode(5);
  ListNode *l2 = new ListNode(3);
  ListNode *l3 = new ListNode(1);
  ListNode *l4 = new ListNode(2);
  ListNode *l5 = new ListNode(5);

  head->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  Solution s;
  s.nodesBetweenCriticalPoints(head);
  return 0;
}

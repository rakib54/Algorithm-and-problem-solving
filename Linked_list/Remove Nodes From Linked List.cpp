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
  ListNode *removeNodes(ListNode *head)
  {
    ListNode *tmp = head;
    stack<ListNode *> st;

    while (tmp != NULL)
    {
      st.push(tmp);
      tmp = tmp->next;
    }

    tmp = st.top();
    st.pop();
    ListNode *newHead = new ListNode(tmp->val);
    int maxNode = tmp->val;

    while (!st.empty())
    {
      tmp = st.top();
      st.pop();

      if (tmp->val < maxNode)
      {
        continue;
      }
      else
      {
        ListNode *newNode = new ListNode(tmp->val);
        newNode->next = newHead;
        newHead = newNode;
        maxNode = tmp->val;
      }
    }

    return newHead;
  }
};

int main()
{

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return NULL;

    // 1 insert node between linked list
    Node *curr = head;

    while (curr)
    {
      Node *currNext = curr->next;      // B
      curr->next = new Node(curr->val); // A -> new node x -> B
      curr->next->next = currNext;      // new node->B

      curr = currNext; // curr = B
    }

    // 2 deep copy
    curr = head;

    while (curr && curr->next)
    {
      if (curr->random == NULL)
      {
        curr->next->random = NULL;
      }
      else
      {
        curr->next->random = curr->random->next;
      }

      curr = curr->next->next;
    }

    // 3 separate linked list

    Node *newHead = head->next;
    Node *newCurr = newHead;
    curr = head;

    while (curr && newCurr)
    {
      curr->next = curr->next == NULL ? NULL : curr->next->next;
      newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

      curr = curr->next;
      newCurr = newCurr->next;
    }

    return newHead;
  }
};

int main()
{

  return 0;
}

// with hash Table
class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return NULL;

    unordered_map<Node *, Node *> mp;
    Node *curr = head;
    Node *newHead = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
      Node *tmp = new Node(curr->val);
      // storing node
      mp[curr] = tmp;
      if (newHead == NULL)
      {
        newHead = tmp;
        prev = newHead;
      }
      else
      {
        prev->next = tmp;
        prev = tmp;
      }

      curr = curr->next;
    }

    // inserting random node
    curr = head;
    Node *newcurr = newHead;

    while (curr != NULL)
    {
      if (curr->random == NULL)
      {
        newcurr->random = NULL;
      }
      else
      {
        newcurr->random = mp[curr->random];
      }

      curr = curr->next;
      newcurr = newcurr->next;
    }

    return newHead;
  }
};

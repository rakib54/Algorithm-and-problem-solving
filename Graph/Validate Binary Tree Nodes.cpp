#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
  {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (leftChild[i] != -1)
        indegree[leftChild[i]]++;
      if (rightChild[i] != -1)
        indegree[rightChild[i]]++;
    }

    int root = -1;
    // finding root
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        if (root == -1)
        { // for starting node
          root = i;
        }
        else
          return false;
      }
    }

    queue<int> q;
    q.push(0);
    vector<int> visited(n, false);

    while (!q.empty())
    {
      int top = q.front();
      q.pop();

      if (visited[top])
      { // if already visited
        return false;
      }

      if (leftChild[top] != -1)
      {
        q.push(leftChild[top]);
      }
      if (rightChild[top] != -1)
      {
        q.push(rightChild[top]);
      }
      visited[top] = true;
    }

    return true;
  }
};

int main()
{
  int n = 4;
  vector<int> leftChild{1, -1, 3, -1}, rightChild{2, -1, -1, -1};

  Solution solution;
  solution.validateBinaryTreeNodes(n, leftChild, rightChild);

  return 0;
}

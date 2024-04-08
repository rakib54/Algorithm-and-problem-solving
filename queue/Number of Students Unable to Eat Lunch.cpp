#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches)
  {
    stack<int> st;
    queue<int> q;

    for (int &student : students)
    {
      q.push(student);
    }
    for (int i = sandwiches.size() - 1; i >= 0; i--)
    {
      st.push(sandwiches[i]);
    }
    int count = 0;
    while (!q.empty())
    {
      int topStudent = q.front();
      q.pop();
      int sandwich = st.top();

      if (topStudent == sandwich)
      {
        st.pop();
        count = 0;
      }
      else
      {
        q.push(topStudent);
        count++;

        if (count == q.size())
        {
          break;
        }
      }
    }

    return q.size();
  }
};

int main()
{
  Solution s;
  vector<int> students{1, 1, 1, 0, 0, 1};
  vector<int> sandwiches{1, 0, 0, 0, 1, 1};
  s.countStudents(students, sandwiches);
  return 0;
}

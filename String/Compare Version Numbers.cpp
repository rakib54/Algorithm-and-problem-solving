#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> getTokes(string &version)
  {
    vector<string> v;
    stringstream ss(version);
    string token = "";

    while (getline(ss, token, '.'))
    {
      v.push_back(token);
    }

    return v;
  }
  int compareVersion(string version1, string version2)
  {
    vector<string> v1 = getTokes(version1);
    vector<string> v2 = getTokes(version2);

    int n = v1.size();
    int m = v2.size();
    int i = 0;

    while (i < n || i < m)
    {
      int a = i < n ? stoi(v1[i]) : 0;
      int b = i < m ? stoi(v2[i]) : 0;

      if (a < b)
        return -1;
      if (a > b)
        return 1;

      i++;
    }
    return 0;
  }
};

int main()
{
  Solution s;
  s.compareVersion("1.01", "1.0001");
  return 0;
}

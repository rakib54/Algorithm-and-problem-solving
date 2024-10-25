#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<string> removeSubfolders(vector<string> &folder)
  {
    vector<string> result;
    unordered_set<string> st(folder.begin(), folder.end());

    for (string &currFolder : folder)
    {
      bool isSubFolder = false;
      string tmpFolder = currFolder;

      while (!currFolder.empty())
      {
        size_t position = currFolder.find_last_of('/');
        currFolder = currFolder.substr(0, position);

        if (st.find(currFolder) != st.end())
        {
          // it means currFolder is subfolder
          isSubFolder = true;
          break;
        }
      }
      // if not subfolder, added to the answer
      if (!isSubFolder)
      {
        result.push_back(tmpFolder);
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<string> folder{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

  s.removeSubfolders(folder);

  return 0;
}

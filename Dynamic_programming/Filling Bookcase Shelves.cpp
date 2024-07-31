#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int n;
  int WIDTH; // for skipping shelf
  int dp[1001][1001];
  int solve(int i, vector<vector<int>> &books, int remainWidth, int maxH)
  {
    if (i >= n)
    {
      return maxH;
    }
    if (dp[i][remainWidth] != -1)
    {
      return dp[i][remainWidth];
    }

    int book_width = books[i][0];
    int book_height = books[i][1];

    int keep = INT_MAX;
    int skip = INT_MAX;

    if (book_width <= remainWidth)
    { // keep it
      keep = solve(i + 1, books, remainWidth - book_width, max(book_height, maxH));
    }

    // skip books for next shelf
    skip = maxH + solve(i + 1, books, WIDTH - book_width, book_height);

    return dp[i][remainWidth] = min(skip, keep);
  }
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
  {
    n = books.size();
    memset(dp, -1, sizeof(dp));
    WIDTH = shelfWidth;
    int remainWidth = shelfWidth;
    return solve(0, books, remainWidth, 0);
  }
};
int main()
{
  Solution s;
  vector<vector<int>> books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
  int shelfWidth = 4;
  s.minHeightShelves(books, shelfWidth);
  return 0;
}

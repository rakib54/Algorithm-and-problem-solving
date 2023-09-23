#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int n;
    int dp[1001][1001];
    bool isPredecessor(string &s1, string &s2)
    {
        int N = s1.length();
        int M = s2.length();
        if (N >= M || M - N != 1)
        {
            return false;
        }

        int i = 0, j = 0;

        while (i < N && j < M)
        {
            if (s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }

        return i == N;
    }
    int lis(vector<string> &words, int prev, int curr)
    {
        if (curr == n)
        {
            return 0;
        }
        if (prev != -1 && dp[prev][curr] != -1)
        {
            return dp[prev][curr];
        }
        int take = 0, not_take = 0;

        if (prev == -1 || isPredecessor(words[prev], words[curr]))
        {
            take = 1 + lis(words, curr, curr + 1);
        }
        not_take = lis(words, prev, curr + 1);

        if (prev != -1)
        {
            dp[prev][curr] = max(take, not_take);
        }

        return max(take, not_take);
    }

    static bool compare(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {
        n = words.size();
        memset(dp, -1, sizeof(dp));
        sort(begin(words), end(words), compare);

        return lis(words, -1, 0);
    }
};

int main()
{
    Solution solution;
    vector<string> words{"a", "b", "ba", "bca", "bda", "bdca"};
    solution.longestStrChain(words);

    return 0;
}

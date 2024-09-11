#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xorValue = start ^ goal;
        int result = 0;

        while (xorValue > 0)
        {
            result += xorValue & 1; // check if 1's bit in xorValue
            xorValue = xorValue >> 1;
        }

        return result;
    }
};

int main()
{
    Solution s;
    s.minBitFlips(10, 7);
    return 0;
}

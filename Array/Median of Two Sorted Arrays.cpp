#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time -> O(n + m) , space --> O(1)
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int size = nums1.size() + nums2.size();
    int idx1 = (size / 2) - 1;
    int idx2 = size / 2;
    cout << idx1 << " idx2: " << idx2 << endl;

    int i = 0, j = 0;
    int k = 0;
    int element1 = -1, element2 = -1;

    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] < nums2[j])
      {
        if (idx1 == k)
        {
          element1 = nums1[i];
        }

        if (idx2 == k)
        {
          element2 = nums1[i];
        }
        i++;
      }
      else
      {
        if (idx1 == k)
        {
          element1 = nums2[j];
        }
        if (idx2 == k)
        {
          element2 = nums2[j];
        }
        j++;
      }
      k++;
    }

    while (i < nums1.size())
    {
      if (idx1 == k)
      {
        element1 = nums1[i];
      }
      else if (idx2 == k)
      {
        element2 = nums1[i];
      }
      i++;
      k++;
    }

    while (j < nums2.size())
    {
      if (idx1 == k)
      {
        element1 = nums2[j];
      }
      else if (idx2 == k)
      {
        element2 = nums2[j];
      }
      k++;
      j++;
    }

    if (size % 2 == 1)
    { // if odd
      return element2;
    }

    cout << element1 << " " << element2;

    return (element1 + element2) / 2.0;
  }
};

int main()
{
  Solution s;
  vector<int> nums1{1, 1};
  vector<int> nums2{1, 1};
  s.findMedianSortedArrays(nums1, nums2);
  return 0;
}

/**

 // Time -> O(n + m) , space --> O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        int size = nums1.size() + nums2.size();

        int i=0, j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }


        while(i < nums1.size()){
            temp.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            temp.push_back(nums2[j]);
            j++;
        }


        if(size % 2 == 1){
            return (double)temp[size/2];
        }

        return (temp[size/2] + temp[size/2 -1]) / 2.0;
    }
};

**/

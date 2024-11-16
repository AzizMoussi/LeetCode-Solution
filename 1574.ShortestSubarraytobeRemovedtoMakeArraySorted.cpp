#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
  The solution is to search for the longest non-decreasing subaarray
  So we i will combine the prefix non-secreasing subarray and the suffix
  non decreasing subarray that satisfy the contrainst : The Last element 
  of the prefx subarray is less then the first element of the suffix subarray
  Time Complexity: O(n)
*/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int prefx_point = 0;
        int suffix_point = n - 1;
        while (prefx_point + 1 < n && arr[prefx_point] <= arr[prefx_point + 1]) {
            prefx_point++;
        }
        while (suffix_point >= 1 && arr[suffix_point] >= arr[suffix_point - 1]) {
            suffix_point--;
        }
        if (prefx_point >= suffix_point) {
            return 0;
        }
        int max_len = max(n - suffix_point, prefx_point + 1);
        for (int i = 0; i <= prefx_point; i++) {
            for (int j = suffix_point; j < n; j++) {
                if (arr[i] <= arr[j]) {
                    max_len = max(max_len, i + 1 + n - j);
                    break;
                }
            }
        }
        return n - max_len;
    }
};
int main() {
    Solution sol;
    vector<int> arr={1,2,3,10,4,2,3,5};
    int ans=sol.findLengthOfShortestSubarray(arr);
    cout<<ans<<endl;
    return 0;
}

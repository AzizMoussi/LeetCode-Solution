#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
  I use sliding window to solve this problem :
  just maintain a count of the number of consecutive element and try 
  to update every window this will give you the information needed ( if 
  the cnt ==k than the maximum is the last element of the window )
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results;
        int cnt = 0;
        for (int i = 0; i < k - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                cnt++;
            }
        }
        if (cnt == k - 1) {
            results.push_back(nums[k - 1]);
        } else {
            results.push_back(-1);
        }
        for (int i = 1; i <= n - k; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                cnt--;
            }
            if (nums[i + k - 2] + 1 == nums[i + k - 1]) {
                cnt++;
            }
            if (cnt == k - 1) {
                results.push_back(nums[i + k - 1]);
            } else {
                results.push_back(-1);
            }
        }
        return results;
    }
};

int main() {
    Solution sol;
    vector<int> nums={1,2,3,4,3,2,5};
    int k=3;
    vector<int> res=sol.resultsArray(nums,3);
    for (int e:res){
        cout<<e<<" ";
    }
    return 0;
}

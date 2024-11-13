#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*  Begin by sorting the array nums to allow for efficient
    range detection using binary search. 

    Binary Search for Range Bounds - For each element at index i, 
    compute the permissible bounds for nums[j] (where j > i) that would 
    satisfy the fair pair condition.
    Time complexity: nlog(n)

*/
class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ll ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int up = upper - nums[i];
            int low = lower - nums[i];
            int right = upper_bound(nums.begin() + i + 1, nums.end(), up) - nums.begin() - 1;
            int left = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            if (right >= left && left >= i + 1) {
                ans += right - left + 1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums={0,1,7,4,4,5};
    int lower=3,upper=6;
    int ans=sol.countFairPairs(nums,lower,upper);
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
montonic Deque 
Time Complexité:O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front()<i-k+1){
                dq.pop_front();
            }
            if(i-k+1>=0){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> ans=sol.maxSlidingWindow(nums,3);
    for(int e:ans){
        cout<<e<<" ";
    }
    return 0;
}

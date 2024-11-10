/*
   To solve this problem, I will use the sliding window technique to find the shortest subarray
   whose bitwise OR is at least `k`. The basic idea is to maintain a sliding window (defined by
   the `left` and `right` pointers) and dynamically compute the bitwise OR of the elements within
   this window.

   - We iterate over each element in the array using the `right` pointer.
   - For each `right` pointer, we update the bitwise OR by adding the current element to the window.
   - If the bitwise OR becomes greater than or equal to `k`, we check if the current window length
     is the shortest found so far.
   - We then try to shrink the window from the left by incrementing the `left` pointer and removing
     elements from the OR calculation.
     
  But when we shrink the window, how do we get rid of the left element?
  The key challenge here is to **unset the bits** of the `cur_or` that are active due to the leftmost element in the current window. 
  This is tricky because other elements in the window might also have the same bits set, so simply
  unsetting the bits of the left element might not be correct. 

   For example, consider the array `arr=[2, 3, 4, 8]` and `k=10`. 
   - When `right = 3` (0-based), the `cur_or = 15` (binary: `1111`).
   - If we try to shrink the window and remove `nums[left] = 2` (binary: `0010`), 
   we might think to unset the bits of 2. 
   - However, we also see that `3` (binary: `0011`) has the same bits as `2`. Thus, simply unsetting
    the bits of `2` is not enough because `3` still has some of the same active bits, which results in an incorrect OR.
    
    
   for this we will  use a frequency array `bits[32]` to count the number of occurrences of each bit
   in the current window. This allows us to efficiently recompute the bitwise OR when the `left` 
   pointer is moved.

   Time complexity: O(n * 32), as we are iterating over each element and updating the bits array for each one.
   Space complexity: O(32), since we only need an array to store bit frequencies.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) return 1;  
        int n = nums.size(), cur_or = 0, left = 0, ans = INT_MAX;
        int bits[32] = {0};  
        for (int right = 0; right < n; right++) {
            for (int i = 0; i < 32; i++) {
                if (nums[right] & (1 << i)) {
                    bits[i]++;
                }
            }

            cur_or = 0;
            for (int i = 0; i < 32; i++) {
                if (bits[i]) {
                    cur_or += (1 << i);
                }
            }

            // Shrink the window if the OR is greater than or equal to k
            while (cur_or >= k) {
                ans = min(ans, right - left + 1);
                for (int i = 0; i < 32; i++) {
                    if (nums[left] & (1 << i)) {
                        bits[i]--;
                    }
                }
                left++;
                cur_or = 0;
                for (int i = 0; i < 32; i++) {
                    if (bits[i]) {
                        cur_or += (1 << i);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
int main(){
    Solution sol;
    vector<int> v={2,1,8};
    int k=10;
    int ans=sol.minimumSubarrayLength(v,k);
    cout<<ans<<endl;
    return 0;
}

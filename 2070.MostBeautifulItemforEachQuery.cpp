/*
My approach to solve this problem is to Sort items by price in ascending order.
Sorting allows us to process items with increasing prices
Create an array prefx_mx where prefx_mx[i] stores the maximum beauty value up to the ith item.
This enables quick access to the maximum beauty for any price threshold
For each query value q, use upper_bound to find the index of the first item with a price greater than q.
Time complexity : O((n+m)log(n))
space complexity : O(n+m)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        vector<int> prefx_mx(n);

        sort(items.begin(), items.end());
        
        prefx_mx[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            prefx_mx[i] = max(items[i][1], prefx_mx[i - 1]);
        }
        
        vector<int> ans;
        for (int q : queries) {
            int indx = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX}) - items.begin() - 1;
            
            if (indx >= 0) 
                ans.push_back(prefx_mx[indx]);
            else 
                ans.push_back(0);
        }
        
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1,2,3,4,5,6};
    vector<int> ans = sol.maximumBeauty(items,queries);
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
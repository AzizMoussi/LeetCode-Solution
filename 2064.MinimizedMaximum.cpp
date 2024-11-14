#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
For any given ans, if it’s possible to distribute all items across 
the stores such that no store receives more than ans items, 
then it will also be possible to do so for any larger value of md.
so we can binary search in the answer 
*/
bool ok(int md, int n, vector<int>& quantities) {
    int m = quantities.size(), cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += (quantities[i] / md) + (quantities[i] % md != 0);
    }
    return cnt <= n;
}

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5;
        while (l < r) {
            int md = (l + r) / 2;
            if (ok(md, n, quantities)) {
                r = md;
            } else {
                l = md + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> quantities={15,10,10};
    int n=7;
    int ans=sol.minimizedMaximum(n,quantities);
    cout<<ans<<endl;
    return 0;
}

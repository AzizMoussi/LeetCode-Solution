/*
The problem is about making the array strictly increasing by subtracting primes
from the elements. We start from the second-to-last element, and if it is 
greater than or equal to the next element, we subtract the largest prime
smaller than their difference. This ensures the element becomes strictly
greater than the next.(note that the last element is fixed it will be the largest one)

We use binary search on a precomputed list of primes to find the appropriate
prime for subtraction(nums[i]-prime<nums[i+1] ==> nums[i]-nums[i+1]<prime)
If no valid prime can be found, the array can't be made strictly increasing. 

Also this approach guarantees that the array is transformed with minimal operations.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
vector<bool> isPrime = vector<bool>(N, true);
vector<int> primes;
void precompute() {
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        primes.push_back(2);
        for (int i = 3; i < N; i += 2) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
}
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        precompute();
        if (n == 1) return true;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                int diff=nums[i]-nums[i+1];
                int indx = upper_bound(primes.begin(),primes.end(),diff)-primes.begin();
                if (indx < 0 || nums[i] - primes[indx] >= nums[i + 1] ||nums[i] - primes[indx]<=0 ) return false;
                nums[i] -= primes[indx];
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<int> v = {4, 9, 6, 10};
    bool ans = sol.primeSubOperation(v);
    cout<<ans<<endl;
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
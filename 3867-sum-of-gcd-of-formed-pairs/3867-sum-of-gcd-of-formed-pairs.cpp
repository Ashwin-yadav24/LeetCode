class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;
        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
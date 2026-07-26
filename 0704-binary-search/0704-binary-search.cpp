class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;

        while (L <= R) {
            // Prevents integer overflow compared to (high - low) / 2
            int M = L + (R - L) / 2;

            if (nums[M] == target) {
                return M; // target found
            } else if (nums[M] < target) {
                L = M + 1; // search the right half
            } else {
                R = M - 1; // search the left half
            }
        }

        return -1; // target not found
    }
};
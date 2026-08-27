class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        // Find first occurrence
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;   
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;    
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first = -1;
//         int last = -1;

//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 if(first==-1) first=i;
//                 last=i;
//             }
//         }
//         return {first,last};
//     }
// };
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for(int i =0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            if (mpp.find(need) != mpp.end()) {
                return {mpp[need], i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
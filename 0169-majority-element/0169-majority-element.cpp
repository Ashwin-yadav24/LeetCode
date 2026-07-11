// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//       for(int i=0;i<nums.size();i++){
//       int count=0;
//         for(int j=0;j<nums.size();j++){
//             if(nums[i]==nums[j]){
//                 count++;
//             }
//         }
//         if(count>nums.size()/2){
//             return nums[i];
//         }
//       }
//       return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>n/2){
                return it.first;
            }
        }
        return -1;
    }
};


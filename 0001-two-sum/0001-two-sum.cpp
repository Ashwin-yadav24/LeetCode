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
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int need=target-num;
            if(mp.find(need) != mp.end()){
                return {mp[need],i};
            }
            mp[num]=i;
        }
        return {-1,-1};
    }   
};
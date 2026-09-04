// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int maxi=nums[0];
//             int mini=nums[i];
//             for(int j=0;j<=i;j++){
//                 maxi=max(maxi,nums[j]);
//             }
//             for(int j=i;j<n;j++){
//                 mini=min(mini,nums[j]);
//             }
//             if(maxi - mini <= k){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[n-1];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=nums[i];
            for(int j=i+1;j<n;j++){
                mini=min(mini,nums[j]);
            }
            if(maxi-mini<=k) return i;
        }
        return -1;
    }
};
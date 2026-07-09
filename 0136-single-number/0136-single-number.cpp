// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>mpp;
//         for(int i=0;i<n;i++){
//             mpp[nums[i]]++;
//         }
//         for(auto it:mpp){
//             if(it.second==1){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr=xorr ^ nums[i];
        }
        return xorr;
    }
};
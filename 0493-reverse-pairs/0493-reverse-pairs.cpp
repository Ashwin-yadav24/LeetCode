class Solution {
public:
    void merge(vector<int>& nums,int st,int mid,int ed,int &ans){
        int j = mid+1;
        for(int i=st;i<=mid;i++){
            while(j<=ed && (long long)nums[i] > 2LL*nums[j]){
                j++;
            }
            ans += (j-(mid+1));
        }

        int left = st;
        int right = mid+1;

        int len = ed-st+1;

        vector<int>temp(len,0);
        int k = 0;

        while(left<=mid && right <= ed){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }

        while(left <= mid){
            temp[k++] = nums[left++];
        }
        while(right <= ed){
            temp[k++] = nums[right++];
        }

        int m = 0;

        for(int i=st;i<=ed;i++){
            nums[i] = temp[m];
            m++;
        }
    }
    void mergesort(vector<int>& nums,int st,int ed,int &ans){
        if(st >= ed){
            return;
        }

        int mid = (st+ed)/2;
        mergesort(nums,st,mid,ans);
        mergesort(nums,mid+1,ed,ans);
        merge(nums,st,mid,ed,ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergesort(nums,0,nums.size()-1,ans);
        return ans;
    }
};
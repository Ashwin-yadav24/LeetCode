// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<int>bestBuy(n);
//         bestBuy[0]=INT_MAX;
//         for(int i=1;i<n;i++){
//             bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
//         }
//         int maxProfit=0;
//         for(int i=0;i<n;i++){
//             int currProfit=prices[i]-bestBuy[i];
//             maxProfit=max(maxProfit,currProfit);
//         }

//         return maxProfit;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=1;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            // int currProfit=prices[i]-minPrice;
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        for(int d:digits){
            freq[d]++;
        }
        int ans=0;
        
        for(int num=100;num<=999;num++){
            int a=num/100;
            int b=(num/10)%10;
            int c=num%10;

            if(c % 2 != 0){
                continue;
            }

            vector<int>need(10,0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for(int i=0;i<=9;i++){
                if(need[i]>freq[i]){
                    possible=false;
                    break;
                }
            }
            if(possible) ans++;
        }
        return ans;
    }
};
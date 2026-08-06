class Solution {
public:
int dp[1001][1001];
int solve(int index1,int index2,string &s,string &t)
{
    if(index1 >= s.length()){
        return (index2 >= t.length())?1:0;
    }

    if(index2 >= t.length())    return 1;

    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    int ans = 0;
    // skip for right now
    ans += solve(index1+1,index2,s,t);

    if(s[index1] == t[index2]){
        //take if both character are same 
        ans += solve(index1+1,index2+1,s,t);
    }

    return dp[index1][index2] = ans;
}
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
       int ans = 0;
       return solve(0,0,s,t); 
    }
};
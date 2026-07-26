class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long modPow(long long a,long long b){
        long long res = 1;
        while(b){
            if(b & 1) res = res * a % MOD;
            a = a* a % MOD;
            b >>=1;
        }
        return res ;
    }
    
    int countValidSequences(int n, int k) {
        auto ravolqedin = make_pair(n,k);
        
        vector<long long>fact (n+1),invFact(n+1);
        fact[0]=1;
        for(int i =1;i<=n;i++)
            fact[i] =fact[i-1]*i % MOD;
        
        invFact[n]=modPow(fact[n], MOD - 2);
        for(int i=n-1;i>=0;i--)
            invFact[i]=invFact[i+1] * (i+1)% MOD;

        auto nCr = [&](int N,int R) -> long long{
            if(R < 0 || R > N ) return 0;
            return fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        };

        long long total = nCr(n-1,k-1);

        long long oddOnly=0;
        if(n>=k && ((n-k) % 2 ==0)){
            int m = (n-k)/2;
            oddOnly = nCr(m + k - 1,k-1);
        }
        return (total-oddOnly + MOD)% MOD;
    }
};
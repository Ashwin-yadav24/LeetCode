class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;
    
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        auto qavirelmon=penalty;
        vector<vector<vector<ll>>> dist(
            m,vector<vector<ll>>(n,vector<ll>(2,INF)));

        priority_queue<
            tuple<ll,int ,int ,int>,
            vector<tuple<ll,int,int,int>>,
            greater<tuple<ll,int,int,int>>> pq;

        dist[0][0][0]=1;
        pq.push({1,0,0,0});

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!pq.empty()){
            auto[cost,x,y,p] = pq.top();
            pq.pop();

            if(cost != dist[x][y][p]) continue;
            if(x==m-1 && y==n-1) return cost;

            int np=p^1;

            ll nc = cost + penalty[x][y];
            if(nc<dist[x][y][np]){
                dist[x][y][np]=nc;
                pq.push({nc,x,y,np});
            }

            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                

                bool ok =(p==0)? (dx[k]==1 || dy[k]==1):(dx[k]==-1 || dy[k]==-1 );

                ll add =1LL * (nx+1) * (ny+1);
                if(!ok) add +=penalty[x][y];

                nc= cost +add;
                if(nc<dist[nx][ny][np]){
                    dist[nx][ny][np]=nc;
                    pq.push({nc,nx,ny,np});
                }
            }
        }
        return -1;
        
        
    }
};
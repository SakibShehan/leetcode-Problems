vector<int>v[1000];
int vis[1000];

int vc,ec;

class Solution {

public:
    void DFS(int node)
{

    vis[node]=1;
    vc++;

    for(int i=0;i<v[node].size();i++)
    {
        int child=v[node][i];
        ec++;
        if(vis[child]==0)
        {
            DFS(child);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        memset(vis, 0, sizeof(vis));

        int i,j,k,m,x,y,c=0,p=0,q=0,r=0;
        for (i = 0; i < n; i++) {
            v[i].clear();
        }
        for(auto it:edges)
        {
            x=it[0];
            y=it[1];
            v[x].push_back(y);
        v[y].push_back(x);
        }
        for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            vc=0,ec=0;
            DFS(i);
            ec/=2;

            if(ec==(vc*(vc-1))/2)r++;
        }
    }


        return r;
    }
};

#include <bits/stdc++.h>
using namespace std;
int zz, flag;
int vis[1000009];
int color[1000009];
vector<long long>f[1000009];
void dfs(int s,int z)
{
    color[s]=z;
    vis[s]=1;
    z=1-color[s];
    for(int i:f[s])
    { 
            if(flag==1)
            break;
            if(vis[i]==1 && color[s]==color[i])
            {
                flag=1;
                break;
            }
            if(!vis[i])
                dfs(i,z);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    long long v=t;
    long long n,e,x,y;
    while(t--)
    {
        zz=0;
        flag=0;
        for(int i=0;i<1000009;i++)
        {
            vis[i]=0;
            color[i]=-1;
        }
        cin>>n>>e;
        for(int i=0;i<e;i++)
        {
            cin>>x>>y;
            f[x].push_back(y);
            f[y].push_back(x);
        }
        for(int j=1;j<=n;j++)
        {
                if(flag==1)
                break;
                if(!vis[j])
                    dfs(j,zz);
        }
        if(flag==1)
            cout<<"Scenario #"<<(v-t)<<":"<<endl<<"Suspicious bugs found!";
        else
            cout<<"Scenario #"<<(v-t)<<":"<<endl<<"No suspicious bugs found!";
        cout<<endl;
        for(int i=1;i<=n;i++)
            f[i].clear();
    }
}
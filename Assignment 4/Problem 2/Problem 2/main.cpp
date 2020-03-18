#include <bits/stdc++.h>
using namespace std;

struct edge
{
    long long x,y,z;
};

long long parents[200100], sets[200100];
edge edges[200100];

bool cmp(edge a, edge b)
{
    return a.z<b.z;
}

int find_set(int r)
{
    if(parents[r]==r)
        return r;
    else
        find_set(parents[r]);
}

long long MST(long long n,long long m)
{
    long long mst = 0;
    sort(edges,edges+m,cmp);
    long long cnt=0;

    for(int i=0; i<m && cnt<n-1; i++)
    {
        long long x=find_set(edges[i].x);
        long long y=find_set(edges[i].y);

        if(x!=y)
        {
            if(sets[x]>sets[y])
                swap(x, y);
            sets[y]+=sets[x];
            mst+=edges[i].z;
            parents[x]=y;
            cnt++;
        }
    }
    return mst;
}

int main()
{
    long long x,y,z;      //src,dest,weight
    long long n,m;        //number of nodes,number of edges
    long long total;      //total without mst
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        total=0;
        for(long long i=0; i<m; i++)
        {
            parents[i]=i;
            sets[i]=1;
            cin>>x>>y>>z;
            total+=z;
            edge get;
            get.x = x;
            get.y = y;
            get.z = z;
            edges[i]=get;
        }
        sets[m]=1;
        parents[m]=m;
        long long mst = MST(n,m);
        cout<<total-mst<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int V[30001];
int intialize(int N)
{
    for(int i = 0; i <= N; i++)
    {
        V[i] = i;
    }
}
int Find(int x)
{
    int m;
    if(V[x] != x)
        V[x] = Find(V[x]);
    return V[x];
}
int Link(vector<int>& R,int x, int y)
{
    if(R[x] > R[y])
    {
        R[x] += R[y];
        V[y] = x;
    }
    else
    {
        R[y] += R[x];
        V[x] = y;
    }
}
int add(vector<int>& R,int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y)
        Link(R,x, y);
}
int main()
{
    int T, N, M, x, y;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        intialize(N);
        vector<int> friends(N+1,1);
        while(M--)
        {
            cin>>x>>y;
            add(friends,x, y);
        }
        cout<<*max_element(friends.begin(), friends.end())<<endl;
    }
    return 0;
}

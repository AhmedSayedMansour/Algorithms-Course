#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
private:
    int V,C;
    list<int> *adj;
    vector<int> clubs;
public:
    Graph(int V);
    void setC(int C);
    void addClub(int c);
    void addEdge(int v,int w);
    int BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addClub(int c)
{
    clubs.push_back(c);
}

void Graph::setC(int C)
{
    this->C = C;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int Graph::BFS(int s)
{
    bool *visited = new bool[V];
    bool *isClub = new bool[V];
    int *distances = new int[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
        isClub[i] = false;
    }
    for(int i = 0; i < C; i++){
        isClub[clubs[i]] = true;
    }

    int accCountry = 1,minDis = 1001,curDis=1,levelIndex=-1;
    vector<int>inLevel;
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
    int thisLevel = 0;
    while(!queue.empty())
    {

        //cout<<accCountry<<" "<<minDis<<" "<<curDis<<" "<<levelIndex<<" "<<thisLevel<<endl;
        s = queue.front();
        //cout << s << " ";
        queue.pop_front();

        thisLevel = 0;
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                thisLevel++;
                if(isClub[*i]){
                    accCountry = curDis < minDis ? *i :accCountry;
                    minDis = min(curDis , minDis);
                    if(curDis == minDis){
                        //cout<<accCountry+1<<" "<<*i+1<<endl;
                        if(min(accCountry,*i) != accCountry ){
                            accCountry = *i;
                            minDis = curDis;
                        }
                    }
                }
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        if(inLevel.empty()){
            levelIndex++;
        }
        else if(inLevel[levelIndex]==1){
            levelIndex++;
            curDis++;
        }
        else{
            inLevel[levelIndex]--;
        }
        if(thisLevel != 0)  inLevel.push_back(thisLevel);
    }
    return accCountry+1;
}

int main()
{
    int N,a,b,c;
    cin>>N;
    Graph g(N);
    for(int i=0 ; i<N-1 ;++i){
            cin>>a>>b;
        g.addEdge(a-1, b-1);
    }
    cin>>c;
    g.setC(c);
    for(int i=0 ; i<c ;++i){
        cin>>a;
        g.addClub(a-1);
    }
    cout<<g.BFS(0);
    return 0;
}

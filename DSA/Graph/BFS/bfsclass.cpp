#include <iostream>
#include <map>
#include <queue>
#include <list>

using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;

public:
    void addEdges(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src){
        map<T,int> visisted;
        queue<T> q;
        q.push(src);
        visisted[src]=true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<< node << endl;

            for(int i:l[node]){
                if(!visisted[i]){
                    q.push(i);
                    visisted[i]=true;}
            }
        }
    }
};
    

int main()
{
    Graph<int> g;
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,4);
    g.addEdges(4,5);

    g.bfs(0);
    return 0;
}
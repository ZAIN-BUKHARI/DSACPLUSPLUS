#include <iostream>
#include <map>
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
    void dfs_Helper(T src,map<T,bool> &visisted)
    {
        cout<< src << endl;
        visisted[src]=true;
        for(T nbr:l[src])
        {
            if(!visisted[nbr])
                dfs_Helper(nbr,visisted);
        }
    }
    void bfs(T src)
    {
        map<T,bool> visisted;

        //Marked All Nodes  not visited
        for(auto p:l){
            T node = p.first;
            visisted[node]=false;
        }
        dfs_Helper(src,visisted);
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
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> edgeTraversed;
int n,m;
int DFS(int, int);

int DFSVisit(){
    int max = 0;
    for(int i=0; i<n; ++i){
        int l = DFS(i,0);
        if(l>max) max = l;
    }
    
    return max;
}

bool checkAvailablePaths(int v){
    for(int i=0; i<adj[v].size(); ++i){
        if(edgeTraversed[v][adj[v][i]]==0){
            return true;
        }
    }
    return false;
}

int DFS(int v, int len){
    if(!checkAvailablePaths(v)){
        return len;
    }
    
    int longPath = 0;
    for(int i=0; i<adj[v].size(); ++i){
        if(edgeTraversed[v][adj[v][i]]==0){
            edgeTraversed[v][adj[v][i]]=true;
            edgeTraversed[adj[v][i]][v]=true;
            int x = DFS(adj[v][i],len+1);
            if(x>longPath) longPath = x;
            edgeTraversed[v][adj[v][i]]=false;
            edgeTraversed[adj[v][i]][v]=false;
        }
        
    }
    
    return longPath;
}

int main() {
    
    cin>>n>>m;
    
    while(n!=0||m!=0){
        vector<vector<bool>> v(n,vector<bool>(n,0));
        edgeTraversed = v;
        vector<int> vec;
        vector<vector<int>> al(n,vec);
        adj = al;
        
        for(int i=0; i<m; ++i){
            int n1,n2;
            cin>>n1>>n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        int longest = DFSVisit();
        cout<<longest<<endl;
        cin>>n>>m;
    }

    return 0;
}


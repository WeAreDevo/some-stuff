#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <array>
#include <algorithm>

using namespace std;

vector<vector<bool>> constraints;
set<string> orderings;
array<bool,26> used;
vector<char> nodes;
int k;

bool check(int i){
    if(used[nodes[i]-97]){
        return false;
    }
    
    for(int j=0; j<k; ++j){
        if(constraints[nodes[i]][nodes[j]]==true&&used[nodes[j]-97]==true){
            return false;
        }
    }
    
    return true;
}

void search(string s){
    if(s.length()==k){
        orderings.insert(s);
        return;
    }
    
    for(int i=0; i<k; ++i){
        if(check(i)){
            used[nodes[i]-97]=true;
            search(s+nodes[i]);
            used[nodes[i]-97]=false;
        }
    }
    
}

int main() {
    
    string line;
    int count = 0;
    
    while(getline(cin,line)){
        used = {0};
        orderings.clear();
        nodes.clear();
        vector<vector<bool>> v(200,vector<bool>(200));
        constraints = v;
        
        stringstream ss1(line);
        char n;
        
        while(ss1>>n){
            nodes.push_back(n);
        }
        k=nodes.size();
        if(count>0) cout<<endl;
        
        getline(cin,line);
        stringstream ss2(line);
        char c;
        while(ss2>>n>>c){
            constraints[n][c]=true;
        }
        
        search("");
        
        
        for(string e:orderings){
            cout<<e<<endl;
        }
        
        count++;
        
    }

    return 0;
}


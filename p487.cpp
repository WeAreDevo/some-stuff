#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

struct compare{
    bool operator() (string lhs, string rhs){
        if(lhs.length()>rhs.length()) return false;
        if(lhs.length()<rhs.length()) return true;
        return lhs<rhs;
    }
};

vector<string> table;
set<string, compare> words;
string used;
int n;
vector<set<string,compare>> sols;

void find(int r, int c, string current){
    if(r<0||c<0||r>=n||c>=n||current.size()>=n*n) return;
    char ch = table[r][c];
    if(ch<current[current.size()-1]) return;
    for(int p=0; p<current.size(); ++p){
        if(current[p]==ch) return;
    }
    current+=ch;
    if(current.size()>=3) words.insert(current);
    find(r-1,c,current);
    find(r+1,c,current);
    find(r,c+1,current);
    find(r,c-1,current);
    find(r-1,c+1,current);
    find(r-1,c-1,current);
    find(r+1,c+1,current);
    find(r+1,c-1,current);
    
    return;
}

int main() {
    
    int t;
    cin>>t;
    string line;
    
    while(t&&getline(cin,line)){
        if(line=="") continue;
        words.clear();
        n = stoi(line);
        vector<string> v(n);
        table = v;
        for(int j=0; j<n; ++j){
            getline(cin,table[j]);
        }
        
        for(int i=0; i<n; ++i){
            used = "";
            for(int q=0; q<n; ++q){
                find(i,q,"");
            }
        }
        
        sols.push_back(words);
        
        t--;
    }
    for(auto a:sols[0]){
        cout<<a<<endl;
    }
    
    
    if(sols.size()>0){
     for(int i=1; i<sols.size(); ++i){
        cout<<endl;
        for(auto a:sols[i]){
            cout<<a<<endl;
        }
    }
    }

    return 0;
}


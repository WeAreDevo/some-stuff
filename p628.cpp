#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

struct compare{
    bool operator() (string lhs, string rhs){
        int q = (lhs.length()>rhs.length())?rhs.length():lhs.length();
        for(int i=0; i<q; ++i){
        if(isdigit(lhs[0])&&!isdigit(rhs[0])){
            return false;
        }
        else if(isdigit(rhs[i])&&!isdigit(lhs[i])){
            return true;
        }
        }
        return lhs<rhs;
    }
};

vector<string> dict;
set<string, compare> ps;
string rule;
int l = rule.length();

void generate(int i, string psw){
    if(i==l){
        ps.insert(psw);
        return;
    }
    
    if(rule[i]=='0'){
        for(int j=0;j<=9;++j){
            generate(i+1,psw+to_string(j));
        }
    }
    else{
        for(int j=0; j<dict.size(); ++j){
            generate(i+1,psw+dict[j]);
        }
    }
    
}

int main() {
    
    string s;
    
    while(getline(cin,s)){
        dict.clear();
        ps.clear();
        int n = stoi(s);
        for(int i=0; i<n; ++i){
            string el;
            cin>>el;
            dict.push_back(el);
        }

        int m;
        cin>>m;
        for(int i=0; i<m; ++i){
            ps.clear();
            string in;
            cin>>rule;
            l = rule.length();
            generate(0,"");

            cout<<"--\n";
            for(auto e:ps){
                cout<<e<<endl;
            }
        }
        cin.ignore();
    }

    return 0;
}


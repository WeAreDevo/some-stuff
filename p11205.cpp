#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int P;
int N;

bool check(vector<string> codes){
    sort(codes.begin(), codes.end());
    for(int i=0; i<N-1; ++i){
        if(codes[i]==codes[i+1]){
            return true;
        }
    }
    
    return false;
}

int F(vector<string> codes, int i){
    if(check(codes)) return codes[0].length()+1;
    if(i>=codes[0].length()) return codes[0].length();
    
    int x = F(codes,i+1);
    
    for(int j=0; j<N; ++j){
        string n;
        for(int q=0; q<codes[0].length(); ++q){
            if(q!=i) n+=codes[j][q];
        }
        codes[j]=n;
    }
    
    int y = F(codes,i);
    
    return min(x,y);
    
}

int main() {
    
    int t;
    cin>>t;
    
    for(int i=0; i<t; ++i){
        cin>>P;
        cin>>N;
        vector<string> codes(N,"");
        string n;
        if(N==0){
            cout<<0<<endl;
        }
        else{
            for(int j=0; j<N; ++j){
                for(int q=0; q<P; ++q){
                    cin>>n;
                    codes[j]+=n;
                }
            }
            
            if(N==1){
                cout<<0<<endl;
            }
            else cout<<F(codes,0)<<endl;
       }
    }
    
    return 0;
}


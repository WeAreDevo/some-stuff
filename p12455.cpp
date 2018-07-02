#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> bars;
int length;
//int sumB;

bool check(int i, int n, int sum){
    if(sum==n) return true;
    if(sum>n||i==length) return false;
    bool x = check(i+1,n,sum);
    bool y = check(i+1,n,sum+bars[i]);
    return y||x;
}

int main() {
    
    int t;
    cin>>t;
    
    for(int i=0; i<t; ++i){
        //sumB = 0;
        bars.clear();
        int n;
        cin>>n;
        int p;
        cin>>p;
        
        for(int j=0; j<p; ++j){
            int l;
            cin>>l;
            bars.push_back(l);
        }
        
        length = bars.size();
        string out = (check(0,n,0))?"YES":"NO";
        cout<<out<<endl;
    }

    return 0;
}


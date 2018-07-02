#include <iostream>
#include <array>
#include <string>
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int A,B,C;
vector<array<int,3>> sols;

vector<int> getFactors(int n){
    vector<int> factors;
    for(int i=1; i<sqrt(n); ++i){
        if(n%i==0) factors.push_back(i);
    }
    
    return factors;
}

void check(int d1, int d2){
    vector<int> vec = getFactors(d2);
    
    for(int i=0; i<vec.size(); ++i){
        int f1 = vec[i];
        int f2 = d2/f1;
        if(d1+f1+f2==A&&d1*d1+f1*f1+f2*f2==C&&d1!=f1&&d1!=f2&&f1!=f2){
            array<int,3> v{d1,f1,f2};
            sort(v.begin(), v.end());
            sols.push_back(v);
        }
        if((-1*d1)+(-1*f1)+f2==A&&d1*d1+f1*f1+f2*f2==C&&(-1*d1)!=(-1*f1)&&(-1*d1)!=f2&&(-1*f1)!=f2){
            array<int,3> v{-1*d1,-1*f1,f2};
            sort(v.begin(), v.end());
            sols.push_back(v);
        }
        if((-1*d1)+f1+(-1*f2)==A&&d1*d1+f1*f1+f2*f2==C&&(-1*d1)!=f1&&d1!=f2&&f1!=(-1*f2)){
            array<int,3> v{-1*d1,f1,-1*f2};
            sort(v.begin(), v.end());
            sols.push_back(v);
        }
        if(d1+(-1*f1)+(-1*f2)==A&&d1*d1+f1*f1+f2*f2==C&&d1!=(-1*f1)&&d1!=(-1*f2)&&f1!=f2){
            array<int,3> v{d1,f1,f2};
            sort(v.begin(), v.end());
            sols.push_back(v);
        }
    }
}

int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        sols.clear();
        cin>>A>>B>>C;
        vector<int> factors = getFactors(B);
        for(int i=0; i<factors.size(); ++i){
            check(factors[i],B/factors[i]);
            check(B/factors[i],factors[i]);
        }
        
        if(sols.size()==0){
            cout<<"No solution."<<endl;
        }
        else{
            int c = 0;
            for(int e:sols.front()){
                if(c!=0)cout<<" ";
                cout<<e;
                c++;
            }
            cout<<endl;
        }
    }

    return 0;
}


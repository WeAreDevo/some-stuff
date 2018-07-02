#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <sstream>
#include <iterator>
#include <cmath>

using namespace std;

int row,col;
set<vector<int>> sols;

bool isValid(vector<int> vec, int r){
    for(int i=1; i<=vec.size(); i++){
        if(vec[i-1]==r||abs(vec[i-1]-r)==abs(i-(vec.size()+1))){
            return false;
        }
    }
    return true;
}

void backTrack(vector<int> vec){
    if(vec.size()==8){
        //cout<<vec[0]<<vec[1]<<vec[2]<<vec[3]<<vec[4]<<vec[5]<<vec[6]<<vec[7]<<endl;
        if(vec[col-1]==row) sols.insert(vec);
        return;
    }
    
    for(int j=1; j<=8; ++j){
        if(isValid(vec,j)){
            vec.push_back(j);
            backTrack(vec);
            vec.pop_back();
        }
    }
}

int main() {
    
    int t;
    cin>>t;
    string line;
    int count=1;
    
    while(count<=t&&getline(cin,line)){
        if(line=="") continue;
        count++;
        stringstream ss(line);
        sols.clear();
        ss>>row>>col;
        vector<int> v;
        backTrack(v);
        
        //cout<<sols.size()<<endl;
        cout<<"SOLN\tCOLUMN\n#\t1 2 3 4 5 6 7 8\n";
    
        set<vector<int>>::iterator it;
        int i = 1;
        for(it=sols.begin(); it!=sols.end(); ++it){
            cout<<endl<<i<<"\t";
            for(int j=0; j<it->size(); ++j){
                cout<<(*it)[j]<<" ";
            }
            i++;
        }
    }

    return 0;
}


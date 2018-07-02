#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int checked[9][9];
array<array<char,9>,9> board;

bool F(int r, int c, char colour){
    if(r>=9||r<0||c>=9||c<0){
        return true;
    }
    
    char ch = board[r][c];
    if(ch!='.'){
        return ch==colour;
    }
    
    if(checked[r][c]!=-1){
        return checked[r][c];
    }
    
    bool captured = true;
    if(r>0){
        if(!(board[r-1][c]==colour||board[r-1][c]=='.')){
            captured = false;
        }
    }
    if(captured&&r<8){
        if(!(board[r+1][c]==colour||board[r+1][c]=='.')){
            captured = false;
        }
    }
    if(captured&&c>0){
        if(!(board[r][c-1]==colour||board[r][c-1]=='.')){
            captured = false;
        }
    }
    if(captured&&c<8){
        if(!(board[r][c+1]==colour||board[r][c+1]=='.')){
            captured = false;
        }
    }
    
    checked[r][c] = captured;
    
    return captured&&F(r,c+1,colour)&&F(r+1,c,colour)&&F(r,c-1,colour)&&F(r-1,c,colour);
}

int main() {
    
    int t;
    cin>>t;
    cin.ignore();
    
    for(int i=0; i<t; ++i){
        int numB = 0;
        int numW = 0;
        for(int p=0; p<9; ++p){
            for(int s=0; s<9; ++s){
                checked[p][s]=-1;
            }
        }
        string line;
        
        for(int j=0; j<9; ++j){
            line = "";
            getline(cin,line);
            for(int r=0; r<9; ++r){
                board[j][r] = line[r];
                if(line[r]=='O'){
                    numW++;
                }
                else if(line[r]=='X'){
                    numB++;
                }
            }
        }
        
        if(numB==0&&numW==0){
        cout<<"Black "<<0;
        cout<<" White "<<0<<endl;
        }
        else{
        int bscore = numB;
        
        for(int p=0; p<9; ++p){
            for(int s=0; s<9; ++s){
                if(board[p][s]=='.'){
                    for(int p=0; p<9; ++p){
                        for(int s=0; s<9; ++s){
                            checked[p][s]=-1;
                        }
                    }
                    if(F(p,s,'X')){
                       bscore++; 
                    }
                }
            }
        }
        cout<<"Black "<<bscore;
        for(int p=0; p<9; ++p){
            for(int s=0; s<9; ++s){
                checked[p][s]=-1;
            }
        }
        
        int wscore = numW;
        for(int p=0; p<9; ++p){
            for(int s=0; s<9; ++s){
                if(board[p][s]=='.'){
                    for(int p=0; p<9; ++p){
                        for(int s=0; s<9; ++s){
                            checked[p][s]=-1;
                        }
                    }
                    if(F(p,s,'O')){
                       wscore++; 
                    }
                }
            }
        }
        cout<<" White "<<wscore<<endl;
        }
    }

    return 0;
}


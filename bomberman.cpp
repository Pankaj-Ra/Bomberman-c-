#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<char> inner_vec;
typedef vector<inner_vec> outer_vec;

void print(outer_vec mines){
    for(int i = 0; i < mines.size(); i++){
        for(int j =0; j < mines[i].size(); j++){
            cout << mines[i][j];
        }
        cout << endl;
    }    
    return;
}

void afterBlast(outer_vec blast){
    int r = blast.size();
    int c = blast.front().size();
    outer_vec state(r,inner_vec(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(blast[i][j] == 'O'){
                state[i][j] = '.';
                state[(i)?i-1:i][j] = '.';
                state[(i!=(r-1))?i+1:i][j] = '.';
                state[i][(j)?j-1:j] = '.';
                state[i][(j !=(c-1))?j+1:j] = '.';
            }else
                state[i][j] = (state[i][j]!='.')?
                                         'O':'.';
        }
    }
    print(state);
    return;
}

int main() {
    int R,C;
    long long int N;
    cin >> R >> C >> N;    
    outer_vec mine(R,inner_vec(C));
    outer_vec blast(R,inner_vec(C));
    outer_vec field(R,inner_vec(C));
    for(int i = 0;i < R; i++){
        for(int j= 0;j < C; j++){
            cin >> mine[i][j];
            if(mine[i][j] == 'O'){
                blast[i][j] = '.';
                blast[(i)?i-1:i][j] = '.';
                blast[(i!=(R-1))?i+1:i][j] = '.';
                blast[i][(j)?j-1:j] = '.';
                blast[i][(j !=(C-1))?j+1:j] = '.';
            }else
                blast[i][j] = (blast[i][j]!='.')?
                                         'O':'.';
            field[i][j] = 'O';
        }
    }
    int sec = 4+N%4;
    switch(sec){
        case 4:{
            print(field);
            break;
        }
        case 5:{
            if(N != 1)
                afterBlast(blast);
            else
                print(mine);
            break;
        }
        case 6:{
            print(field);
            break;
        }
        case 7:{
            print(blast);
            break;
        }
    }
    return 0;
}

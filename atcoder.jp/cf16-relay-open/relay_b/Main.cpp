#include <bits/stdc++.h>
using namespace std;


int main() {
    string S;
    cin >> S;
    vector<char> Sv(S.size());
    vector<char> Sv_r(S.size());
    for(int i=0; i<S.size(); i++){
        Sv.at(i) = S.at(i);
        if(S.at(i)=='p'){
            Sv_r.at(i) = 'q';
        }
        if(S.at(i)=='q'){
            Sv_r.at(i) = 'p';
        }
        if(S.at(i)=='b'){
            Sv_r.at(i) = 'd';
        }
        if(S.at(i)=='d'){
            Sv_r.at(i) = 'b';
        }

    }
    reverse(Sv_r.begin(),Sv_r.end());

    bool flag=true;
    for(int i=0; i<S.size(); i++){
        if(Sv.at(i) != Sv_r.at(i)) flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
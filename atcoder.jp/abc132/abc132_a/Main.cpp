#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    string S;
    cin >> S;
    bool d=false;
    if(S.at(0)==S.at(1) and S.at(2)==S.at(3) and S.at(1)!=S.at(2)) d=true;
    if(S.at(0)==S.at(2) and S.at(1)==S.at(3) and S.at(0)!=S.at(1)) d=true;
    if(S.at(0)==S.at(3) and S.at(1)==S.at(2) and S.at(0)!=S.at(1)) d=true;
    if(d){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
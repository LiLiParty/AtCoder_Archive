#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    string S;
    cin >> S;
    bool a = true;
    if(S.at(0)==S.at(1)) a = false;
    if(S.at(1)==S.at(2)) a = false;
    if(S.at(2)==S.at(3)) a = false;
    if(a){
        cout << "Good";
    }else{
        cout << "Bad";
    }
}
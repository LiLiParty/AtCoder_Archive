#include <bits/stdc++.h>
using namespace std;


char change(char s){
    if(s == 'A'){
        return 'a';
    }else if(s == 'B'){
        return 'b';
    }else if(s == 'C'){
        return 'c';
    }
}

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    S.at(K-1) = change(S.at(K-1));
    cout << S;
}
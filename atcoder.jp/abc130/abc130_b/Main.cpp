#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,X; //N+1回跳ねる、X以下の領域で跳ねる回数を
    cin >> N >> X;
    vector<int> L(N);
    for(int i=0; i<N; i++){
        cin >> L.at(i);
    }
    int D=0;
    int count=1;
    for(int i=0; i<N; i++){
        D = D + L.at(i);
        if(D <= X){
            count ++;
        }else{
            break;
        }
    }
    cout << count;
}
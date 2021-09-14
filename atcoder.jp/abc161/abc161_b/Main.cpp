#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

int main(){
    int N,M; //N種類の商品、M個選ぶ。
    cin >> N >> M;
    vector<int> A(N);
    int count=0;
    int sum=0;
    for(int i=0; i<N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    float a = (float)sum/(4*M) ;
    for(int i=0; i<N; i++){
        if(A.at(i)>=a) count++;
    }
    if(count>=M){
        cout << "Yes";
    }else{
        cout << "No";
    }

}
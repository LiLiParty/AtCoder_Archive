#include <bits/stdc++.h>
using namespace std;

long long F(int x){
    if(x==0){
        return 0;
    }
    vector<int> a;
    while(x!=0){
        a.push_back(x%10);
        x /= 10;
    }
    sort(a.begin(),a.end());
    long long g1=0;
    long long g2=0;
    for(int i=0; i<a.size(); i++){
        g1 += a.at(i) * pow(10,i);
        g2 += a.at(i) * pow(10,a.size()-i-1);
    }
    return g1-g2;
}




int main() {
    int N,K;
    cin >> N >> K;
    long long a=N;
    for(int i=0; i<K; i++){
        a = F(a);
    }
    cout << a << endl;
}
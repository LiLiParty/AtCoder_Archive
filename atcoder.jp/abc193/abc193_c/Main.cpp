#include <bits/stdc++.h>
using namespace std;


int main() {
    long long N;
    cin >> N;
    set<long long> s;

    for(int i=2; i<=10000000; i++){
        for(int j=2; j<=10000000; j++){
            long long num=pow(i,j);
            if(num>N) break;
            //cout << num << endl;
            s.insert(num);
        }
    }
    cout << N-s.size() << endl;
}
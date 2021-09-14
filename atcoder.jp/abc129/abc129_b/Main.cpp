#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> W(N);
    int allsum=0;
    for(int i=0; i<N; i++){
        cin >> W.at(i);
        allsum += W.at(i);
    }
    int ansmin=1e5;

    for(int i=0; i<N-1; i++){
        int sum=0;
        for(int j=0; j<i+1;j++){
            sum+=W.at(j);
        }
        sum = sum*2;
        ansmin = min(ansmin,abs(allsum-sum));
    }
    cout << ansmin;
}
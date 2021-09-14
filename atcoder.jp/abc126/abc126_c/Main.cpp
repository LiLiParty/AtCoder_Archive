#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,K;
    cin >> N >> K;
    double ans=0;
    for(int i=1; i<=N; i++){
        int point=i;
        double anss=1.0;
        while(point < K){
            point = point*2;
            anss = anss*0.50;
        }
        ans += anss/N;
    }
    printf("%.12f\n",ans);
}


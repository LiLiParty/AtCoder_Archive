#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);
    for(int i=0; i<N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    float ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            float d = pow(x.at(i)-x.at(j),2) + pow(y.at(i)-y.at(j),2);
            ans = max(ans,d);
        }
    }
    
    float result = sqrt(ans);
    cout << result << endl;
    
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec.at(i); 
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int sA=0;
    int sB=0;
    for(int i=0; i<N; i++){
        if( (i+1)%2 == 1){   //odd
            sA += vec.at(i);
        }else{
            sB += vec.at(i);
        }
    }

    cout << sA-sB << endl;
}

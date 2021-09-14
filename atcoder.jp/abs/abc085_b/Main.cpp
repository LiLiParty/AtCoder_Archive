#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N+1);
    for(int i=0; i<N; i++){
        cin >> vec.at(i); 
    }
    sort(vec.begin(), vec.end());

    int count = N;
    for(int i=0; i<N; i++){
        if( vec.at(i) == vec.at(i+1) ) count--;
    }

    cout << count << endl;
    
}

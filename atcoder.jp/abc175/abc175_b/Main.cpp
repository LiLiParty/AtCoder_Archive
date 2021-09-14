#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec.at(i); 
    }

    int counter = 0;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                int a = vec.at(i);
                int b = vec.at(j);
                int c = vec.at(k);
                if(a+b>c and a+c>b and b+c>a and a!=b and b!=c and c!=a) counter++;
            }
        }
    }

    cout << counter << endl;
    
}

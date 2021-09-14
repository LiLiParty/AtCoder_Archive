#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<string> list(N);
    vector<string> list_a(N);
    vector<string> list_b(N);

    for(int i=0; i<N; i++){
        cin >> list.at(i);
        list_a.at(i) = list.at(i);
        list_b.at(i) = list.at(i);

        for(int k=0; k<list.at(i).size(); k++){
            if(list.at(i).at(k) == '?'){
                list_a.at(i).at(k) = 'a';
                list_b.at(i).at(k) = 'z';
            }
            if(k==20) break;
        }
    }

    string T;
    cin >> T;
    int up=1;
    int down=N+1;

    for(int i=0; i<N; i++){
        if( list_a.at(i) > T){
            down--;
        }else if( list_b.at(i) < T ){
            up++;
        }
    }

    for(int i=0; i<=down-up;i++){
        if(i==down-up){
            cout << up+i << endl;
        }else{
            cout << up+i << " ";
        }
    }


}
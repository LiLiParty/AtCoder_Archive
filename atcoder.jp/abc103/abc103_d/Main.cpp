#include <bits/stdc++.h>
using namespace std;



int main() {
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> request(M); //終点、始点

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        request.at(i) = make_pair(b,a);
    }

    sort(request.begin(),request.end());

    int island_last_before = -1;
    int ans=0;

    for(int i=0; i<M; i++){
        if(island_last_before <= request.at(i).second){
            ans++;
            island_last_before = request.at(i).first;
        }
    }

    cout << ans << endl;


}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807


struct Edge{
    ll to;
    ll cost;
    ll k_time;
};

int flag = 1;

int main(){
    ll N,M,X,Y;
    cin >> N >> M >> X >> Y;
    //ノード:N, エッジ:M Start:X Goal:Y

    vector<ll> dist(100001,INF64);
    vector<vector<Edge>> G(100001);

    for(ll i=0; i<M; i++){
        ll a,b,t,k;
        cin >> a >> b >> t >> k;
        Edge E_1 = {a,t,k};
        Edge E_2 = {b,t,k};
        G.at(a).push_back(E_2);
        G.at(b).push_back(E_1);
    }

    priority_queue
    < pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
    //pair<距離,頂点番号>

    pq.push(make_pair(0,X));
    dist.at(X) = 0;

    while(!pq.empty()){
        ll now_dist = pq.top().first;
        ll v = pq.top().second;
        pq.pop();

        if(dist.at(v) < now_dist) continue;
        for(Edge e: G.at(v)){
            ll wait;
            ll num = now_dist % e.k_time;
            if(num == 0 or flag==1){
                wait = 0;
                flag = 0;
            }else{
                wait = e.k_time - num;
            }
            if(dist.at(v) + wait + e.cost<0) continue;

            if(dist.at(e.to) > dist.at(v) + wait + e.cost){
                dist.at(e.to) = dist.at(v) +  wait + e.cost;
                pq.push(make_pair(dist.at(e.to),e.to));
            }
        }


    }

    if(dist.at(Y) ==INF64 ){
        cout << -1 << endl;
    }else{
        cout << dist.at(Y) << endl; 
    }
    
}

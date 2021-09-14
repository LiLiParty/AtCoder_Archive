#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,M;
    cin >> N >> M; //頂点、辺数
    vector< pair<ll,ll> > A(N+1);
    A.at(0) = make_pair(0,0);

    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        A.at(i) = make_pair(a,i); //pair(価格、街番)
    }

    vector< vector<pair<ll,ll>> > G(N+1); //pair(行先,価格)
    for(int i=1; i<=M; i++){
        ll x,y;
        cin >> x >> y;
        //cout << "x: " << x << "y: " << y << endl; 
        pair<ll,ll> p = make_pair(y,A.at(y).first);
        G.at(x).push_back(p);
    }
    
    sort(A.begin(), A.end());
    
    /*
    for(int i=1; i<=N; i++){
        cout << "A.at(" << i << "):" << A.at(i).second << endl;
    }
    */
    
   
    vector<ll> seen(N+1,-1);
    queue< ll > q;

    ll ans=-3000000000;

    for(int i=1; i<=N; i++){
        //cout << A.at(i).second << "から出発:" <<endl;
        ll p_max = 0;
        ll p_min = A.at(i).first;
        ll v_f = A.at(i).second;
        if( seen.at(v_f) != -1 ) continue;
        q.push( v_f );
        bool flag=false;
        while(!q.empty()){
            ll v = q.front();
            q.pop();
            

            for( pair<ll,ll> nv: G.at(v)){
                if(seen.at( nv.first ) != -1) continue;
                //cout << nv.first << "を探索 値段は"<< nv.second << endl;  
                q.push(nv.first);
                p_max = max(p_max , nv.second);
                //cout << p_max << endl;
                seen.at(nv.first) = 1;
                flag = true;
            }
        }
        if(flag) ans = max(ans, p_max - p_min);
        
    }

    cout << ans << endl;
    
    

}

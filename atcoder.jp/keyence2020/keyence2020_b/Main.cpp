#include <bits/stdc++.h>
using namespace std;



int main() {
    int N;
    cin >> N;
    vector< pair<int,int> > robot(N); //pair<終点、始点>

    for(int i=0; i<N; i++){
        int x,l;
        cin >> x >> l;
        robot.at(i) = make_pair(x+l,x-l); 
    }
    sort(robot.begin(),robot.end());

    int robot_before = -1000000001;
    int ans=0;
    for(int i=0; i<N; i++){
        pair<int,int> p = robot.at(i);
        if( robot_before <= p.second ){
            ans++;
            robot_before = p.first;
        }    
    }

    cout << ans << endl;
}


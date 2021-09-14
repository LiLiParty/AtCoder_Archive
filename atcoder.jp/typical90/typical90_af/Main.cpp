#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
const ll mod = 998244353;

ll facctorial(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N+1,vector<int>(N+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
    int M; cin >> M;
    set<pp> Re;
    for(int i=0; i<M; i++){
        int X,Y;
        cin >> X >> Y;
        Re.insert(mk(X,Y));
        Re.insert(mk(Y,X));
    }

    ll ans = INF64;
    vector<int> P;
    for(int i=1; i<=N; i++) P.push_back(i);

    do{
        ll ans_c = 0;
        bool flag = false;
        for(int i=0; i<N; i++){
            ans_c += A[P[i]][i+1];
            if(i != N-1){
                if(Re.count(mk(P[i],P[i+1]))){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        ans = min(ans_c, ans);
    }while(next_permutation(P.begin(),P.end()));


    if(ans == INF64){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}

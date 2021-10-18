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

int main(){
    int N,M; cin >> N >> M;
    vector<ll> V(N+1,0); //入次数
    vector<vector<int>> G(N+1);
    for(int i=0; i<M; i++){
        int A,B; cin >> A >> B;
        V[B]++;
        G[A].push_back(B);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=N; i++){
        if(V[i] == 0) pq.push(i);
    }
    vector<int> Ans;
    while(!pq.empty()){
        int a = pq.top();
        //cout << "a: " << a << endl;
        Ans.push_back(a);
        pq.pop();
        for(int b: G[a]){
            V[b]--;
            if(V[b] == 0){
                pq.push(b);
                //cout << "b: " << b << endl;
            }
        }
    }

    if(Ans.size() != N){
        cout << -1 << endl;
    }else{
        for(int i=0; i<N; i++){
            cout << Ans[i] << " ";
        }
    }

}

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
//const ll mod = 998244353;



int main() {
    int N;
    cin >> N;
    vector<ll> A(N),B(N),C(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    for(int i=0; i<N; i++) cin >> C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    vector<ll> B_sum(N,0);
    for(int i=0; i<N; i++){
        int itr = C.end() - upper_bound(C.begin(),C.end(),B[i]);
        if(itr <= N) B_sum[i] = itr;
    }
    for(int i=N-2; i>=0; i--){
        B_sum[i] += B_sum[i+1];
    }
    
    ll ans = 0;
    for(int i=0; i<N; i++){
        int itr = upper_bound(B.begin(),B.end(),A[i]) - B.begin();
        //cout << itr << endl;
        if(itr < N) ans += B_sum[itr];
    }
    cout << ans;
}


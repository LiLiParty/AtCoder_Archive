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
    int N,K;
    cin >> N >> K;
    vector<int> V(N);

    for(int i=0; i<N; i++){
        cin >> V[i];
    }

    ll ans = 0;
    for(int k=0; k<=K; k++){
        if(k > N) break;
        for(int r=0; r<=k; r++){
            ll c_ans = 0;
            vector<int> juery;
            int l = k-r;
            for(int i=0; i<r; i++){
                c_ans += V[i];
                //cout << V[i] << " ";
                if(V[i] < 0) juery.push_back(V[i]);
            }
            for(int i=0; i<l; i++){
                c_ans += V[N-1 - i];
                //cout << V[N-1-i] << " ";
                if(V[N-1-i] < 0) juery.push_back(V[N-1-i]);
            }
            sort(juery.begin(),juery.end());
            int n = 0;
            for(int i=0; i<K-k; i++){
                if(juery.size() == n) break;
                c_ans -= juery[n];
                n++;
            }
            ans = max(c_ans,ans);
        }        
    }

    cout << ans << endl;
}

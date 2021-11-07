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
#include <cassert>
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
    int N; cin >> N;
    vector<pair<int,int>> City(N);
    for(int i=0; i<N; i++){
        int x,y; cin >> x >> y;
        City[i] = mk(x,y);
    }

    int ans = 0;

    set<pair<int,int>> M;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int a1 = City[i].first - City[j].first;
            int b1 = City[i].second - City[j].second;
            if(a1!=0 || b1!=0){
                int GCD = __gcd(abs(a1),abs(b1));
                a1 /= GCD;
                b1 /= GCD;
            }
            pair<int,int> m1 = mk(a1,b1);
            if(!M.count(m1)){
                ans ++;
                M.insert(m1);
            }

            int a2 = City[j].first - City[i].first;
            int b2 = City[j].second - City[i].second;
            if(a2!=0 || b2!=0){
                int GCD = __gcd(abs(a2),abs(b2));
                a2 /= GCD;
                b2 /= GCD;
            }
            pair<int,int> m2 = mk(a2,b2);
            if(!M.count(m2)){
                ans ++;
                M.insert(m2);
            }
        }
    }

    cout << ans << endl;
}

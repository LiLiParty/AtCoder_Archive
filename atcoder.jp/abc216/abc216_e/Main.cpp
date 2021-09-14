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
    ll N,K;
    cin >> N >> K;

    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    ll ans = 0;
    for(int i=0; i<N; i++){
        ll count;
        if(i!=N-1){
            count = (i+1) * (A[i] - A[i+1]);
        }else{
            count = (i+1) * (A[i] - 0);
        }
        //cout << "count: " << count << " ";
        if(K >= count){
            ans += (i+1) * count/(i+1) * (A[i] + A[i] - count/(i+1) + 1)/2;
            //cout << "add: " << (i+1) * count/(i+1) * (A[i] + A[i] - count/(i+1) + 1)/2 << " "; 
            K -= count;
            //cout << "ans:" << ans << endl;
        }else{
            int n = K / (i+1);
            ans += n * ( 2 * A[i]*(i+1) - (n-1)*(i+1)) / 2;
            int r = K % (i+1);
            ans += (A[i] - n) * r;
            //cout << "add: " << n * ( 2 * A[i]*(i-1) - (n-1)*(i-1)) / 2 + (A[i] - n) * r << " ";
            //cout << "ans:" << ans << endl;
            break;
        }
    }

    cout << ans << endl;

}

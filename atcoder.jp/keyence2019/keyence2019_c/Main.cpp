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
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];

    vector<ll> diff(N);
    ll num = 0;
    ll sub = 0;
    for(int i=0; i<N; i++){
        diff[i] = B[i] - A[i];
        num += diff[i];
        if(diff[i] > 0){
            sub += diff[i];
        }
    }
    //cout << sub << endl;
    if(num > 0){
        cout << -1 << endl;
        return 0;
    }
    sort(diff.begin(),diff.end());

    vector<ll> pre_diff = diff;

    //cout << sub << endl;
    for(int i=0; i<N; i++){
        if(sub != 0 && diff[i] < 0){
            if(abs(diff[i]) <= sub){
                sub += diff[i];
                diff[i] = 0;
            }else{
                diff[i] = diff[i] + sub;
                sub = 0;
            }   
        }
        if(diff[i] > 0){
            diff[i] = 0;
        }
        //cout << "sub: " << sub << endl;
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        if(pre_diff[i] != diff[i]) ans++;
        //cout << diff[i] << " ";
        //cout << pre_diff[i] << endl;
    }
    

    cout << ans << endl;

}
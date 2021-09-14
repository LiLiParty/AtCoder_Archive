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
    map<char,char> M1,M2;
    for(int i=0; i<10; i++){
        char num;
        cin >> num;
        
        M1[num] = i + '0';
        M2[ i +'0'] = num;
        
    }

    int N; cin >> N;
    vector<int>  A(N);
    for(int i=0; i<N; i++){
        string num;
        cin >> num;
        
        for(int j=0; j<(int)num.size(); j++){
            num[j] = M1[num[j]];
        }
        A[i] = stoi(num);
        
    }

    sort(A.begin(),A.end());
    for(int i=0; i<N; i++){
        string As = to_string(A[i]);
        for(int j=0; j < (int)As.size(); j++){
            As[j] = M2[As[j]];
        }
        cout << As << endl;
    }
    
}

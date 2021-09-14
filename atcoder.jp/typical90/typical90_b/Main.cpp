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
    int N;
    cin >> N;
    vector<string> canS;
    for(int bit=0; bit< (1<<N); bit++){
        string S;
        for(int i=0; i<N; i++){
            if( bit & (1<<i) ){
                S.push_back('(');
            }else{
                S.push_back(')');
            }
        }
        canS.push_back(S);
    }
    
    vector<string> S;
    for(int i=0; i<canS.size(); i++){
        int a=0,b=0;
        bool flag = false;
        for(int j=0; j<N; j++){
            if(canS[i][j] == '(') a++;
            else b++;
            if(a-b < 0){
                flag = true;
                break;
            }
        }
        if(flag) continue;
        if(a == b) S.push_back(canS[i]);
    }
    
    sort(S.begin(),S.end());
    for(int i=0; i<S.size(); i++){
        cout << S[i] << endl;
    }
    


}

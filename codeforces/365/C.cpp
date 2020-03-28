#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// using namespace __gnu_pbds; 

typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)  
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(ll i=b;i>=a;i--)
#define     debug(x)         cout<< '>'<<#x<<" : "<<x<<"\n";
#define     debug2(x,y)      cout<< '>'<<#x<<" : "<<x<<" | "; cout<< '>'<<#y<<" : "<<y<<"\n";
#define     debug3(x,y,z)    cout<< '>'<<#x<<" : "<<x<<" | "; cout<< '>'<<#y<<" : "<<y<<" | ";cout<< '>'<<#z<<" : "<<z<<"\n";
#define     umap             unordered_map
#define     uset             unordered_set
#define     lb               lower_bound
#define     ub               upper_bound
#define     mp               make_pair
#define     in               insert
#define     s                second
#define     f                first
#define     nn               cout<<"\n"
#define     pb               push_back
#define     testcase         int t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             INT_MAX
#define     minv             INT_MIN
#define     MOD              1000000007
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define     mem(a)           memset((a),0,sizeof(a));
#define     ordered_set      tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define     all(x)           x.begin(),x.end()

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

signed main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    ll a;
    cin >> a;
    string str;
    cin >> str;
    umap<ld,ll,custom_hash> sumcnt;
    vector<ll> psum(str.size());
    psum[0] = str[0]-'0';
    FOR(i,1,str.size()){
        psum[i] = psum[i-1] + (str[i]-'0');
    }
    FOR(i,0,str.size()){
        FOR(j,i,str.size()){
            ld lsum = psum[j]-psum[i]+(str[i]-'0');
            if(sumcnt.find(lsum) == sumcnt.end()) sumcnt[lsum] = 1;
            else sumcnt[lsum]++;
        }
    }
    ll ans = 0;
    if(a == 0){
        if(sumcnt.find(0) == sumcnt.end()){
            cout << 0 << "\n";
            return 0;
        }else{
            cout << sumcnt[0]*(str.size())*(str.size()+1) - sumcnt[0] -(sumcnt[0]*(sumcnt[0]-1)) << "\n";
            return 0; 
        }
    }
    for(auto itr : sumcnt){
        ll sum = itr.f;
        ld isum = (ld)a/(ld)sum;
        if(sum <= a && sumcnt.find(isum) != sumcnt.end()){
            ans += 1ll*((itr.s) * (sumcnt[isum]));
        }
    }
    cout << ans << "\n";
    return 0;
}



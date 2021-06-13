#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(ll i=b;i>=a;i--)
#define     debug(x)         cout<< '>'<<#x<<" : "<<x<<"\n";
#define     debug2(x,y)      cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";
#define     debug3(x,y,z)    cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";cout<< '>'<<#z<<" : "<<z<<"\n";
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
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define endl '\n'         
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  
 
vector<char> answ;

unordered_map<char,vector<char>> graph;

bool flg=true;

void top_sort(char curr,char parent,unordered_set<char>& vst,unordered_set<char>& vst1)
{
    
    vst.insert(curr);
    for(auto u:graph[curr])
    {
        if(vst.count(u)==1)
        {
            flg=false;
        }
        else if(vst1.count(u)==0)
        {
            top_sort(u,curr,vst,vst1);
        }
       
    }
    vst.erase(curr);
    vst1.insert(curr);
    answ.pb(curr);
}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<string> inp(n);
        FOR(i,0,n) cin>>inp[i];
        FOR(i,0,n-1)
        {
            ll a=0,b=0;
            while (a<inp[i].size() && b<inp[i+1].size() && inp[i][a]==inp[i+1][b])
            {
                /* code */
                a++;
                b++;
            }

            if(a!=inp[i].size())
            {
                // cout<<inp[i+1][b]<<" "<<inp[i][a]<<endl;
                graph[inp[i+1][b]].pb(inp[i][a]);

            }
             if(b==inp[i+1].size())
            {
                flg=false;
            }
        }
        unordered_set<char> vst;
        unordered_set<char> vst1;

        for(char i='a';i<='z';i++)
        {
            if(vst1.count(i)==0)
                top_sort(i,'*',vst,vst1);
            
        }
        
        if(!flg)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {

            for(int i = 0 ; i <answ.size();i++)
            {
                cout<<answ[i];
            }
            cout<<endl;
        
        }
        
    }
    return 0;
}

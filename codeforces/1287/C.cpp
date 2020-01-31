#include<bits/stdc++.h>

using namespace std;

typedef     long long        ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(ll i=a;i<=b;i++)
#define     FORD(i,b,a)      for(ll i=b;i>a;i--)
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
#define     testcase         ll t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             ll_MAX
#define     minv             ll_MIN
#define     MOD              1000000007
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
ll nCrModpDP(ll n, ll r) 
{ 
    
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    { 
        
        for (ll j = min(i, r); j > 0; j--) 
  
            
            C[j] = (C[j] + C[j-1])%MOD; 
    } 
    return C[r]; 
} 
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
ll ntopowermandMod(ll n,ll m,ll mod_v)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowermandMod(n,m/2,mod_v);
        val=val%mod_v;
        val=val*val;
        val=val%mod_v;
        if(m%2==1)
        {
        val=val*n;
        val=val%mod_v;
        }
        return val;

    }
    
}
ll ntopowerm(ll n,ll m)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowerm(n,m/2);
        val=val*val;
        if(m%2==1)
        {
        val=val*n;
        }
        return val;

    }
    
}
template<class T> void dispvector(vector<T> v){for(ll i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, ll n){for(ll i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> ll sizeofarr(T *v){return sizeof(v)/sizeof(T);}
ll n;
bool mycmp(pair<ll,ll>a,pair<ll,ll>b)
{
     if(abs(a.first-a.second)!=abs(b.first-b.second))
   return abs(a.first-a.second)<abs(b.first-b.second);
 
    else 
        {
            int len1=max(n-1-a.first,a.second);
            int len2=max(n-1-b.first,b.second);
            return len1<len2;
        }
}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    ll ans=0;
    cin>>n;
    
    ll arr[n];
    
    bool done[n+1];
    ll prev=-1;
    vector<ll> one_t,two_t,mixed_t,priority_1,priority_2;
    ll prev_idx=-1;
    ll mod_one=0,mod_two=0;
    for(ll i = 0 ; i <n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp==0)
        {
            arr[i]=-1;
        }
        else
        {
        arr[i]=temp%2;
        if(arr[i]==1)
        {
            mod_one++;
        }
        else
        {
            mod_two++;
        }
        
        if(prev==-1)
        {
            arr[i]==1?priority_1.pb(i-prev_idx-1):priority_2.pb(i-prev_idx-1);
            
        }
        else
        {
            if(prev==arr[i] && prev==1)
            {
                // cout<<i<<endl;
                one_t.pb(i-prev_idx-1);                
            }
            else if(prev==arr[i] &&prev==0)
            {
                two_t.pb(i-prev_idx-1);
            }
            else if(prev!=arr[i])
            {
                
                mixed_t.pb(i-prev_idx-1);
            }
            
            
        }
        prev=arr[i];              
        prev_idx=i;

        }
        
        done[i+1]=false;
    }
    if(prev_idx!=n-1)
    {
            prev==1?priority_1.pb(n-prev_idx-1):priority_2.pb(n-prev_idx-1);       
        
    }
    // debug(priority_2.size());
    if(one_t.size()+two_t.size()+mixed_t.size()+priority_1.size()+priority_2.size()<=1)
    {
        cout<<min(n-1,(ll)1)<<endl;
        return 0;
    }
    
    ll one_left=((n+1)/2)-mod_one;
    ll zer_left=(n/2)-mod_two;
    sort(one_t.begin(),one_t.end());
    sort(two_t.begin(),two_t.end());
    sort(mixed_t.begin(),mixed_t.end());
    sort(priority_1.begin(),priority_1.end());
    sort(priority_2.begin(),priority_2.end());

    // dispvector<ll>(one_t);
    // dispvector<ll>(two_t);
    // dispvector<ll>(mixed_t);

    // debug2(one_left,zer_left);

    for(int i = 0 ; i <one_t.size();i++)
    {
        if(one_left>=one_t[i])
        {
            one_left-=one_t[i];
        }
        else
        {
            
            ans+=2;
        }
    // debug2(one_left,zer_left);

        
    }
    // debug(ans);
    

    for(int i = 0 ; i <two_t.size();i++)
    {
        if(zer_left>=two_t[i])
        {
            zer_left-=two_t[i];
        }
        else
        {
            
            ans+=2;
        }
    // debug2(one_left,zer_left);

        
    }
    // debug(ans);


    if(priority_1.size()>0)
    {
        for(int i =  0 ; i <priority_1.size();i++)
        {
            if(priority_1[i]<=one_left)
            {
                one_left-=priority_1[i];
            }
            else
            {
                ans++;
            }
    // debug2(one_left,zer_left);

            
        }
    }
    // debug(ans);

    if(priority_2.size()>0)
    {
        for(int i =  0 ; i <priority_2.size();i++)
        {
            if(priority_2[i]<=zer_left)
            {
                zer_left-=priority_2[i];
            }
            else
            {
                ans++;
            }
    // debug2(one_left,zer_left);

            
        }
    }

    // debug(ans);
    for(int i = 0 ; i <mixed_t.size();i++)
    {
        if(mixed_t[i]>=0)
        {
            ans++;
        }
    }
    // cout<<mixed_t.size()<<endl;

    // ans+=mixed_t.size();
    cout<<ans<<endl; 


    
    
   
    

   
    return 0;
}
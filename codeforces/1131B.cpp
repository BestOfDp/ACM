#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    ll n;
    cin>>n;
    ll ans=1,a=0,b=0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(x==a&&y==b) continue;
        if(a>b){
            if(x>y){if(y>=a) ans+=y-a+1;}
            else ans+=x-a+1;
        }
        else if(a<b){
            if(x<y){if(x>=b) ans+=x-b+1;}
            else ans+=y-b+1;
        }
        else if(a==b){
            ans+=min(x,y)-a;
        }
        a=x,b=y;
    }
    cout<<ans<<endl;
}

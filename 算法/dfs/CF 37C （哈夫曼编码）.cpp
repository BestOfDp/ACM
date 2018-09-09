#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL ll_INF = 0x3f3f3f3f3f3f3f3f;//4e18 ~= 2^62
const int N =1000 + 10;
const LL mod = 1e9+7;

int n, tot=0, flag=0;

struct S
{
    int len, ind;
    string s;
}p[N];


bool cmp(const S a, const S b)
{
    return a.len<b.len;
}


bool cmp2(const S a, const S b)
{
    return a.ind<b.ind;
}


void DFS(int x, string s)
{
	//cout << s <<endl; 
    if(x==p[tot].len){
        p[tot++].s = s;
        if(tot==n) flag=1;
        return;
    }
    DFS(x+1, s+'0');
    if(tot==n) return;
    DFS(x+1, s+'1');
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &p[i].len);
        p[i].ind=i;
        p[i].s="";
    }
    sort(p, p+n, cmp);
    DFS(0, "");
    if(flag==0) { printf("NO\n"); return 0; }
    sort(p, p+n, cmp2);
    puts("YES");
    for(int i=0; i<n; i++){
        cout<<p[i].s<<endl;
    }
}

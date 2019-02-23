#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char op;
	int a,b;
	int current_a = -1;
	int current_b = -1;
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c",&op);
		scanf("%d %d",&a,&b);
		if(b<a) swap(a,b);
		if(op=='+'){
			current_a = max(current_a,a);
			current_b = max(current_b,b);
		}else{
			if(current_a <= a && current_b <= b){
				printf("YES\n");
			}else printf("NO\n");
		}
	}
}

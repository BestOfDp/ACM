#include<bits/stdc++.h>
using namespace std;
int next[100];
//传入模式串 
void gen_next(string s){
	next[0]=0;
	next[1]=0;
	int k=0; 
	for(int i=1;i<s.size();i++){
		while(k>0 && s[k]!=s[i]) k = next[k];
		if(s[k]==s[i]) k++;
		next[i+1]=k; 
	}
	next[0]=-1;
}

int kmp(string s, string p)
{
	int lens=s.size(); //主字符串 
	int lenp=p.size(); //模式字符串 
	int i=0,j=0;
	while(i<lens && j<lenp){
		//因为在得到next数组的时候，最后把next[0] = -1
		//所以j==-1代表当前无意义，重新匹配 
		if( j==-1 || s[i]==p[j]){
			i++;
			j++;
		}else j=next[j];
	}
	if(j==lenp) return i-j;
	else return -1;
}

int main()
{
	string s,p;
	   // 主字符串s ，模式串p  
	cin >> s >> p;
	gen_next(p);
	cout << kmp(s,p) << endl;
} 

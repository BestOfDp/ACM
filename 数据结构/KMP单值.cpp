#include<bits/stdc++.h>
using namespace std;
int next[100];
//����ģʽ�� 
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
	int lens=s.size(); //���ַ��� 
	int lenp=p.size(); //ģʽ�ַ��� 
	int i=0,j=0;
	while(i<lens && j<lenp){
		//��Ϊ�ڵõ�next�����ʱ������next[0] = -1
		//����j==-1����ǰ�����壬����ƥ�� 
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
	   // ���ַ���s ��ģʽ��p  
	cin >> s >> p;
	gen_next(p);
	cout << kmp(s,p) << endl;
} 

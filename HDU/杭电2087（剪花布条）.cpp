#include<bits/stdc++.h>
using namespace std;
int nextval[1005];
int ans[1005];
int index;
void gen(string s){
	nextval[0]=0;
	nextval[1]=0;
	int k=0; 
	for(int i=1;i<s.size();i++){
		while(k>0 && s[k]!=s[i]) k = nextval[k];
		if(s[k]==s[i]) k++;
		nextval[i+1]=k; 
	}
	nextval[0]=-1;
}

void kmp(string s, string p)
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
		}else j=nextval[j];
		if(j==lenp){
			ans[index++]=i-j;
			//����
			j=nextval[j];
			i+=(p.size()-1);
		} 
	}
}

int main()
{
	string s,p;
	   // ���ַ���s ��ģʽ��p  
	while(cin >> s){
		index=0;
		memset(nextval,0,sizeof(nextval));
		if(s=="#") break;
		cin >> p;
		gen(p);
		kmp(s,p);
		cout << index << endl;	
	}
}

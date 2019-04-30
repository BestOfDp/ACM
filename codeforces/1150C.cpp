#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	cin >> num;
	int one=0;
	int two=0;
	for(int i=0;i<num;i++){
		int temp;
		cin >> temp;
		if(temp==1) one++;
		else two++;
	}
	if(two){
		cout << 2 << " ";
		two--;
		if(one){
			one--;
			cout << 1 << " "; 
		}
		for(int i=0;i<two;i++){
			cout << 2 << " "; 
		}
		for(int i=0;i<one;i++){
			cout << 1 << " ";
		}
	}else{
		for(int i=0;i<num;i++){
			cout << 1 << " ";
		}
	}
	
} 

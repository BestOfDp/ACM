#include<iostream>
using namespace std;
int main(){
    int f[10000]={2};
    int k=1;
    for(int i=3;i<100000;i++){
        int q=1;
        for(int j=0;j<k;j++)
        if(i%f[j]==0){q=0;break;}
        if(q){
            f[k++]=i;
        }
    }
    int n;
    while(cin>>n&&n!=0){
        int sum=0;
        for(int i=0,j=k-1;i<=j;){///一定不能用两层循环,否则超时,要从两边同时向中间靠
            if(f[i]+f[j]==n){
                i++;
                j--;
                sum++;
            }
            else if(f[i]+f[j]>n)j--;
            else i++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

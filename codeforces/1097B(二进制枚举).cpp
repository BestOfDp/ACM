#include <bits/stdc++.h>
using namespace std;
int a[18];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i = 0; i < (1<<n); i++) //��0��2^n-1��״̬
    {
    	int ans = 0;
        for(int j = 0; j < n; j++) //���������Ƶ�ÿһλ
        {
        	ans = (ans+360)%360;
            if(i & (1 << j))//�ж϶����Ƶ�jλ�Ƿ����
            {
                ans += a[j];
            }else{
            	ans -= a[j];
			}
        }
        if(ans==0){
        	cout << "YES" << endl;
        	return 0;
		}
    }
    cout << "NO" << endl;
}

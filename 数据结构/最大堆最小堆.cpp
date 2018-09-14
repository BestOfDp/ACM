#include<bits/stdc++.h>
using namespace std;
int maxn = 1e9;
// ��Žڵ� 
vector<int>v;
int number = 10; // ��ʼ�������Ľڵ���� 
bool is_small_heap = false; // �жϵ�ǰ�ǲ��� ��С�� 
void get_random_tree(){
	srand((int)time(NULL));
	for(int i=0;i<number;i++){
		v.push_back(rand()%20); //����������ֲ����� 
	} 	
	cout << "���ɵ���ȫ������Ϊ: ";
	for(int i=0;i<v.size();i++) cout << " " << v[i];
	cout << endl;
}
// ��������� ���� �ڵ�� 
void swap_node(int i,int node_count,int leaf_count){
	int now_node = i;
	while(1){
		if(now_node>=node_count-leaf_count) break;
		int chl_left = 2*now_node + 1;
		int chl_right = chl_left + 1;
		int val_left = v[chl_left];
		int val_right;
		if(chl_right>=v.size()) val_right = maxn; // ���ܻ����ֻ����ڵ㣬û���ҽڵ� 
		else val_right=v[chl_right];
		if(v[now_node] > min(val_right,val_left)){
			now_node = chl_left;
			if(val_right < val_left) now_node++;
		}else break;
	}
	swap(v[i],v[now_node]);
	// �ٴε��ã���Ϊ ��Ҫ�жϽ�����Ľڵ� �ܷ�����³�
	// ���忴����������ͼ 
	if (i!=now_node) swap_node(now_node,node_count,leaf_count);
}
void generate_small_heap(){
	int node_count = v.size(); //�ڵ���� 
	int leaf_count = (node_count+1)/2 ; // Ҷ�ӽڵ�
	for(int i=node_count-leaf_count-1;i>=0;i--){
		// �����һ����Ҷ�ӽڵ㿪ʼ���� 
		swap_node(i,node_count,leaf_count);
	}
	is_small_heap = true;
	cout << "���ɵ���С��Ϊ:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

// ����ڵ㣬���¶���Ѱ�ң����� 
void insert_node(int new_node){
	v.push_back(new_node);
	int father_node; //���׽ڵ��λ��
	int now_index=v.size()-1; //Ŀǰ����Ľڵ����ڵ�λ�� 
	while(1){
		father_node = (now_index-1)/2;
		if(new_node < v[father_node]){
			swap(v[now_index],v[father_node]); 
			now_index= father_node;
		}else break; 
	}
	cout << "���ɵ���С��Ϊ:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

void delete_node(int node){
	swap(v[node],v[v.size()-1]); // ���һ���ڵ����Ҫɾ���Ľڵ㻻λ 
	v.pop_back(); // �Ƴ����һ���ڵ�
	int now_node = node;
	while(1){
		if(now_node >= v.size() - ( v.size()+1)/2  ) break; //��Ҷ�ӽڵ��˵�������� 
		int left = now_node * 2 + 1;
		int right = now_node * 2 + 2;
		int val_left = v[left];
		int val_right;
		if(right >= v.size()) val_right=maxn;
		else val_right = v[right];
		if(v[now_node] > min(val_left,val_right)){
			int change = left;
			if(val_left > val_right) change=left+1;
			swap(v[now_node],v[change]);
			now_node = change;
		}else break;
	}	
	cout << "���ɵ���С��Ϊ:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}
int main()
{
	get_random_tree();
	cout << "��ѡ�����:" << endl; 
	cout << "1:������С��" << endl; 
	cout << "2:����ڵ�" << endl; 
	cout << "3:ɾ���ڵ�" << endl; 
	int n;
	while(1){
		cin >> n;
		switch(n){
			case 1:{
				generate_small_heap();
				break;
			};
			case 2:{
				if(is_small_heap == false){
					cout << "��������С��" << endl;
					break;
				}
				int new_node;
				cout << "������ӵĽڵ�" << endl; 
				cin >> new_node;
				insert_node(new_node);	
				break;
			};
			case 3:{
				if(is_small_heap == false){
					cout << "��������С��" << endl;
					break;
				}
				int node;
				cout << "����ɾ���Ľڵ�����[0 , number-1]" << endl; 
				cin >> node;
				delete_node(node);
				break;
			} 
		}	
	}
} 

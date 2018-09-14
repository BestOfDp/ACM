#include<bits/stdc++.h>
using namespace std;
int maxn = 1e9;
// 存放节点 
vector<int>v;
int number = 10; // 初始化的树的节点个数 
bool is_small_heap = false; // 判断当前是不是 最小堆 
void get_random_tree(){
	srand((int)time(NULL));
	for(int i=0;i<number;i++){
		v.push_back(rand()%20); //随机生成数字并插入 
	} 	
	cout << "生成的完全二叉树为: ";
	for(int i=0;i<v.size();i++) cout << " " << v[i];
	cout << endl;
}
// 这个函数是 交换 节点的 
void swap_node(int i,int node_count,int leaf_count){
	int now_node = i;
	while(1){
		if(now_node>=node_count-leaf_count) break;
		int chl_left = 2*now_node + 1;
		int chl_right = chl_left + 1;
		int val_left = v[chl_left];
		int val_right;
		if(chl_right>=v.size()) val_right = maxn; // 可能会出现只有左节点，没有右节点 
		else val_right=v[chl_right];
		if(v[now_node] > min(val_right,val_left)){
			now_node = chl_left;
			if(val_right < val_left) now_node++;
		}else break;
	}
	swap(v[i],v[now_node]);
	// 再次调用，因为 还要判断交换后的节点 能否继续下沉
	// 具体看倒数第三张图 
	if (i!=now_node) swap_node(now_node,node_count,leaf_count);
}
void generate_small_heap(){
	int node_count = v.size(); //节点个数 
	int leaf_count = (node_count+1)/2 ; // 叶子节点
	for(int i=node_count-leaf_count-1;i>=0;i--){
		// 从最后一个非叶子节点开始遍历 
		swap_node(i,node_count,leaf_count);
	}
	is_small_heap = true;
	cout << "生成的最小堆为:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

// 插入节点，自下而上寻找，交换 
void insert_node(int new_node){
	v.push_back(new_node);
	int father_node; //父亲节点的位置
	int now_index=v.size()-1; //目前插入的节点所在的位置 
	while(1){
		father_node = (now_index-1)/2;
		if(new_node < v[father_node]){
			swap(v[now_index],v[father_node]); 
			now_index= father_node;
		}else break; 
	}
	cout << "生成的最小堆为:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}

void delete_node(int node){
	swap(v[node],v[v.size()-1]); // 最后一个节点和需要删除的节点换位 
	v.pop_back(); // 移除最后一个节点
	int now_node = node;
	while(1){
		if(now_node >= v.size() - ( v.size()+1)/2  ) break; //是叶子节点就说明结束了 
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
	cout << "生成的最小堆为:" << endl; 
	for(int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}
	cout << endl;
}
int main()
{
	get_random_tree();
	cout << "请选择操作:" << endl; 
	cout << "1:生成最小堆" << endl; 
	cout << "2:插入节点" << endl; 
	cout << "3:删除节点" << endl; 
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
					cout << "先生成最小堆" << endl;
					break;
				}
				int new_node;
				cout << "输入添加的节点" << endl; 
				cin >> new_node;
				insert_node(new_node);	
				break;
			};
			case 3:{
				if(is_small_heap == false){
					cout << "先生成最小堆" << endl;
					break;
				}
				int node;
				cout << "输入删除的节点坐标[0 , number-1]" << endl; 
				cin >> node;
				delete_node(node);
				break;
			} 
		}	
	}
} 

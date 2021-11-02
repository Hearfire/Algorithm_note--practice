/*PTA1053
每个结点有重量，找出特定重量的一条路
*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 100;
int n, m, s;
int path[MAXN];

struct Node {
	int weight;
	vector<int> child;//输出时要降序排列，不妨此时就将子节点排序，从大到小
}node[MAXN];

bool cmp(int a, int b) {//从大到小
	return node[a].weight>node[b].weight;
}

void DFS(int index, int num, int sum) {//当前结点为index，当前路径已有num个结点，重量为sum
	if (sum > s) {
		return;
	}
	else if (sum == s) {
		if (node[index].child.empty()) {//已找到一条完整路径，输出他
			for (int i = 0; i < num-1; i++) {
				printf("%d ", node[path[i]].weight);
			}
			printf("%d\n", node[path[num-1]].weight);
			return;
		}
		else {
			return;
		}
	}
	else {
		for (int i = 0; i < node[index].child.size(); i++) {
			int child= node[index].child[i];
			path[num] = child;
			DFS(child, num + 1, sum + node[child].weight);
		}
		return;
	}
}

int main() {
	scanf_s("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &node[i].weight);
	}

	int tempi,k, childi;
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d", &tempi, &k);
		for (int j = 0; j < k; j++) {
			scanf_s("%d", &childi);
			node[tempi].child.push_back(childi);
		}
		//sort(node[i].child.begin(), node[i].child.end(), cmp);//孩子从大到小排列
		//这里出错，测试点2过不了
		sort(node[tempi].child.begin(), node[tempi].child.end(), cmp);
	}

	path[0] = 0;//path从0结点开始
	DFS(0, 1, node[0].weight);

	return 0;
}
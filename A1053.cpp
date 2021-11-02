/*PTA1053
ÿ��������������ҳ��ض�������һ��·
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
	vector<int> child;//���ʱҪ�������У�������ʱ�ͽ��ӽڵ����򣬴Ӵ�С
}node[MAXN];

bool cmp(int a, int b) {//�Ӵ�С
	return node[a].weight>node[b].weight;
}

void DFS(int index, int num, int sum) {//��ǰ���Ϊindex����ǰ·������num����㣬����Ϊsum
	if (sum > s) {
		return;
	}
	else if (sum == s) {
		if (node[index].child.empty()) {//���ҵ�һ������·���������
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
		//sort(node[i].child.begin(), node[i].child.end(), cmp);//���ӴӴ�С����
		//����������Ե�2������
		sort(node[tempi].child.begin(), node[tempi].child.end(), cmp);
	}

	path[0] = 0;//path��0��㿪ʼ
	DFS(0, 1, node[0].weight);

	return 0;
}
/* PAT A1052 Linked List Sorting
给出N个结点的地址、数据、指针，给出链表首地址与结点总个数
递增排序后输出
思路：
  用静态链表解题，建立数组，用数组下标来模拟地址
  排序后，有效结点（有数据）排在前面，递增序列，无效结点在后面
注意：
  有的地址存贮了数据，但并不在链表中
  */
//建的数组应该还是写node而不是memory，排序后就不是原本的内存了，有一点误会

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100020;//结点不超过10^5，开辟这么多内存就可

//address、next存放的时模拟地址的数组下标
struct node {
	int address, data, next;//address:自己的地址，next：下一个结点的地址，-1表示NULL
	bool flag;//flag为true表示有数据，便于排序
}memory[maxn];

bool cmp(node a, node b) {
	if (a.flag==false || b.flag==false) {
		return a.flag > b.flag;//无效结点放在后面
	}
	else {//a、b都有效
		return a.data < b.data;
	}
}

int main() {
	//初始化
	for (int i = 0; i < maxn; i++) {
		memory[i].flag = false;
	}

	int n,head,temp;
	scanf_s("%d %d", &n, &head);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		scanf_s("%d %d", &memory[temp].data, &memory[temp].next);
		memory[temp].address = temp;
	}

	int p=head,count=0;
	//梳理链表，计算有效结点个数
	while (p != -1) {
		count++;
		memory[p].flag = true;
		p = memory[p].next;
	}

	if (count == 0) {//特殊情况，无结点
		printf("0 -1");
		return 0;
	}

	sort(memory, memory + maxn, cmp);
	printf("%d %05d\n", count ,memory[0].address);
	for (int i = 0; i < count; i++) {
		//if (memory[i].next == -1) {//排序后，原最后结点不一定是最后结点
		if (i==count-1) {
			printf("%05d %d -1", memory[i].address,memory[i].data);
		}
		else {
			printf("%05d %d %05d\n", memory[i].address, memory[i].data, memory[i + 1].address);
		}
	}


	return 0;
}
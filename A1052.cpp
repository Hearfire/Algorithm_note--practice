/* PAT A1052 Linked List Sorting
����N�����ĵ�ַ�����ݡ�ָ�룬���������׵�ַ�����ܸ���
������������
˼·��
  �þ�̬������⣬�������飬�������±���ģ���ַ
  �������Ч��㣨�����ݣ�����ǰ�棬�������У���Ч����ں���
ע�⣺
  �еĵ�ַ���������ݣ���������������
  */
//��������Ӧ�û���дnode������memory�������Ͳ���ԭ�����ڴ��ˣ���һ�����

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100020;//��㲻����10^5��������ô���ڴ�Ϳ�

//address��next��ŵ�ʱģ���ַ�������±�
struct node {
	int address, data, next;//address:�Լ��ĵ�ַ��next����һ�����ĵ�ַ��-1��ʾNULL
	bool flag;//flagΪtrue��ʾ�����ݣ���������
}memory[maxn];

bool cmp(node a, node b) {
	if (a.flag==false || b.flag==false) {
		return a.flag > b.flag;//��Ч�����ں���
	}
	else {//a��b����Ч
		return a.data < b.data;
	}
}

int main() {
	//��ʼ��
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
	//��������������Ч������
	while (p != -1) {
		count++;
		memory[p].flag = true;
		p = memory[p].next;
	}

	if (count == 0) {//����������޽��
		printf("0 -1");
		return 0;
	}

	sort(memory, memory + maxn, cmp);
	printf("%d %05d\n", count ,memory[0].address);
	for (int i = 0; i < count; i++) {
		//if (memory[i].next == -1) {//�����ԭ����㲻һ���������
		if (i==count-1) {
			printf("%05d %d -1", memory[i].address,memory[i].data);
		}
		else {
			printf("%05d %d %05d\n", memory[i].address, memory[i].data, memory[i + 1].address);
		}
	}


	return 0;
}
//7-1 File Transfer (18 分)
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 10000;
int set[maxn];//union by size

int findroot(int a) {//找到根，根相同则在一个集合
	while (set[a] > 0) {
		a = set[a];
	}
	return a;
}
void unionset(int a, int b) {
	int roota = findroot(a);
	int rootb = findroot(b);
	if (roota == rootb) {//已经在一个集合
		return;
	}
	if (set[roota] < set[rootb]) {//union by size
		set[roota] += set[rootb];
		set[rootb] = roota;
	}
	else {
		set[rootb] += set[roota];
		set[roota] = rootb;
	}
	return;
}


int main() {
	int n, a, b;
	scanf("%d", &n);
	getchar();
	memset(set, -1, sizeof(set));


	char ch;
	while ((ch = getchar()) != 'S') {
		scanf("%d%d", &a, &b);
		getchar();

		switch (ch) {
		case 'C':
			if (findroot(a - 1) == findroot(b - 1)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		case 'I':
			unionset(a - 1, b - 1);
			break;
		default:
			printf("wrong");
			break;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (set[i] < 0) {
			count++;
		}
	}
	if (count >= 2) {
		printf("There are %d components.\n", count);
	}
	else {
		printf("The network is connected.\n");
	}

	return 0;
}
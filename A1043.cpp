/*PTA A1043
是否为二叉树
*/
#include<cstdio>
#include<vector>
using namespace std;

vector<int> origin, pre, post, prem, postm;

struct node {
	int data;
	node* left,*right;
};

void insert(node* &root, int data) {
	if (root == NULL) {//到达要插入的地方
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (data < root->data) {//插在左子树
		insert(root->left, data);
	}
	else {
		insert(root->right, data);
	}
}
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}
void preorderm(node*root) {
	if (root == NULL) {
		return;
	}
	prem.push_back(root->data);
	preorderm(root->right);
	preorderm(root->left);
}
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->data);
}
void postorderm(node*root) {
	if (root == NULL) {
		return;
	}
	postorderm(root->right);
	postorderm(root->left);	
	postm.push_back(root->data);
}


int main() {
	int n,temp;
	node*root = NULL;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		origin.push_back(temp);
		insert(root, temp);
	}
	preorder(root);
	preorderm(root);
	postorder(root);
	postorderm(root);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i != post.size() - 1) {
				printf(" ");
			}
		}
	}
	else if (origin == prem) {
		printf("YES\n");
		for (int i = 0; i < postm.size(); i++) {
			printf("%d", postm[i]);
			if (i != postm.size() - 1) {
				printf(" ");
			}
		}
	}
	else {

		printf("NO\n");
	}


	return 0;
}
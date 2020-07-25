#include <iostream>
#include <map>
using namespace std;
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};
void bottomView(Node *root,int dist, int level, auto &map)
{
	if (root == nullptr)
		return;
    if (level>map[dist].second)
		map[dist] = {root->key,level};
  
	bottomView(root->left,dist-1, level + 1, map);
	bottomView(root->right,dist+1, level + 1, map);
}


int PrintView(Node *root)
{   map<int,pair<int, int>> map;
	bottomView(root, 0,0, map);
	for (auto it :map)
	    cout<<it.second.first<<" ";
}


int main()
{
	Node* root = nullptr;
	
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	PrintView(root);

	return 0;
}

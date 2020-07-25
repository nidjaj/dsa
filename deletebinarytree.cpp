#include<iostream>
#include<queue>
using namespace std;
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	
	Node(int key)
	{
		this->key=key;
		this->left=nullptr;
		this->right=nullptr;	
	}	
};
void DeleteBinaryTree(Node * &root)
{
	if(root==nullptr)
	return;
	
	queue<Node *> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node *ptr=q.front();
		q.pop();
		
		if(ptr->left)
		q.push(ptr->left);
		
		if(ptr->right)
		q.push(ptr->right);
		
		ptr->left=ptr->right=nullptr;
		delete ptr;
		
	}
	root=NULL;
}
int main()
{
	Node *root1=nullptr;
	root1=new Node(15);
	root1->left=new Node(10);
	root1->right=new Node(20);
	root1->left->left=new Node(8);
	root1->left->right=new Node(12);
	root1->right->left=new Node(16);
	root1->right->right=new Node(25);
	
	DeleteBinaryTree(root1);	
}

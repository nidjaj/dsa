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
int Height(Node *root)
{
	if(root==nullptr)
	return 0;
	
	int height=0;
	queue<Node *> q;
	
	q.push(root);
	q.push(nullptr);
	
	while(!q.empty())
	{
		Node *ptr=q.front();
		q.pop();
		
		if(ptr==nullptr)
		{
			height++;
			if(q.size()!=0)
			q.push(nullptr);
		}
		else 
		{
			if(ptr->left)
			q.push(ptr->left);
			if(ptr->right)
			q.push(ptr->right);
		}
	}
	return height;
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
	
	cout<<Height(root1);
	
	
	
	
}

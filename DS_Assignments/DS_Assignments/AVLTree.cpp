#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node *right;
};
class BST {
	struct node *start;
public:
	BST();
	void insert(int);
	void deleteEle(int);
	void inorder();
	void preorder();
	void postorder();
	int findMax();
	int findMin();
	int height();
	int NLN();
	int NNLN();
	int B(node *);
	struct node *balance(struct node*);
	friend int findMax1(struct node *);
	friend int findMin1(struct node *);
	friend int height1(struct node *);
	friend int NLN1(struct node *);
	friend int NNLN1(struct node *);
	friend struct node* L_Rotation(node *);
	friend struct node* R_Rotation(node *);
	friend struct node* LR_Rotation(node *);
	friend struct node* RL_Rotation(node *);
	~BST();
	friend void printi(struct node *);
	friend void printpr(struct node *);
	friend void printpo(struct node *);
	friend void deleteNode(struct node *);
	friend struct node* inser(int ele, struct node *);
	friend struct node* deleteEl(int ele, struct node *);
	friend int FMax(struct node *);
};
BST::BST()
{
	start = NULL;
}
int BST::NLN()
{
	return NLN1(start);

}
int BST::NNLN()
{
	return NNLN1(start);
}
int BST::height()
{
	return height1(start);
}
int BST::findMax()
{
	return findMax1(start);
}
int BST::findMin()
{
	return findMin1(start);
}
int NLN1(struct node *cur)
{
	if (cur == NULL)
		return 0;
	if ((cur->left == NULL) && (cur->right == NULL))
		return 1;
	return(NLN1(cur->left) + NLN1(cur->right));
}
int NNLN1(struct node *cur)
{
	if (cur == NULL)
		return 0;
	if ((cur->left == NULL) && (cur->right == NULL))
		return 0;
	return(NNLN1(cur->left) + NNLN1(cur->right) + 1);
}
int findMin1(struct node *cur)
{
	if (cur != NULL)
	{
		while (cur->left != NULL)
			cur = cur->left;
		return cur->data;
	}
	return -1;
}
int findMax1(struct node *cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	return -1;
}
int height1(struct node *cur)
{
	if (cur == NULL)
		return -1;
	else
		return(std::max(height1(cur->left), height1(cur->right)) + 1);
}
void printi(struct node *cur)
{
	if (cur != NULL)
	{
		printi(cur->left);
		cout << cur->data << endl;
		printi(cur->right);
	}
}
void printpr(struct node *cur)
{
	if (cur != NULL)
	{
		cout << cur->data << endl;
		printpr(cur->left);
		printpr(cur->right);
	}
}
void printpo(struct node *cur)
{


	if (cur != NULL)
	{

		printpo(cur->left);
		printpo(cur->right);
		cout << cur->data << endl;
	}
}
void BST::inorder()
{

	if (start != NULL)
		printi(start);
}
void BST::preorder()
{
	if (start != NULL)
		printpr(start);
}
void BST::postorder()
{
	if (start != NULL)
		printpo(start);
}
void deleteNode(struct node *cur)
{
	if (cur != NULL)
	{
		deleteNode(cur->left);
		deleteNode(cur->right);
		delete cur;
	}
}
BST::~BST()
{
	if (start != NULL)
		deleteNode(start);
}
struct node* inser(int ele, struct node *cur)
{
	if (cur == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele < cur->data)
			cur->left = inser(ele, cur->left);
		else
			cur->right = inser(ele, cur->right);
		return cur;
	}

}
void BST::insert(int ele)
{
	start = inser(ele, start);
}
int FMax(struct node *cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	return -1;
}
struct node * deleteEl(int ele, struct node *cur)
{
	if (cur != NULL)
	{
		if (cur->data < ele)
			cur->right = deleteEl(ele, cur->right);
		else if (cur->data > ele)
			cur->left = deleteEl(ele, cur->left);
		else
		{
			if ((cur->left != NULL) && (cur->right != NULL))
			{
				cur->data = FMax(cur->left);
				cur->left = deleteEl(cur->data, cur->left);
			}
			else
			{
				struct node *temp;
				temp = cur;
				if (cur->left == NULL)
					cur = cur->right;
				else
					cur = cur->left;
				delete temp;
			}
		}
		return cur;
	}
	else
		return NULL;
}
void BST::deleteEle(int ele)
{
	start = deleteEl(ele, start);
}
struct node* L_Rotation(struct node *cur)
{
	struct node *temp = cur->right;
	cur->right = temp->left;
	temp->left = cur;
	return temp;
}
struct node* R_Rotation(struct node *cur)
{
	struct node *temp = cur->left;
	cur->left = temp->right;
	temp->right = cur;
	return temp;
}
struct node* RL_Rotation(struct node *cur)
{
	struct node *temp = cur->right;
	temp = R_Rotation(temp);
	cur->right = temp->left;
	temp->left = cur;
	return temp;
}
struct node* LR_Rotation(struct node *cur)
{
	struct node *temp = cur->left;
	temp = L_Rotation(temp);
	cur->left = temp->right;
	temp->right = cur;
	return temp;
}

int BST::B(struct node *cur)
{
	return (height1(cur->left) - height1(cur->right));
}
struct node *BST::balance(struct node *cur)
{
	if (B(cur) > 1)
	{
		if (B(cur->left) == 1)
			R_Rotation(cur);
		else
			LR_Rotation(cur);
	}
	if (B(cur->right) < -1)
	{
		if (B(cur->right) == 1)
			RL_Rotation(cur);
		else
			L_Rotation(cur);
	}
	return cur;
}
int main()
{
	BST bst;
	int c, ele;
	while (1)
	{
		cout << "Enter choice 1.insert 2.inorder 3.preorder 4.postorder 5.delete 6.height 7.findmax 8.findmin 9.leafs 10.non-leafs 11.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to insert\n";
			cin >> ele;
			bst.insert(ele);
			break;
		case 2:bst.inorder(); cout << "\n";
			break;
		case 3:bst.preorder(); cout << "\n";
			break;
		case 4:bst.postorder(); cout << "\n";
			break;
		case 5:cout << "enter ele to delete\n";
			cin >> ele;
			bst.deleteEle(ele);
			break;
		case 6:cout << "Height of bst : " << bst.height() << "\n";
			break;
		case 7:cout << "Maximum ele in tree : " << bst.findMax() << "\n";
			break;
		case 8:cout << "Minimum ele in tree : " << bst.findMin() << "\n";
			break;
		case 9:cout << "No of leafs : " << bst.NLN() << endl;
			break;
		case 10:cout << "No of non leaf nodes : " << bst.NNLN() << endl;
			break;
		}
		if (c == 11)
			break;
	}
	return 0;
}
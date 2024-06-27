#include <iostream>
#include <queue>


using namespace std;

class Node
{
public:
	int deger;
	Node* left;
	Node* right;

	Node(int deger)
	{
		this->deger = deger;
		left = NULL;
		right = NULL;
	}
};
class BinarySearchTree
{
public:
	Node* root;

	BinarySearchTree()
	{
		root = NULL;
	}
	~BinarySearchTree()
	{
		deleteAllNodes(root);
	
	}
	bool insertNode(int deger)
	{
		Node* node = new Node(deger);
		if (root == NULL)
		{
			root = node;
			return true;
		}
		Node* tmp = root;
		while (true)
		{
			if (node->deger == tmp->deger)
			{
				cout << " mukeerrer node eklenmeye calisiliyor!!!!!!!";
				return false;
			}

			if (node->deger < tmp->deger)
			{
				if (tmp->left == NULL)
				{
					tmp->left = node;
					return true;
				} 
					tmp = tmp->left;
			}
			else
			{
				if (tmp->right == NULL)
				{
					tmp->right = node;
					return true;
				}
					tmp = tmp->right;
			}
		}
	
	}
	void DFSPreOrderSearch(Node* node)
	{
		cout << node->deger << " , ";
		if (node->left)
		{
			DFSPreOrderSearch(node->left);
		}
		if (node->right)
		{
			DFSPreOrderSearch(node->right);

		}
		
	}
	Node* DFSPreOrderSearchNode(Node* node, int arananDeger)
	{
		if (node == NULL || node->deger == arananDeger)
		{
			return node;
		}

		if (arananDeger < node->deger)
		{
			return DFSPreOrderSearchNode(node->left, arananDeger);
		}
		else
		{
			return DFSPreOrderSearchNode(node->right, arananDeger);
		}

	}
	void deleteAllNodes(Node* node)
	{

		if (node == NULL)
			return;
		
			if (node->left)
			{
				deleteAllNodes(node->left);
			}
			if (node->right)
			{
				deleteAllNodes(node->right);

			}
			delete node;
		
	}
	void DFSPostOrderSearch(Node* node)
	{
	
		if (node->left)
		{
			DFSPostOrderSearch(node->left);
		}
		if (node->right)
		{
			DFSPostOrderSearch(node->right);

		}
		cout << node->deger << " , ";
	}
	void DFSInOrderSearch(Node* node)
	{

		if (node->left)
		{
			DFSInOrderSearch(node->left);
		}
			cout << node->deger << " , ";
		if (node->right)
		{
			DFSInOrderSearch(node->right);

		}
	
	}
	void BreadthFirstSearch()
	{
		queue<Node*> queue1;
		queue1.push(root);

		while (queue1.size()>0)
		{
			Node* node = queue1.front();
			queue1.pop();
			cout << node->deger << " , ";
			if (node->left)
			{
				queue1.push(node->left);
			}
			if (node->right)
			{
				queue1.push(node->right);
			}
		}

	}
};

int main()
{
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insertNode(52);
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);

	//cout << "son eklenen nodum: " << bst->root->left->left->left->deger << endl;

	/*bst->DFSPreOrderSearch(bst->root);
	Node*ptr= bst->DFSPreOrderSearchNode(bst->root, 30);
	if (ptr != NULL)
	{
		cout << "Aradiginiz sonuc bulundur: " << ptr->deger << endl;
	}
	else
	{
		cout << "Aradiginiz sonuc nst icinde mevcut degildir: "<< endl;
	}*/    
	bst->DFSPostOrderSearch(bst->root);
	cout << endl;
	bst->DFSInOrderSearch(bst->root);
	cout << endl;
	bst->BreadthFirstSearch();
	cout << endl;
	delete bst;
	return 0;
}


/*
dsf algoritmlar�nda recursive methotlar cagirilir yani methotlar aras�nda stack kurulur bir i�lem yaparken ba�ka methot �a��r�l�nca o methodun i�ini halleder sonra �a��r�ld�g� 
yerden kalan kodlar� yapar dfs(depth first search) methotlarda en sola iner sonra tek tek geri ��karak sag nodelar� kontrol etmesine denir

traversalda sat�r sat�r ilerler seviye seviye

dfs preorder da ilk ebebeynler yaz�l�r sonra cocuklar dfs post orderda ise ilk cocuklar�n�n hepsi yaz�l�r ondan sonra ebevenyler yaz�l�r ondan dolay� 
root post orderda en son yaz�l�r
breadth first search algroitmas� katman katman row row yazar traveller seklinde parent� yazar sol cocugunu varsa kuyruga ekler sonra sag kuyruga ekler son bu kuyruklar�n front eleman�n
sol sag cocuklar�na bakar kuyrukta node kalmayacaga kadar yazar










*/
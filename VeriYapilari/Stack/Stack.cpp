#include <iostream>

using namespace std;

class Node
{
	public:
		int deger;
		Node* next;
		Node(int deger)
		{
			this->deger = deger;
			next = NULL;
		}
};
class Stacks
{
private:
	Node* top;
	int count;

public:
	Stacks(int deger)
	{
		Node* node = new Node(deger);
		top = node;
		count = 1;
	}
	~Stacks()
	{
		Node* tmp = top;
		while (top!=NULL)
		{
			top= top->next;
			delete tmp;
			tmp = top;
			cout << "Node silindi" << endl;
		}
	}
	void print()
	{
		Node* tmp = top;
		while (tmp !=NULL)
		{
			cout << tmp->deger << endl;
			tmp = tmp->next;
		}
	}
	void printTop()
	{
		if (!isEmpty())
		{
			cout << "Top Deger: " << top->deger << endl;
		}
	}
	int getCount()
	{
		return count;
	}
	void push(int deger)
	{
		Node* node = new Node(deger);
	    node->next = top;
		top = node;
		count++;
	}
	int pop()
	{
		if (top == NULL)
		{
			cout << "bos stacte pop islemi yapilmaya calisiliyor!!!!!!!!";
				exit(1);
		}
		Node* tmp = top;
		int deger= top->deger;
		delete tmp;
		count--;
		return deger;
	}
	bool isEmpty()
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


};
int main()
{
	Stacks *stacks = new Stacks(24);
	stacks->push(20);
	stacks->push(30);




	delete stacks;
	return 0;
}


/*
if (top == NULL)
		{
			cout << "bos stacte pop islemi yapilmaya calisiliyor!!!!!!!!";
				exit(1);
		}
		if (count == 0)
			return -1; // INT_MIN         EXÝT YAPIP HATA MESAJI ÝLE DÝREKT CIKABÝLÝRSÝN -1 DEÐERÝ PROGRAMA AGÖRE DEGÝSÝKLÝK YAPABÝLÝR INT_MIN ÝLE END ÜÞÜK RAKAMI DA ÇAÐIRABÝLÝRSÝN



*/
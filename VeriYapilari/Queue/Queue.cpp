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
class Queues
{
public:
	Node* head;
	Node* tail;
	int count;
	Queues(int deger)
	{
		Node* node = new Node(deger);
		head = node;
		tail= node;
		count = 1;
	}
	~Queues()
	{
		Node* tmp = head;

		while (head != NULL)
		{
			head= head->next;
			delete tmp;
			tmp = head;

		}
	}

	void printAll()
	{
		Node* tmp = head;

		while (tmp!=NULL)
		{
			cout << tmp->deger <<", ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	int getHeadValue()
	{
		if (count != 0)
		{
			return head->deger;
		}
		else
		{
			return INT_MIN;
		}
	}
	int getTailValue()
	{
		if (count != 0)
		{
			return tail->deger;
		}
		else
		{
			return INT_MIN;
		}
	}
	int getCount()
	{
		if (count != 0)
		{
			return count;
		}
		else
		{
			return INT_MIN;
			cout << "sa";
		}
	}
	void enqueue(int deger)
	{
		Node* node = new Node(deger);
		if (count == 0)
		{
			head = node;
		}
		else
		{
			tail->next = node;
		}
		tail = node;
		count++;
	}
	int  Dequeue()
	{

		if (count == 0)
		{
			return INT_MIN;
		}
		Node* tmp = head;
		int deger = head->deger;
		if (count == 1)
		{
			head = NULL;
			tail= NULL;
		}
		else
		{
			head = head->next;
		}
		delete tmp;
		count--;
		return deger;
	}
	 
};


int main()
{
	Queues* queues = new Queues(10);
	 
	cout << "count: " << queues->getCount() << endl;
	cout << "head value : " << queues->getHeadValue() << endl;
	cout << "tail value: " << queues->getTailValue() << endl;
	queues->printAll();

	queues->enqueue(20);
	queues->enqueue(30);
	queues->enqueue(40);
	
	cout << "kuruktan cikarilan node: " << queues->Dequeue() << endl;
	cout << "count: " << queues->getCount() << endl;
	cout << "head value : " << queues->getHeadValue() << endl;
	cout << "tail value: " << queues->getTailValue() << endl;
	queues->printAll();
	
	

	return 0;
}

/*

queue kuyruk yap�s� ilk giren ilk ��kar yani sadece head silinir  taile eklenir  edevlet i�lem s�ras� 
stack ilk giren son ��kar top a eklenir toptan ��kar 

tree katmanl� yap�d�r  en ba�taki  d���m root parent denir di�erleri child  parent olabilir 
binary treelerde bir node   maxiumum iki tane child node ba�lanabilir      nodelar� birbirine baglayana dallara edge denir
binary treelerde eklenecek node root node b�y�kse sa� dogru gider k�c�kse sola dogru gider ve i�lem bu di�er olan nodelarla devam eder
binary treeler arama ve silme i�lemlerinde �ok daha az i�lemlerde buluyor bir cocugun nodeu yoksa lead node denir yani yaprak node 
ayn� parentlara sahip olanlar kendi aralar�nda sibling node denir yani karde� node
subtree agac�n alt�ndaki k�melere denir

*/
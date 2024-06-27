#include <iostream>

using namespace std;

class  Node
{
public:
	int deger;
	Node* next;
	Node(int deger)
	{
		this->deger = deger;
		next = NULL;
	}
	

private:

};
class LinkedList {
	private:
		Node* head;
		Node* tail;
		int count;

	public:
		LinkedList(int deger)
		{
			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
		}
		~LinkedList()
		{
			Node* tmp = head;
			while (head != NULL)
			{
				head = head->next;
				delete tmp;
				tmp = head;
			}
		}
		void printHead()
		{
			if (head != NULL)
			{
				cout <<"Head: "<< head->deger << endl;
			}
		}
		void printTail()
		{
			if (tail != NULL)
			{
				cout <<"Tail: "<< tail->deger << endl;
			}
		}
		void getCount()
		{
			cout << "list count: " << this->count << endl;
		}
		void appendList(int deger)
		{
			Node* node = new Node(deger);
			if (count == 0)
			{
				head = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = node;
			}
			count++;
		}
		void printAll()
		{
			Node* tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->deger << endl;
				tmp = tmp->next;
			}
		}
		void deleteLastNode()
		{
			if (count == 0)
			{
				return;
			}
			Node* tmp = head;
			Node* tmp2 = tail;
			while (tmp != NULL)
			{
				tmp = tmp->next;
				if (tmp->next == tmp2)
				{
					break;
				}
			}
			tail = tmp;
			tail->next = NULL;
			count--;
			if(count==0)
			{
				head = NULL;
				tail = NULL;
			}
			delete tmp2;

		}
		void addFirst(int deger)
		{
			Node* node = new Node(deger);
			if (count == 0)
			{
				head = node;
				tail = node;
			}
			else
			{
				node->next = head;
				head = node;
			}
			count++;

		}
		void deleteFirst()
		{
			if (count == 0)
				return;
			Node* tmp = head;
			if (tmp->next)
			{
				head = tmp->next;
				count--;
			}
			else
			{
				head = NULL;
				tail = NULL;
			}
			delete tmp;

		}
		Node* GetNode(int index)
		{
			if (index < 0 || index >= count)
				return NULL;
			Node* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp= temp->next;
			}
			return temp;
		}
		void setValue(int index,int value)
		{
			Node *node= GetNode(index);
			if (node == NULL)
			{
				cout << " isleminiz gerceklesmemisdir";
				return;
			}
			node->deger = value;
		}
		bool insertNode(int index, int deger)
		{

			if (index < 0 || index > count)
				return false;

			if (index == 0)
			{
				addFirst(deger);
				return true;
			}
			if (index == count)
			{
				appendList(deger);
				return true;
			}
			Node* node=new Node(deger);
			Node* tmp = GetNode(index - 1);
			node->next = tmp->next;	
			tmp->next = node;
			count++;
			
			return true;

		}
		void deleteNode(int index)
		{
			if (index < 0 || index > count)
				return ;
			if (index == 0)
			{
				deleteFirst();
				return;
			}
			if (index == count-1)
			{
				deleteLastNode();
				return;
			}
			Node* tmp = GetNode(index-1);
			Node* silinecekNode = tmp->next;
			tmp->next = silinecekNode->next;
			delete silinecekNode;
			count--;

		}
};
int main()
{
	LinkedList* linkedList1 = new LinkedList(12);
	linkedList1->appendList(5);
	linkedList1->appendList(24);
	linkedList1->appendList(7);
	linkedList1->appendList(8);

	linkedList1->deleteNode(4);
	linkedList1->printAll();


	return 0;
}

/*
   array ve linked lists farklarý mesela dizi de ortada eleman silemezsin çünkü dizi bir blok iin belirttiðin sayý kadar byte ayýrýr ondan dolayý olmaz. ancak kopya dizi oluþturabilirsin
   head                                                            tail
	|                                                               |
   12,next ---------> 5,next--------------->24,next------------->7,next----------------->null
   linked list dez avantajlarýndan biri de sýra sýra çaðýrabilirsin dizideki gibi index mantýðý yok  linkedlistler diziler gibi yanyana tutulmaz   mesela array[index+20] çaðýrabilirsin linkedlist sýra sýra çaðýracan

	eðer sürekli ekleme çýkarma yapacaksan linkedlist kullan ama sürekli dizinin baþka yerlerinde deðerlere eriþmek istiyorsan array kullanmak zorundasýn
	bir algoritma ve datastrcuter ile ugrasýyorsan ilk ve son elemanlarkontrol edilir  buna boundry condition sýnýrlarý kontrol et
	methot içindeki oluþturulan deðiþkenler ve pointer deðiþkenler metot dýþýna çýkýnca silinir maindekileri elle silmen gerekir






*/

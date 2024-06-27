#include <iostream>

using namespace std;

class  Node
{
public:
	int deger;
	Node* next;
	Node* prev;
	Node(int deger)
	{
		this->deger = deger;
		next = NULL;
		prev = NULL;
	}


private:

};
class DoublyLinkedList
{
	private:
	Node* head;
	Node* tail;
	int count;



	public:
		DoublyLinkedList(int deger)
		{
			Node* node = new Node(deger);
			head = node;
			tail= node;
			count = 1;
		}
		~DoublyLinkedList()
		{
			Node* tmp = head;
			 
			while (head!=NULL)
			{
				head= head->next;
				delete tmp;
				tmp = head;
				cout << " node silindi"<<endl;
			}
		
		}

		void printList()
		{
			Node* tmp = head;
			while (tmp != NULL) 
			{
				cout << tmp->deger << " , ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		void printHead()
		{
			if (head != NULL)
			{
				cout << "Head: " << head->deger << endl;
			}
		}
		void printTail()
		{
			if (tail != NULL)
			{
				cout << "Tail: " << tail->deger << endl;
			}
		}
		void getCount()
		{
			cout << "list count: " << this->count << endl;
		}
		void appendList(int deger)
		{

			Node* tmp = new Node(deger);
			if (count == 0)
			{
				head = tmp;
				tail= tmp;
			}
			else
			{
					tail->next = tmp;
					tmp->prev = tail;
					tail = tmp;
			}


			count++;
		}
		void deleteLastNodes()
		{
			if (count == 0)
				return;
			
			Node* tmp = tail;
			 if (count != 1)
			{
			    	 tail = tail->prev;
			    	 tail->next = NULL;
			}
			 else if (count == 1)
			 {
				 head = NULL;
				 tail = NULL;
			 }
			delete tmp;
			count--;
		}
		void addFirst(int deger)
		{
			Node* tmp = new Node(deger);
			if (count != 0)
			{
				head->prev = tmp;
				tmp->next = head;
			}
			else
			{
				tail = tmp;
			}
			head = tmp;
			count++;
		}
		void deleteFirst()
		{
			if (count == 0)
				return;
			
			Node* tmp = head;
			if (count == 1)
			{
				head == NULL;
				tail== NULL;
			}
			else if (count != 1)
			{
				head = head->next;
				head->prev = NULL;;

			}
			delete tmp;

			count--;
		}
		Node* GetNode(int index)
		{
			if (index < 0 || index >= count)
				return NULL;
			Node* temp;
			if (count / 2 < index)
			{
				temp = tail;
				int a = count - index;
				
				for (int i = count-1; i > index; i--)
				{
					temp = temp->prev;
				}
			}
			else
			{
				temp = head;
				for (int i = 0; i < index; i++)
				{
					temp = temp->next;
				}
			}
			
		   
			return temp;
		}
		bool setNode(int index, int deger)
		{
			Node* tmp = GetNode(index);
			if (tmp != NULL)
			{
				tmp->deger = deger;
				return true;
			}
			else
			{
				return false;
			}
		}
		bool insertNode(int index, int deger)
		{
			if (index >= 0 && index <= count)
			{
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

				Node* yeniNode = new Node(deger);
				Node* tmp= GetNode(index-1);
				yeniNode->next = tmp->next;
				(tmp->next)->prev = yeniNode;
				tmp->next = yeniNode;
				yeniNode ->prev= tmp;
				count++;
				return true;

			}
			else
			{
				return false;
			}

		}
		void deleteNode(int index)
		{
			if (index >= 0 && index < count)
			{
				if (index == 0)
				{
					deleteFirst();
				}
				else if (index == count-1)
				{
					deleteLastNodes();
				}
				else
				{
					Node* node = GetNode(index);
					(node->prev)->next = node->next;
					(node->next)->prev = node->prev;
					delete node;
					count--;
				}
			}
			
		}
};
int main()
{
	DoublyLinkedList* doublyLinkedList = new DoublyLinkedList(12);

	doublyLinkedList->appendList(5);
	doublyLinkedList->appendList(24);
	doublyLinkedList->appendList(9);
	
	doublyLinkedList->printList();
	
	 doublyLinkedList->insertNode(2,999);

	 doublyLinkedList->printList();
	 doublyLinkedList->deleteNode(2);
	 doublyLinkedList->printList();






	 delete doublyLinkedList;
	return 0;
}
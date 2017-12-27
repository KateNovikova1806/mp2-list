#include "list.h"

List::List(const List& list2)
{
	if (list2.head != NULL) 
	{ 
		Node* node = list2.head->next;
		head = new Node(list2.head->data, NULL);
		Node* node1 = head;
		while (node != NULL)
		{
			node1->next = new Node(node->data, NULL);
			node = node->next;
			node1 = node1->next;
		}
	}
	else head = NULL;
}
List:: ~List()
{
	Clean();
}




List& List:: operator=(const List& list2) 
{

	if (list2.head != head)	Clean(); else return *this;
	if (list2.head != NULL) 
	{
		Node* node = list2.head->next;
		head = new Node(list2.head->data, NULL);
		Node* node1 = head;
		while (node != NULL)
		{
			node1->next = new Node(node->data, NULL);
			node = node->next;
			node1 = node1->next;
		}
		return (*this);

	}

}
bool List:: operator ==(const List& list2) const
{

	Node* nnode1 = head;
	Node* nnode2 = list2.head;
	while ((nnode1 != NULL) && (nnode2 != NULL) && (nnode1->data == nnode2->data))
	{
		nnode1 = nnode1->next;
		nnode2 = nnode2->next;
	}
	if ((nnode1 == NULL) && (nnode2 == NULL)) return true;
	else return false;
}
ostream& operator<<(ostream& ostr, const List& l)

{
	Node* tmp = l.head;
	while (tmp != NULL)
	{
		ostr << tmp->data << " ";
		tmp = tmp->next;
	}
	return ostr;
}


void List::InsertToHead(const DataType& d)
{

	if (head == NULL) head = new Node(d, NULL);
	else head = new Node(d, head);
}

void List::InsertToTail(const DataType& d)
{

	if (head == NULL) head = new Node(d, NULL);

	else 
	{
		Node* node = head;
		while (node->next != NULL) node = node->next;
		node->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* nod, const DataType& d)
{
	if (nod == NULL)
	{
		this->InsertToTail(d);
	}
	else
	{
		Node* node = head;
		while (nod != node) node = node->next;
		Node* ptr2 = nod->next;
		node->next = new Node(d, ptr2);
	}
}

void List::Delete(const DataType& d)
{
	int y = 0;
	Node*  nodelast= head;
	if (head != NULL) 
	{
		Node* node = head;
		if (node->data != d) 
		{
			node = node->next;
		}
		else 
		{
			y = 1;
			Node* headnode = head->next;
			delete head;
			head = headnode;
		}
		if (y == 0) 
		{
			while ((node != NULL) && (node->data != d)) 
			{
				node = node->next;
				nodelast = nodelast->next;
			}
			if (node == NULL) cout << "WRONG" << endl; 
			else 
			{
				nodelast->next = node->next;
				delete node;
			}
		}
	}
}

void List::Clean()
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			Node* nnode = head->next->next;
			Node* nnodefirst = head->next;
			delete head;
			head = NULL;
			while (nnode != NULL)
			{
				delete nnodefirst;
				nnodefirst = nnode;
				nnode = nnode->next;
			}
			delete nnodefirst;
		}
		else
		{
			delete head;
			head = NULL;
		}
	}
}


Node* List::Search(const DataType& d) 
{

	Node* node = head;
	while ((node != NULL) && (node->data != d)) node = node->next;
	if (node == NULL) return NULL; else return node;
}

int List::GetSize() 
{
	Node* node = head;
	int k = 0;
	while (node != NULL)
	{
		k++;
		node = node->next;
	}
	return k;
}


Node* List::GetHead()
{
	return head;
}



List List::Merge(Node* nod, const List& list2)
{
	List a;
	Node* node = head;
	if (nod != NULL) 
	{
		while (node != nod) 
		{
			a.InsertToTail(node->data);
			node = node->next;
		}
		a.InsertToTail(node->data);
		node = node->next;
		Node* nnode2 = list2.head;
		while (nnode2 != NULL)
		{
			a.InsertToTail(nnode2->data);
			nnode2 = nnode2->next;
		}
		while (node != NULL)
		{
			a.InsertToTail(node->data);
			node = node->next;
		}
		return a;
	}
	else
	{
		a = (*this);
		return a;
	}
}

void List::Inverse()
{
	Node* nnode1 = head;
	Node* nnode2;
	Node* nnode3;
	if (head != NULL)
	{
		nnode2 = head->next;
		head->next = NULL;
		if (nnode2 != NULL)
		{
			nnode3 = nnode2->next;
			while (nnode3 != NULL)
			{
				nnode2->next = nnode1;
				nnode1 = nnode2;
				nnode2 = nnode3;
				nnode3 = nnode3->next;
			}
			nnode2->next = nnode1;
			head = nnode2;
		}
	}
}



List List::Merge(const List& list2)
{
	List a;
	Node* node = head;
	while (node != NULL)
	{
		a.InsertToTail(node->data);
		node = node->next;
	}
	node = list2.head;
	while (node != NULL) 
	{
		a.InsertToTail(node->data);
		node = node->next;
	}
	return a;
}


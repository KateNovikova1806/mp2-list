#include "list.h"

List::List(const List& list2) {
	if (list2.head != NULL) {
		Node* ptr = list2.head->next;
		head = new Node(list2.head->data, NULL);
		Node* ptr2 = head;
		while (ptr != NULL) {
			ptr2->next = new Node(ptr->data, NULL);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
	}
	else head = NULL;
}

List:: ~List() {
	Clean();
}




List& List:: operator=(const List& list2) {

	if (list2.head != head)	Clean(); else return *this;
	if (list2.head != NULL) {
		Node* ptr = list2.head->next;
		head = new Node(list2.head->data, NULL);
		Node* ptr2 = head;
		while (ptr != NULL) {
			ptr2->next = new Node(ptr->data, NULL);
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
		return (*this);

	}

}

void List::Clean() {
	if (head != NULL) {
		if (head->next != NULL) {
			Node* Ptr = head->next->next;
			Node* Ptr_before = head->next;
			delete head;
			head = NULL;
			while (Ptr != NULL) {
				delete Ptr_before;
				Ptr_before = Ptr;
				Ptr = Ptr->next;
			}
			delete Ptr_before;
		}
		else {
			delete head;
			head = NULL;
		}
	}
}


void List::InsertToHead(const DataType& d) {

	if (head == NULL) head = new Node(d, NULL);
	else head = new Node(d, head);
}

void List::InsertToTail(const DataType& d) {

	if (head == NULL) head = new Node(d, NULL);

	else {
		Node* ptr = head;
		while (ptr->next != NULL) ptr = ptr->next;
		ptr->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* node, const DataType& d) {
	if (node == NULL) {
		this->InsertToTail(d);
	}
	else {
		Node* ptr = head;
		while (node != ptr) ptr = ptr->next;
		Node* ptr2 = node->next;
		ptr->next = new Node(d, ptr2);
	}
}

void List::Delete(const DataType& d) {
	int y = 0;
	Node* ptr_prev = head;
	if (head != NULL) {
		Node* ptr = head;
		if (ptr->data != d) {
			ptr = ptr->next;
		}
		else {
			y = 1;
			Node* ptr_head = head->next;
			delete head;
			head = ptr_head;
		}
		if (y == 0) {
			while ((ptr != NULL) && (ptr->data != d)) {
				ptr = ptr->next;
				ptr_prev = ptr_prev->next;
			}
			if (ptr == NULL) cout << "uncorrect, is is valtype no here" << endl; else {
				ptr_prev->next = ptr->next;
				delete ptr;
			}
		}
	}
}


Node* List::Search(const DataType& d) {

	Node* ptr = head;
	while ((ptr != NULL) && (ptr->data != d)) ptr = ptr->next;
	if (ptr == NULL) return NULL; else return ptr;
}

int List::GetSize() {
	Node* ptr = head;
	int k = 0;
	while (ptr != NULL) {
		k++;
		ptr = ptr->next;
	}
	return k;
}


Node* List::GetHead() {
	return head;
}

void List::Inverse() {
	Node* ptr_1 = head;
	Node* ptr_2;
	Node* ptr_3;
	if (head != NULL) {
		ptr_2 = head->next;
		head->next = NULL;
		if (ptr_2 != NULL) {
			ptr_3 = ptr_2->next;
			while (ptr_3 != NULL) {
				ptr_2->next = ptr_1;
				ptr_1 = ptr_2;
				ptr_2 = ptr_3;
				ptr_3 = ptr_3->next;
			}
			ptr_2->next = ptr_1;
			head = ptr_2;
		}
	}
}


List List::Merge(Node* node, const List& list2)
{
	List a;
	Node* ptr = head;
	if (node != NULL) {
		while (ptr != node) {
			a.InsertToTail(ptr->data);
			ptr = ptr->next;
		}
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
		Node* ptr_2 = list2.head;
		while (ptr_2 != NULL) {
			a.InsertToTail(ptr_2->data);
			ptr_2 = ptr_2->next;
		}
		while (ptr != NULL) {
			a.InsertToTail(ptr->data);
			ptr = ptr->next;
		}
		return a;
	}
	else {
		a = (*this);
		return a;
	}
}


List List::Merge(const List& list2)
{
	List a;
	Node* ptr = head;
	while (ptr != NULL) {
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
	}
	ptr = list2.head;
	while (ptr != NULL) {
		a.InsertToTail(ptr->data);
		ptr = ptr->next;
	}
	return a;
}


ostream& operator<<(ostream& os, const List& l)

{
	Node* tmp = l.head;
	while (tmp != NULL)
	{
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}

bool List:: operator ==(const List& list2) const {

	Node* ptr_1 = head;
	Node* ptr_2 = list2.head;
	while ((ptr_1 != NULL) && (ptr_2 != NULL) && (ptr_1->data == ptr_2->data)) {
		ptr_1 = ptr_1->next;
		ptr_2 = ptr_2->next;
	}
	if ((ptr_1 == NULL) && (ptr_2 == NULL)) return true;
	else return false;
}
#include "linkedlist.hpp"
#include <iostream>

using namespace std;

template <typename T>
void linked_list<T>::push_back(T data) {
	node<T>* tmp = new node<T>(data);
	if(!head_) {
		head_ = tmp;
		tail_ = tmp;
	} else {
		tail_->next_ = tmp;
		tail_ = tmp;
	}
} 

template <typename T>
void linked_list<T>::push_back(node<T>* n) {
	if(!head_) {
		head_ = n;
		tail_ = n;
		n->next_ = nullptr;
	} else {
		tail_->next_ = n;
		tail_ = n;
		n->next_ = nullptr;
	}
} 

template <typename T>
void linked_list<T>::push_front(T data) {
	node<T>* tmp = new node<T>(data);
	if(!head_) {
		head_ = tmp;
		tail_ = tmp;
	} else {
		tmp->next_ = head_;
		head_ = tmp;
	}
} 

template <typename T>
void linked_list<T>::push_front(node<T>* n) {
	if(!head_) {
		head_ = n;
		tail_ = n;
		n->next_ = nullptr;
	} else {
		n->next_ = head_;
		head_ = n;
	}
}

template <typename T>
void linked_list<T>::remove(T data) {
	if(!head_) {
		return;
	}

	node<T>* temp = head_;
	node<T>* prev = nullptr;

	if(head_->data_ == data) {
		head_ = head_->next_;
		delete(temp);
		return; 
	}

	while(temp && temp->data_ != data) {
		temp = temp->next_;
		prev = temp;
	}

	if(!temp) return;

	prev->next_ = temp->next_;
	delete(temp);
}

template <typename T>
node<T>* linked_list<T>::pop(node<T>* n) {
	if(!n || !head_) return nullptr;

	node<T> *tmp, *prev;

	if(head_ == n) {
		tmp = head_;
		head_ = head_->next_;
		return tmp;
	}

	tmp = head_->next_;
	prev = head_;
	while(tmp) {
		if(tmp == n) {
			prev->next_ = tmp->next_;
			return tmp;
		} else {
			prev = tmp;
			tmp = tmp->next_;
		}
	}
	return nullptr;
}


template <typename T>
void linked_list<T>::remove_front() {
	if(head_) {
		node<T>* tmp = head_;
		head_ = head_->next_;
		delete(tmp);
	}
}

template <typename T>
void linked_list<T>::remove_back() {
	if(!head_) {
		return;
	}
	node<T>* temp = head_;
	node<T>* prev = nullptr;

	while(temp->next_) {
		prev = temp;
		temp = temp->next_;
	}

	prev->next_ = nullptr;
	delete(temp);
}

template<typename T>
node<T>* linked_list<T>::get_head() {
	return head_;
}


template <typename T>
void linked_list<T>::partition(T data) {
	if(!head_) return;

	linked_list<T> left_ll;

	node<T>* tmp = head_;
	node<T>* next;

	// populate left partition
	while(tmp) {
		next = tmp->next_;
		if(tmp->data_ < data) {
			left_ll.push_back(this->pop(tmp));
		}
		tmp = next;
	}

	left_ll.print();

	// append left partition
	tmp = left_ll.get_head();

	while(tmp) {
		next = tmp->next_;
		this->push_front(tmp);
		tmp = next;
	}
} 


template <typename T>
void linked_list<T>::print() {
	if(!head_) {
		cout << "empty list" << endl;
	}
	node<T>* curr = head_;
	while(curr) {
		cout << curr->data_ << " ";
		curr = curr->next_;
	}
	cout << endl;
}




int main() {
	linked_list<int> ll;
	ll.push_back(8);
	ll.push_back(7);
	ll.push_back(6);
	ll.push_back(5);
	ll.push_back(4);
	ll.push_back(3);
	ll.push_back(2);
	ll.push_back(1);
	ll.partition(4);
	ll.print();

}




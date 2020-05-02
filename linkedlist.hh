#ifndef LINKEDLIST_HH
#define LINKEDLIST_HH

#define nullptr 0

template<typename T>
struct node {
	int data_;
	struct node* next_;
	node(T data);
};


template <typename T>
class linked_list {
 private:
 	node<T> *head_, *tail_;


 public:
 	linked_list();

 	void push_back(T data);
 	void push_back(node<T>* n);
 	void push_front(T data);
 	void push_front(node<T>* n);
 	void remove(T data);
 	void remove_back();
 	void remove_front();
 	void print();
 	void partition(T data);
 	node<T>* pop(node<T>* n);
 	node<T>* get_head();
};

template <typename T>
node<T>::node(T data) : data_(data), next_(nullptr) {
}

template <typename T>
linked_list<T>::linked_list() : head_(nullptr), tail_(nullptr) {
}
#endif
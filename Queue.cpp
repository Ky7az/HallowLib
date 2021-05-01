#include "Queue.h"

/* Node */
Node::Node(void *data)
{
	this->data = data;
	this->prev = NULL;
	this->next = NULL;
}
Node::~Node()
{
}

void* Node::get_data() const { return data; }
Node* Node::get_prev() const { return prev; }
void Node::set_prev(Node *prev) { this->prev = prev; }
Node* Node::get_next() const { return next; }
void Node::set_next(Node *next) { this->next = next; }

/* HwQueue */
Queue::Queue()
{
	this->len = 0;
	this->head = NULL;
	this->tail = NULL;
}
Queue::~Queue()
{
	Node *n = head;
	while (n != NULL) {
		//free_func(n->data);
		Node *n_next = n->get_next();
		rem(n);
		n = n_next;
	}
}

int Queue::get_len() const { return len; }
Node* Queue::get_head() const { return head; }
void Queue::set_head(Node *head) { this->head = head; }
Node* Queue::get_tail() const { return tail; }
void Queue::set_tail(Node *tail) { this->tail = tail; }

void Queue::add(void *data)
{
	Node *n = new Node(data);

	if (head == NULL) {
		head = n;
		tail = n;
	} else {
		tail->set_next(n);
		n->set_prev(tail);
		tail = n;
	}
	len += 1;
}

void Queue::rem(Node *n)
{
	if (n == NULL)
		return;

	if (head == n && tail == n) {
		head = NULL;
		tail = NULL;
	}
	else if (head == n) {
		set_head(n->get_next());
		head->set_prev(NULL);
	}
	else if (tail == n) {
		tail = n->get_prev();
		tail->set_next(NULL);
	}
	else {
		n->get_next()->set_prev(n->get_prev());
		n->get_prev()->set_next(n->get_next());
	}

	delete n;
	len -= 1;
}
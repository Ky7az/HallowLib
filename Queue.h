#ifndef __QUEUE_H__
#define __QUEUE_H__

/** INCLUDES **/
#include <windows.h>

/** CLASSES **/
/* Node */
class Node
{
public:
	Node(void *data);
	~Node();

	void* get_data() const;
	Node* get_prev() const;
	void set_prev(Node *prev);
	Node* get_next() const;
	void set_next(Node *next);

private:
	void *data;
	Node *prev;
	Node *next;
};

/* Queue */
class Queue
{
public:
	Queue();
	~Queue();

	int get_len() const;
	Node* get_head() const;
	void set_head(Node *head);
	Node* get_tail() const;
	void set_tail(Node *tail);

	void add(void *data);
	void rem(Node *n);

private:
	int len;
	Node *head;
	Node *tail;
};

#endif
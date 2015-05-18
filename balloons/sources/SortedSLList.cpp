#include "SortedSLList.h"

/* ---------------------------------------------------------------------------------- */
/* - SLNode class methods ----------------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */
template<typename Object>
SortedSLList<Object>::SLNode::SLNode()
{
	this->next = NULL;
}

template<typename Object>
SortedSLList<Object>::SLNode::SLNode(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}

template<typename Object>
SortedSLList<Object>::SLNode::~SLNode()
{
	;
}

template<typename Object>
typename SortedSLList<Object>::SLNode& SortedSLList<Object>::SLNode::operator=(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}


/* ---------------------------------------------------------------------------------- */
/* - SortedSLList class methods ----------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */
template<typename Object>
SortedSLList<Object>::SortedSLList()
{
	this->front = NULL;
	this->back = NULL;
	this->count = 0;
}

template<typename Object>
SortedSLList<Object>::SortedSLList(const Object& Data)
{
	this->head = &Data;
	this->tail = &Data;
	this->count = 1;
}

template<typename Object>
SortedSLList<Object>::~SortedSLList()
{
	;
}

template<typename Object>
Object SortedSLList<Object>::GetAtIndex(const int& Index)
{
	SLNode *temp;
	int index;

	temp = NULL;
	index = 0;

	if (Index > (this->count - 1))
	{
		return;
	}

	temp = this->front;
	while (index <= Index)
	{

	}
}

template<typename Object>
Object SortedSLList<Object>::GetFront()
{
	return (*(this->front));
}

template<typename Object>
Object SortedSLList<Object>::GetBack()
{
	return (*(this->back));
}

template<typename Object>
void SortedSLList<Object>::Add(const Object& Data)
{
	;
}

template<typename Object>
void SortedSLList<Object>::RemoveAtIndex(const int& Index)
{
	;
}

template<typename Object>
void SortedSLList<Object>::RemoveFront()
{
	;
}

template<typename Object>
void SortedSLList<Object>::RemoveBack()
{
	;
}

template<typename Object>
bool SortedSLList<Object>::Contains(const Object& Key)
{
	;
}

template<typename Object>
void SortedSLList<Object>::Clear()
{
	;
}

template<typename Object>
int SortedSLList<Object>::Size()
{
	;
}
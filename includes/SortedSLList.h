#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

#include <Windows.h>
#include "SortedList.h"

template <typename Object> 
class SortedSLList : public SortedList<Object>
{
private:
	/* ---------------------------------------------------------------------------------- */
	/* - SLNode class ------------------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */
	class SLNode
	{
	protected:
		Object data;
		SLNode *next;

	public:
		SLNode();
		SLNode(const SLNode& Node);
		~SLNode();
		SLNode& operator=(const SLNode& Node);
		SLNode* GetNext();
		Object GetData();
	};
	/* ---------------------------------------------------------------------------------- */
	/* - END ---------------------------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */
	SLNode *front;
	SLNode *back;

public:
	SortedSLList();
	SortedSLList(const Object& Data);
	~SortedSLList();
	Object GetAtIndex(const int& Index);
	Object GetFront();
	Object GetBack();
	void Add(const Object& Data);
	void RemoveAtIndex(const int& Index);
	void RemoveFront();
	void RemoveBack();
	bool Contains(const Object& Key);
	void Clear();
	int Size();
};

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

template<typename Object>
typename SortedSLList<Object>::SLNode* SortedSLList<Object>::SLNode::GetNext()
{
	return (this->next);
}

template<typename Object>
Object SortedSLList<Object>::SLNode::GetData()
{
	return (this->data);
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

	/* 
		If the Index is bigger than count that means we 
		want an object from outside the list, so we return NULL
	*/
	if (Index > (this->count - 1))
	{
		return NULL;
	}

	/*
		We parse the list in order to obtain the required Object
	*/
	temp = (SLNode*)this->front;
	while (index <= Index)
	{
		temp = temp->GetNext();
	}
	return (temp->GetData());
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
	return FALSE;
}

template<typename Object>
void SortedSLList<Object>::Clear()
{
	this->front = NULL;
	this->back = NULL;
	this->count = 0;
}

template<typename Object>
int SortedSLList<Object>::Size()
{
	return (this->count);
}

#endif //_SORTEDSLLIST_H_

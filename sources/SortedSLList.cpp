#include "SortedSLList.h"

/* ---------------------------------------------------------------------------------- */
/* - SLNode class methods ----------------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */

template<typename DataType>
SortedSLList<DataType>::SLNode::SLNode()
{
	this->next = NULL;
}

template<typename DataType>
SortedSLList<DataType>::SLNode::SLNode(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}

template<typename DataType>
SortedSLList<DataType>::SLNode::~SLNode()
{
	;
}

template<typename DataType>
typename SortedSLList<DataType>::SLNode& SortedSLList<DataType>::SLNode::operator=(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}


/* ---------------------------------------------------------------------------------- */
/* - SortedSLList class methods ----------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */


template<typename DataType>
SortedSLList<DataType>::SortedSLList()
{
	this->front = NULL;
	this->back = NULL;
	this->size = 0;
}

template<typename DataType>
SortedSLList<DataType>::SortedSLList(const DataType& Data)
{
	this->head = &Data;
	this->tail = &Data;
	this->size = 1;
}

template<typename DataType>
SortedSLList<DataType>::~SortedSLList()
{
	;
}

template<typename DataType>
DataType SortedSLList<DataType>::GetFront()
{
	return (*(this->front));
}

template<typename DataType>
DataType SortedSLList<DataType>::GetBack()
{
	return (*(this->back));
}

template<typename DataType>
DataType SortedSLList<DataType>::GetAtIndex(const int& Index)
{
	;
}

template<typename DataType>
void SortedSLList<DataType>::Add()
{
	;
}

template<typename DataType>
void SortedSLList<DataType>::RemoveFront()
{
	;
}

template<typename DataType>
void SortedSLList<DataType>::RemoveBack()
{
	;
}

template<typename DataType>
void SortedSLList<DataType>::RemoveAtIndex(const int& Index)
{
	;
}


template<typename DataType>
SortedSLList<DataType> SortedSLList<DataType>::Clone()
{
	;
}

template<typename DataType>
int SortedSLList<DataType>::Size()
{
	;
}
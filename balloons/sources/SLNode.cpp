#include "SLNode.h"

template<typename DataType>
SLNode<DataType>::SLNode()
{
	this->next = NULL;
}

template<typename DataType>
SLNode<DataType>::SLNode(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}

template<typename DataType>
SLNode<DataType>::~SLNode()
{
	;
}

template<typename DataType>
SLNode<DataType>& SLNode<DataType>::operator=(const SLNode& Node)
{
	this->data = Node.data;
	this->next = Node.next;
}

template<typename DataType>
void SLNode<DataType>::SetNext(SLNode *Node)
{
	this->next = Node;
}

template<typename DataType>
SLNode<DataType>* SLNode<DataType>::GetNext()
{
	return (this->next);
}

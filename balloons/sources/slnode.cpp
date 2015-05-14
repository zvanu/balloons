#include "slnode.h"

template<typename DataType>
SLNode<DataType>::SLNode()
{
	this->xCoordStart = 0;
	this->xCoordStart = 0;
	this->next = 0;
}

template<typename DataType>
SLNode<DataType>::~SLNode()
{
	;
}

template<typename DataType>
SLNode<DataType>&			SLNode<DataType>::operator=(const SLNode& other)
{
	this->xCoordStart = other.xCoordStart;
	this->xCoordEnd = other.xCoordEnd;
	this->next = other.next;
}

template<typename DataType>
bool			SLNode<DataType>::operator==(const SLNode& other)
{
	return (this->xCoordStart == other->xCoordStart &&
		this->xCoordEnd == other->xCoordEnd);
}

template<typename DataType>
std::ostream	SLNode<DataType>::operator<<(const SLNode& node)
{
	cout << "X start: " << node.xCoordStart << " | ";
	cout << "X end: " << node.xCoordEnd << "\n";
}

template<typename DataType>
void SLNode<DataType>::SetXCoordStart(DataType& value)
{
	this->xCoordStart = value;
}

template<typename DataType>
void SLNode<DataType>::SetXCoordEnd(DataType& value)
{
	this->xCoordEnd = value;
}

template<typename DataType>
DataType SLNode<DataType>::GetXCoordStart()
{
	return (this->xCoordStart);
}

template<typename DataType>
DataType SLNode<DataType>::GetXCoordEnd()
{
	return (this->xCoordEnd);
}

template<typename DataType>
void	SLNode<DataType>::SetNext(SLNode *nextNode)
{
	this->next = nextNode;
}

template<typename DataType>
SLNode<DataType>*		SLNode<DataType>::GetNext()
{
	return (this->next);
}

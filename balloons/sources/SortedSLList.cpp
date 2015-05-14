#include "sortedsllist.h."
#include "slnode.h"

template<typename DataType>
SortedSLList<DataType>::SortedSLList()
{
	this->front = NULL;
	this->back = NULL;
	this->size = 0;
}

template<typename DataType>
SortedSLList<DataType>::SortedSLList(const DataType& object)
{
	this->head = &object;
	this->tail = &object;
	this->size = 1;
}

template<typename DataType>
SortedSLList<DataType>::~SortedSLList()
{
	;
}

template<typename DataType>
DataType	SortedSLList<DataType>::GetFront()
{
	return (*(this->front));
}

template<typename DataType>
DataType	SortedSLList<DataType>::GetBack()
{
	return (*(this->back));
}

template<typename DataType>
DataType	SortedSLList<DataType>::GetAtIndex(const int& index)
{
	;
}

template<typename DataType>
void	SortedSLList<DataType>::Add()
{
	;
}

template<typename DataType>
void	SortedSLList<DataType>::RemoveFront()
{
	;
}

template<typename DataType>
void	SortedSLList<DataType>::RemoveBack()
{
	;
}

template<typename DataType>
void	SortedSLList<DataType>::RemoveAtIndex(const int& index)
{
	;
}

template<typename DataType>
int		SortedSLList<DataType>::GetIndexOfObject(const DataType& object)
{
	;
}

template<typename DataType>
SortedSLList<DataType>	SortedSLList<DataType>::Clone()
{
	;
}

template<typename DataType>
int		SortedSLList<DataType>::Size()
{
	;
}
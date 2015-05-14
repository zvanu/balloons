#include "sllist.h."
#include "slnode.h"

template<typename DataType>
SLList<DataType>::SLList()
{
	this->head = NULL;
	this->listSize = 0;
}
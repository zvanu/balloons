#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

/* Local includes */
#include "SLNode.h"

template <typename DataType>
class SortedSLList
{
private:
	DataType	*front;
	DataType	*back;
	int			size;
public:
	SortedSLList();
	SortedSLList(const DataType& object);
	~SortedSLList();

	DataType		GetFront();
	DataType		GetBack();
	DataType		GetAtIndex(const int& Index);
	void			Add();
	void			RemoveFront();
	void			RemoveBack();
	void			RemoveAtIndex(const int& Index);
	int				GetIndexOfObject(const DataType& Object);
	SortedSLList	Clone();
	int				Size();
};

#endif //_SORTEDSLLIST_H_

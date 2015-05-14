#ifndef _SLLIST_H_
# define _SLLIST_H_

/* Local includes */
#include "slnode.h"

template <typename DataType>
class SLList
{
private:
	SLNode	*head;
	int		listSize;
public:
	SLList();
	~SLList();

	void	getSize();
	void	listPrint();
	void	listAppend();
};

#endif //_SLLIST_H_

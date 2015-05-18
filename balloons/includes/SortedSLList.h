#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

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
	private:
		Object data;
		SLNode *next;

	public:
		SLNode();
		SLNode(const SLNode& Node);
		~SLNode();
		SLNode& operator=(const SLNode& Node);
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

#endif //_SORTEDSLLIST_H_

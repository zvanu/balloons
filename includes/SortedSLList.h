#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

template <typename DataType> 
class SortedSLList
{
private:
	/* ---------------------------------------------------------------------------------- */
	/* - SLNode class ------------------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */
	class SLNode
	{
	private:
		DataType	data;
		SLNode		*next;

	public:
		SLNode();
		SLNode(const SLNode& Node);
		~SLNode();
		SLNode& operator=(const SLNode& Node);
	};
	/* ---------------------------------------------------------------------------------- */
	/* - END ---------------------------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */
	SLNode	*front;
	SLNode	*back;
	int		size;

public:
	SortedSLList();
	SortedSLList(const DataType& Data);
	~SortedSLList();
	DataType GetFront();
	DataType GetBack();
	DataType GetAtIndex(const int& Index);
	void Add();
	void RemoveFront();
	void RemoveBack();
	void RemoveAtIndex(const int& Index);
	SortedSLList Clone();
	int Size();
};

#endif //_SORTEDSLLIST_H_

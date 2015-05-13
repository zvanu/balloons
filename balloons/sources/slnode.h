#ifndef _SLLIST_H_
# define _SLLIST_H_

template<typename DataType>
class SLNode
{
private:
	/* Value from which the segment starts */
	DataType	xCoordStart;
	/* Value to which the segment ends */
	DataType	xCoordEnd;
	/* Pointer to the next element in list */
	SLNode		*next;

public:
	/* Constructor */
	SLNode();
	/* Destructor */
	~SLNode();

	void		SetXCoordStart(DataType value);
	void		SetXCoordEnd(DataType value);
	DataType	GetXCoordStart();
	DataType	GetXCoordEnd();
	void		SetNext(SLNode *nextNode);
	SLNode		*GetNext();
};

#endif //_SLLIST_H_
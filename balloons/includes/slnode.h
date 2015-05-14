#ifndef _SLNODE_H_
# define _SLNODE_H_

# include <iostream>

template<typename DataType>
class SLNode
{
private:
	/* Value from which the segment starts */
	DataType	xCoordStart;
	/* Value to which the segment ends */
	DataType	xCoordEnd;
	/* Pointer to the next element in list */
	SLNode	*next;

public:
	/* Constructor */
	SLNode();
	/* Destructor */
	~SLNode();
	/* Operators */
	SLNode&			operator=(const SLNode& other);
	bool			operator==(const SLNode& other);
	std::ostream	operator<<(const SLNode& node);

	void			SetXCoordStart(DataType& value);
	void			SetXCoordEnd(DataType& value);
	DataType		GetXCoordStart();
	DataType		GetXCoordEnd();
	void			SetNext(SLNode *nextNode);
	SLNode			*GetNext();
};

#endif //_SLNODE_H_
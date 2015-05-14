#ifndef _SLNODE_H_
# define _SLNODE_H_

# include <iostream>

template<typename DataType>
class SLNode
{
private:
	/* Data of the node */
	DataType	data;
	/* Pointer to the next element in list */
	SLNode		*next;

public:
	/* Constructor */
	SLNode();
	SLNode(const SLNode& Node);
	/* Destructor */
	~SLNode();
	/* Operators */
	SLNode& operator=(const SLNode& Node);
	/* Setters */
	void SetNext(SLNode *Node);
	/* Getters */
	SLNode *GetNext();
};

#endif //_SLNODE_H_
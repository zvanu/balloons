#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

/**************************************************************************************************\
| Sorted List implementation over Single Linked List.                                              |
|**************************************************************************************************|
| Main methods inherited from AbstractSortedList (BASE CLASS):                                     |
|   - getAtIndex (index given)                                                                     |
|   - add (insert sorted)                                                                          |
|   - removeAtIndex (index given)                                                                  |
|   - contains (checks if list contains given data)                                                |
|   - clear (list is empty after call)                                                             |
|   - size (returns list node count)                                                               |
|**************************************************************************************************|
| Extra Methods: (see definitions for more details)                                                |
|   - getFront                                                                                     |
|   - getBack                                                                                      |
|   - removeFront                                                                                  |
|   - removeBack                                                                                   |
|   - begin                                                                                        |
|   - end                                                                                          |
|**************************************************************************************************|
| Implementation also involves SLNode and Iterator:                                                |
|   - SLNode - node in the list (contains data_ and next_ two private variables)                   |
|   - Iterator - iterator for the list, AbstractSortedListIterator for more details                |
|**************************************************************************************************|
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Operators, Constructors, Destructors, Setters and Getters are not specified                  |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

/* Required for NULL define */
#include <Windows.h>

#include "AbstractSortedList.h"
#include "AbstractSortedListIterator.h"

template <typename Object> 
class SortedSLList : public AbstractSortedList<Object>
{
private:
	class SLNode
	{
	protected:
		friend class SortedSLList<Object>;
		Object data_;
		SLNode *next_;

	public:
		/* Constructors */
		SLNode();
		SLNode(const SLNode& Node);
		SLNode(const Object& Data);
		/* Destructors */
		~SLNode();
		/* Functions */
		SLNode& operator=(const SLNode& Node);
		Object& getData();
	};
	/* Start and End of the list */
	SLNode *front_;
	SLNode *back_;

public:
	class Iterator : public AbstractSortedListIterator<SLNode, Object>
	{
	private:
		friend class SortedSLList<Object>;
		void setCurrent(SLNode* Node);
	public:
		Iterator();
		~Iterator();

		/* Is iterator valid (NULL != this->current) */
		bool isValid();
		bool hasNext();
		/* Iterator operators */
		void operator++();
		void operator++(int);
		bool operator==(const Iterator& Other);
		bool operator!=(const Iterator& Other);
		Iterator& operator=(const Iterator& Other);
		Object& operator*() const;
	};

	/* Constructors */
	SortedSLList();
	SortedSLList(const Object& Data);
	/* Destructors */
	~SortedSLList();
	/* Get the 'data' at Index in list */
	Object getAtIndex(const int& Index);
	Object getFront();
	Object getBack();
	/* Add into the list sorted ascending */
	void add(const Object& Data);
	/* Removie the 'data' at Index in list */
	void removeAtIndex(const int& Index);
	void removeFront();
	void removeBack();
	/* Check if list contains 'Data' */
	bool contains(const Object& Data);
	/* Clear list */
	void clear();
	/* Return list node count */
	int size();
	Iterator begin();
	Iterator end();
};

/* ---------------------------------------------------------------------------------- */
/* - SLNode class methods ----------------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */

template<typename Object>
SortedSLList<Object>::SLNode::SLNode()
{
	this->next_ = NULL;
}

template<typename Object>
SortedSLList<Object>::SLNode::SLNode(const Object& Data)
{
	this->data_ = Data;
	this->next_ = NULL;
}

template<typename Object>
SortedSLList<Object>::SLNode::~SLNode()
{
	;
}

template<typename Object>
typename SortedSLList<Object>::SLNode& SortedSLList<Object>::SLNode::operator=(const SLNode& Node)
{
	this->data_ = Node.data_;
	this->next_ = Node.next_;
}

template<typename Object>
Object& SortedSLList<Object>::SLNode::getData()
{
	return (this->data_);
}

/* ---------------------------------------------------------------------------------- */
/* - Iterator class methods --------------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */

/*
	Set current element (PRIVATE)
	Node - Other node
*/
template <typename Object>
void SortedSLList<Object>::Iterator::setCurrent(SLNode* Node)
{
	this->current_ = Node;
}

template <typename Object>
SortedSLList<Object>::Iterator::Iterator()
{
	this->current_ = NULL;
}

template <typename Object>
SortedSLList<Object>::Iterator::~Iterator()
{
	;
}

template <typename Object>
bool SortedSLList<Object>::Iterator::isValid()
{
	return (this->current_ != NULL);
}

template <typename Object>
bool SortedSLList<Object>::Iterator::hasNext()
{
	if (NULL == this->current_)
	{
		return (false);
	}

	if (NULL == this->current_->next_)
	{
		return (false);
	}
	return (true);
}

template <typename Object>
void SortedSLList<Object>::Iterator::operator++()
{
	if (NULL != this->current_)
	{
		this->current_ = this->current_->next_;
	}
}

template <typename Object>
void SortedSLList<Object>::Iterator::operator++(int)
{
	if (NULL != this->current_)
	{
		this->current_ = this->current_->next_;
	}
}

template <typename Object>
bool SortedSLList<Object>::Iterator::operator==(const Iterator& Other)
{
	return (this->current_ == Other.current_);
}

template <typename Object>
bool SortedSLList<Object>::Iterator::operator!=(const Iterator& Other)
{
	return (this->current_ != Other.current_);
}

template <typename Object>
typename SortedSLList<Object>::Iterator& SortedSLList<Object>::Iterator::operator=(const Iterator& Other)
{
	this->current_ = Other.current_;
}

template <typename Object>
Object& SortedSLList<Object>::Iterator::operator*() const
{
	return (this->current_->getData());
}

/* ---------------------------------------------------------------------------------- */
/* - SortedSLList class methods ----------------------------------------------------- */
/* ---------------------------------------------------------------------------------- */

template<typename Object>
SortedSLList<Object>::SortedSLList()
{
	this->front_ = NULL;
	this->back_ = NULL;
	this->count_ = 0;
}

template<typename Object>
SortedSLList<Object>::SortedSLList(const Object& Data)
{
	this->head = new SLNode(Data);
	this->tail = new SLNode(Data);
	this->count_ = 1;
}

template<typename Object>
SortedSLList<Object>::~SortedSLList()
{
	;
}

/*
	Get element from 'Index' in list (counting from 0!!!)
	Index - The list element position
	PRECOND: Index points between 0 and count
*/
template<typename Object>
Object SortedSLList<Object>::getAtIndex(const int& Index)
{
	SLNode *node;
	int index;

	node = NULL;
	index = 0;

	/* 
		If the Index is bigger than count that means we 
		want an object from outside the list, so we return NULL
	*/
	if (Index > (this->count_ - 1))
	{
		return Object();
	}

	/*
		We parse the list in order to obtain the required Object
	*/
	node = this->front_;
	index = 0;
	while (index < Index)
	{
		node = node->next_;
		index++;
	}
	return (node->data_);
}

/*
	Get the first element in the list
	PRECOND: List is valid (nonempty)
	*/
template<typename Object>
Object SortedSLList<Object>::getFront()
{
	if (NULL != this->front_)
	{
		return (this->front_->data_);
	}
	return Object();
}

/*
	Get the last element in the list
	PRECOND: List is valid (nonempty)
*/
template<typename Object>
Object SortedSLList<Object>::getBack()
{
	if (NULL != this->back_)
	{
		return (this->back_->data_);
	}
	return Object();
}

/* 
	Add element in the list (SORTED ASCENDING)
	Data - Element to be added in the list (SLNode is created with SLNode->data = Data)
	PRECOND: Data is an object of 'Object' type (defined at declaration)
*/
template<typename Object>
void SortedSLList<Object>::add(const Object& Data)
{
	SLNode *searchNode;
	SLNode *prevSearchNode;

	searchNode = NULL;
	prevSearchNode = NULL;

	/* List is empty */
	if (NULL == this->front_ &&
		NULL == this->back_)
	{
		this->front_ = new SLNode(Data);
		this->back_ = this->front_;
		this->count_ = 1;
	}
	else /* List is not empty */
	{
		prevSearchNode = this->front_;
		searchNode = this->front_;

		/* Add in front */
		if (Data < searchNode->data_)
		{
			this->front_ = new SLNode();
			this->front_->next_ = searchNode;
		}
		else
		{
			/* Add in middle or back */
			while (NULL != searchNode && Data > searchNode->data_)
			{
				prevSearchNode = searchNode;
				searchNode = searchNode->next_;
			}
			prevSearchNode->next_ = new SLNode(Data);
			prevSearchNode->next_->next_ = searchNode;
			if (NULL == searchNode)
			{
				this->back_ = prevSearchNode->next_;
			}
		}
	}
}

/*
	Remove element from list at 'Index'
	Index - The list element position
	PRECOND: Index points between 0 and count
*/
template<typename Object>
void SortedSLList<Object>::removeAtIndex(const int& Index)
{
	SLNode *prevNode;
	SLNode *node;
	int index;

	prevNode = NULL;
	node = NULL;
	index = 0;

	/*
	If the Index is bigger than count that means we
	want an object from outside the list, so we return NULL
	*/
	if (Index > (this->count_ - 1))
	{
		return;
	}

	/*
	We parse the list in order to obtain the required Object
	*/
	node = this->front_;
	index = 0;
	while (index < Index)
	{
		prevNode = node;
		node = node->next_;
		index++;
	}

	prevNode->next_ = node->next_;
	delete node;
	count_--;
}

/*
	Remove front element
*/
template<typename Object>
void SortedSLList<Object>::removeFront()
{
	SLNode *node;

	node = NULL;
	if (NULL != this->front_)
	{
		node = this->front_->next_;
		delete this->front_;
		this->front_ = node;
		count_--;
	}
}

/*
	Remove back element
*/
template<typename Object>
void SortedSLList<Object>::removeBack()
{
	SLNode *node;
	SLNode *prevNode;

	node = NULL;
	prevNode = NULL;

	node = this->front_;
	while (NULL != node->next_)
	{
		prevNode = node;
		node = node->next_;
	}
	delete node;
	prevNode->next_ = NULL;
	count_--;
}

/*
	Check if the list contains 'Data'
	Data - Data to be checked if it exists
*/
template<typename Object>
bool SortedSLList<Object>::contains(const Object& Data)
{
	SLNode *searchNode;

	searchNode = NULL;

	searchNode = this->front_;
	while (NULL != searchNode)
	{
		if (searchNode->data_ == Data)
		{
			return (true);
		}
		searchNode = searchNode->next_;
	}
	return (false);
}

/*
	Clears the list
	Post: this->count_ = 0;
*/
template<typename Object>
void SortedSLList<Object>::clear()
{
	SLNode *prevNode;
	SLNode *node;

	prevNode = NULL;
	node = NULL;

	node = this->front_;
	while (NULL != node)
	{
		prevNode = node;
		node = node->next_;
		delete prevNode;
	}

	this->front_ = NULL;
	this->back_ = NULL;
	this->count_ = 0;
}

/*
	Returns the node count (this->count_)
*/
template<typename Object>
int SortedSLList<Object>::size()
{
	return (this->count_);
}

/*
	Returns an Iterator to the beginning of the list
*/
template<typename Object>
typename SortedSLList<Object>::Iterator SortedSLList<Object>::begin()
{
	SortedSLList<Object>::Iterator iterator;
	iterator.setCurrent(this->front_);
	return (iterator);
}

/*
	Returns an Iterator to the end of the list
*/
template<typename Object>
typename SortedSLList<Object>::Iterator SortedSLList<Object>::end()
{
	SortedSLList<Object>::Iterator iterator;
	if (NULL != this->back_)
	{
		iterator.setCurrent(this->back_->next_);
	}
	else
	{
		iterator.setCurrent(NULL);
	}
	return (iterator);
}

#endif //_SORTEDSLLIST_H_
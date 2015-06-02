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
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _SORTEDSLLIST_H_
# define _SORTEDSLLIST_H_

/* Required for NULL define */
#include <Windows.h>

#include "AbstractSortedList.h"
#include "AbstractSortedListIterator.h"

namespace Containers
{
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

			/* Is iterator valid (NULL != this->current_) */
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
		/* Get the 'data' at front in list */
		Object getFront();
		/* Get the 'data' at back in list */
		Object getBack();
		/* Add into the list sorted ascending */
		void add(const Object& Data);
		/* Removie the 'data' at Index in list */
		void removeAtIndex(const int& Index);
		/* Remove the 'data' at front in list */
		void removeFront();
		/* Remove the 'data' at back in list */
		void removeBack();
		/* Check if list contains 'Data' */
		bool contains(const Object& Data);
		/* Clear list */
		void clear();
		/* Return list node count */
		int size();
		/* Return iterator at beginning of list */
		Iterator begin();
		/* Return iterator at end of list */
		Iterator end();
	};

	/* ---------------------------------------------------------------------------------- */
	/* - SLNode class methods ----------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */

	/*
		Default constructor
	*/
	template<typename Object>
	SortedSLList<Object>::SLNode::SLNode()
	{
		this->data_ = Object();
		this->next_ = NULL;
	}

	/*
		Constructor when Object is given
	*/
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
		return (*this);
	}

	/*
		Return the Object 
	*/
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
		@PRECOND: None
		@POSTCOND: current_ = Node
	*/
	template <typename Object>
	void SortedSLList<Object>::Iterator::setCurrent(SLNode* Node)
	{
		this->current_ = Node;
	}

	/*
		Default constructor
	*/
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

	/*
		Check if the iterator is valid
		@PRECOND:
		@POSTCOND:
			True - this->current_ is not NULL
			False - this->current_ is NULL
	*/
	template <typename Object>
	bool SortedSLList<Object>::Iterator::isValid()
	{
		return (NULL != this->current_);
	}

	/*
		Check if the iterator has a 'next' element
		@PRECOND: NULL != current_, NULL != current_->next_
		@POSTCOND:
			True - this->current_ and this->current_->next_ is not NULL
			False - otherwise
	*/
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

	/*
		Iterate through elements (obtain the 'next_' element)
		*** PREFIX ++ ***
		@PRECOND: current_ != NULL
		@POSTCOND: current_ = current_->next
	*/
	template <typename Object>
	void SortedSLList<Object>::Iterator::operator++()
	{
		if (NULL != this->current_)
		{
			this->current_ = this->current_->next_;
		}
	}

	/*
		Iterate through elements (obtain the 'next_' element)
		*** POSTFIX ++ ***
		@PRECOND: current_ != NULL
		@POSTCOND: current_ = current_->next
	*/
	template <typename Object>
	void SortedSLList<Object>::Iterator::operator++(int)
	{
		if (NULL != this->current_)
		{
			this->current_ = this->current_->next_;
		}
	}

	/*
		Check if this->current_ equals other.current_
		@PRECOND: None
		@POSTCOND:
			True - this->current_ equals other.current_
			False - otherwise
	*/
	template <typename Object>
	bool SortedSLList<Object>::Iterator::operator==(const Iterator& Other)
	{
		return (this->current_ == Other.current_);
	}

	/*
		Check if this->current_ does not equal other.current_
		@PRECOND: None
		@POSTCOND:
			True - this->current_ is not equal to other.current_
			False - otherwise
	*/
	template <typename Object>
	bool SortedSLList<Object>::Iterator::operator!=(const Iterator& Other)
	{
		return (this->current_ != Other.current_);
	}

	/*
		@PRECOND: None
		@POSTCOND: current_ = Other.current_
			Return: this
	*/
	template <typename Object>
	typename SortedSLList<Object>::Iterator& SortedSLList<Object>::Iterator::operator=(const Iterator& Other)
	{
		this->current_ = Other.current_;
		return (*this);
	}

	/*
		Return the Object
		@PRECOND: current_ != NULL
		@POSTCOND:
			Return: Object contained in current_
	*/
	template <typename Object>
	Object& SortedSLList<Object>::Iterator::operator*() const
	{
		return (this->current_->getData());
	}

	/* ---------------------------------------------------------------------------------- */
	/* - SortedSLList class methods ----------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */

	/*
		Default constructor
		@PRECOND: None
		@POSTCOND:
			front = NULL
			back = NULL
			count = 0
	*/
	template<typename Object>
	SortedSLList<Object>::SortedSLList()
	{
		this->front_ = NULL;
		this->back_ = NULL;
		this->count_ = 0;
	}

	/*
		Constructor when Object is given
		@PRECOND: None
		@POSTCOND:
			front = new Node containing Data
			back = front
			count = 1
	*/
	template<typename Object>
	SortedSLList<Object>::SortedSLList(const Object& Data)
	{
		this->front_ = new SLNode(Data);
		this->back_ = this->front_;
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
		@PRECOND: Index points between 0 and count
		@POSTCOND:
			Return: Object contained at Index
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
			want an object from outside the list, so we return NULL-type object
		*/
		if (Index > (this->count_ - 1))
		{
			return (Object());
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
		@PRECOND: List is valid (nonempty)
		@POSTCOND: 
			Return: Object contained at front
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
		@PRECOND: List is valid (nonempty)
		@POSTCOND:
		Return: Object contained at back
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
		@PRECOND: Data is an object of 'Object' type (defined at declaration)
		@POSTCOND:
			SLList now contains 'Data'
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
				this->front_ = new SLNode(Data);
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
			this->count_++;
		}
	}

	/*
		Remove element from list at 'Index'
		Index - The list element position
		@PRECOND: Index points between 0 and count
		@POSTCOND:
			Object at index 'Index' is now removed
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
		prevNode = this->front_;
		index = 0;
		while (index < Index)
		{
			prevNode = node;
			node = node->next_;
			index++;
		}

		prevNode->next_ = node->next_;
		delete node;
		this->count_--;
	}

	/*
		Remove front element
		@PRECOND: List is valid (nonempty)
		@POSTCOND:
			Object at index 0 is now removed
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
		@PRECOND: List is valid (nonempty)
		@POSTCOND:
			Object at index 'count_ - 1' is now removed
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
		this->back_ = prevNode;
		count_--;
	}

	/*
		Check if the list contains 'Data'
		Data - Data to be checked if it exists
		@PRECOND: Data is an object of 'Object' type (defined at declaration)
		@POSTCOND
			Return: True - if it exists
			Return: False - otherwise
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
		@PRECOND: None
		@POSTCOND: this->count_ = 0;
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
		@PRECOND: None
		@POSTCOND:
			Return: count_ (element count in vector)
	*/
	template<typename Object>
	int SortedSLList<Object>::size()
	{
		return (this->count_);
	}

	/*
		Returns an Iterator to the beginning of the list
		@PRECOND: None
		@POSTCOND:
			Return: New iterator at beginning of vector
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
		@PRECOND: None
		@POSTCOND:
			Return: New iterator at end of vector
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
} // End of 'Containers' Namespace
#endif //_SORTEDSLLIST_H_
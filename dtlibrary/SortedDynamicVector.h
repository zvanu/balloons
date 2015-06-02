/**************************************************************************************************\
| Sorted List implementation over Dynamic Vector.                                                  |
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
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _SORTEDDYNAMICVECTOR_H_
# define _SORTEDDYNAMICVECTOR_H_

/* Required for NULL define */
#include <Windows.h>

#include "AbstractSortedList.h"
#include "AbstractSortedListIterator.h"

namespace Containers
{
	template <typename Object>
	class SortedDynamicVector : public AbstractSortedList<Object>
	{
	private:
		int capacity_;
		Object *array_;
		/* Methods */
		void ensureCapacity(const int& IncreaseValue);
		void switchLeftAtIndex(const int& index);
		void switchRightAtIndex(const int& index);


	public:
		class Iterator : public AbstractSortedListIterator<Object, Object>
		{
		private:
			friend class SortedDynamicVector<Object>;
			void setCurrent(Object *Element);
		
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
		SortedDynamicVector();
		SortedDynamicVector(const SortedDynamicVector& Other);
		/* Destructors */
		~SortedDynamicVector();
		/* Get the 'data' at Index in list */
		Object getAtIndex(const int& Index);
		/* Get the 'data' at front in list */
		Object getFront();
		/* Get the 'data' at back in list */
		Object getBack();
		/* Add into the list sorted ascending */
		void add(const Object& Data);
		/* Removie the 'data' at Index in vector */
		void removeAtIndex(const int& Index);
		/* Remove the 'data' at front in vector */
		void removeFront();
		/* Remove the 'data' at back in vector */
		void removeBack();
		/* Check if list contains 'Data' */
		bool contains(const Object& Data);
		/* Clear list */
		void clear();
		/* Return list node count */
		int size();
		/* Return iterator at beginning of vector */
		Iterator begin();
		/* Return iterator at end of vector */
		Iterator end();
	};

	/* ---------------------------------------------------------------------------------- */
	/* - Iterator class methods --------------------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */

	/*
		Set current element (PRIVATE)
		Address - Address of the array (position), then we can iterate by pointer++
		@PRECOND: None
		@POSTCOND: current_ = Address
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::Iterator::setCurrent(Object *Address)
	{
		this->current_ = Address;
	}

	template <typename Object>
	SortedDynamicVector<Object>::Iterator::Iterator()
	{
		this->current_ = NULL;
	}

	template <typename Object>
	SortedDynamicVector<Object>::Iterator::~Iterator()
	{
		;
	}

	/*
		Check if the iterator is valid
		@PRECOND: None
		@POSTCOND:
			Return: True - this->current_ is not NULL
			Return: False - this->current_ is NULL
	*/
	template <typename Object>
	bool SortedDynamicVector<Object>::Iterator::isValid()
	{
		return (NULL != this->current_);
	}

	/*
		Check if the iterator has a 'next' element
		@PRECOND: current_ != NULL
		@POSTCOND:
			Return: True - this->current_ is not NULL
			Return: False - otherwise
	*/
	template <typename Object>
	bool SortedDynamicVector<Object>::Iterator::hasNext()
	{
		if (NULL == this->current_)
		{
			return (false);
		}
		return (true);
	}

	/*
		Iterate through elements (increase pointer)
		*** I also check for NULL pointer even though it shouldn't happen ***
		*** PREFIX ++ ***
		@PRECOND: current_ != NULL
		@POSTCOND: current_ = current_ + 1
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::Iterator::operator++()
	{
		if (NULL != this->current_)
			this->current_++;
	}

	/*
		Iterate through elements (increase pointer)
		*** I also check for NULL pointer even though it shouldn't happen ***
		*** POSTFIX ++ ***
		@PRECOND: current_ != NULL
		@POSTCOND: current_ = current_ + 1
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::Iterator::operator++(int)
	{
		if (NULL != this->current_)
			this->current_++;
	}

	/* 
		Check if this->current_ equals other.current_
		@PRECOND: None
		@POSTCOND:
			Return: True - this->current_ equals other.current_
			Return: False - otherwise
	*/
	template <typename Object>
	bool SortedDynamicVector<Object>::Iterator::operator==(const Iterator& Other)
	{
		return (this->current_ == Other.current_);
	}

	/*
		Check if this->current_ does not equal other.current_
		@PRECOND: None
		@POSTCOND:
			Return: True - this->current_ is not equal to other.current_
			Return: False - otherwise
	*/
	template <typename Object>
	bool SortedDynamicVector<Object>::Iterator::operator!=(const Iterator& Other)
	{
		return (this->current_ != Other.current_);
	}

	/*
		@PRECOND: None
		@POSTCOND: current_ = Other.current_
			Return: this
	*/
	template <typename Object>
	typename SortedDynamicVector<Object>::Iterator& SortedDynamicVector<Object>::Iterator::operator=(const Iterator& Other)
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
	Object& SortedDynamicVector<Object>::Iterator::operator*() const
	{
		if (NULL != this->current_)
			return (*(this->current_));
	}

	/* ---------------------------------------------------------------------------------- */
	/* - SortedDynamicVector class methods ---------------------------------------------- */
	/* ---------------------------------------------------------------------------------- */

	/*
		Make sure there is enough space in the vector to contain NewCapacity elements
		@PRECOND: NewCapacity > 0
		@POSTCOND:
			If NewCapacity > this->capacity_:
				- this->capacity_ is big enough to have elements
				- this->array_ has a new size (this->capacity_)
			If NewCapacity < this->capacity_:
				- nothing happens
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::ensureCapacity(const int& NewCapacity)
	{
		Object *aux;

		aux = NULL;
	
		/* If there is enough space, we don't do anything */
		if (this->capacity_ >= NewCapacity)
		{
			return;
		}

		aux = this->array_;
		this->capacity_ = this->capacity_ * 2;
		this->array_ = new Object[capacity_];
		for (int index = 0; index < count_; index++)
		{
			this->array_[index] = aux[index];
		}
		delete[] aux;
	}

	/*
		Switch all elements from 'Index' to end with one position to the left (for remove)
		@PRECOND: Index >= 0
		@POSTCOND: array_ is shifted one position to left at Index
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::switchLeftAtIndex(const int& Index)
	{
		for (int index = Index; index < this->count_ - 1; index++)
		{
			this->array_[index] = this->array_[index + 1];
		}
	}
	
	/*
		Switch all elements from 'Index' to end with one position to the right (for add)
		@PRECOND: Index >= 0
		@POSTCOND: array_ is shifted one position to right at index
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::switchRightAtIndex(const int& Index)
	{
		for (int index = this->count_; index > Index; index--)
		{
			this->array_[index] = this->array_[index - 1];
		}
	}

	/*
		Default constructor assumes vector has:
			- this->capacity_ = 10
			- this->count_ = 0;
			- this->array_ is an array of 10 elements
		@PRECOND: None
		@POSTCOND: New Dynamic Vector
	*/
	template <typename Object>
	SortedDynamicVector<Object>::SortedDynamicVector()
	{
		this->count_ = 0;
		this->capacity_ = 10;
		this->array_ = new Object[this->capacity_];
	}

	/*
		Copy constructor
		@PRECOND: Other - valid Dynamic Vector
		@POSTCOND: New Dynamic Vector identical to Other
	*/
	template <typename Object>
	SortedDynamicVector<Object>::SortedDynamicVector(const SortedDynamicVector& Other)
	{
		this->count_ = Other.count_;
		this->capacity_ = Other.capacity_;
		this->array_ = new Object[Other.capacity_];
		for (int index = 0; index < Other.count_; index++)
		{
			this->array_[index] = Other.array_[index];
		}
	}

	template <typename Object>
	SortedDynamicVector<Object>::~SortedDynamicVector()
	{
		;
	}
	
	/*
		Get element from 'Index' in list (counting from 0!!!)
		Index - The vector element position
		@PRECOND: Index points between 0 and count, Vector is valid (nonempty)
		@POSTCOND: 
			Return: Object contained at Index
	*/
	template <typename Object>
	Object SortedDynamicVector<Object>::getAtIndex(const int& Index)
	{
		/*
			If the Index is bigger than count that means we
			want an object from outside the list, so we return NULL-type object
		*/
		if (Index >= this->count_)
		{
			return (Object());
		}
		return (this->array_[Index]);
	}

	/*
		Get the first element in the vector
		@PRECOND: Vector is valid (nonempty)
		@POSTCOND:
			Return: Object contained at front
	*/
	template <typename Object>
	Object SortedDynamicVector<Object>::getFront()
	{
		return (this->array_[0]);
	}

	/*
		Get the last element in the vector
		@PRECOND: Vector is valid (nonempty)
		@POSTCOND:
			Return: Object contained at back
	*/
	template <typename Object>
	Object SortedDynamicVector<Object>::getBack()
	{
		return (this->array_[this->count_ - 1]);
	}

	/*
		Add element in the vector (SORTED ASCENDING)
		Data - Element to be added in the vector
		@PRECOND: Data is an object of 'Object' type (defined at declaration)
		@POSTCOND:
			Dynamic Vector now contains 'Data'
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::add(const Object& Data)
	{
		int index;

		index = 0;
		
		this->ensureCapacity(this->count_ + 1);
		while (index < this->count_ && Data > this->array_[index])
		{
			index++;
		}
		this->switchRightAtIndex(index);
		this->array_[index] = Data;
		this->count_++;
	}

	/*
		Remove element from list at 'Index'
		Index - The list element position
		@PRECOND: Index points between 0 and count, Vector is valid (nonempty)
		@POSTCOND:
			Object at index 'Index' is now removed
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::removeAtIndex(const int& Index)
	{
		this->switchLeftAtIndex(Index);
		this->count_--;
	}

	/*
		Remove front element
		@PRECOND: Vector is valid (nonempty)
		@POSTCOND:
			Object at index '0' is now removed
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::removeFront()
	{
		this->switchLeftAtIndex(0);
		this->count_--;
	}

	/*
		Remove back element
		@PRECOND: Vector is valid (nonempty)
		@POSTCOND:
			Object at index 'count_ - 1' is now removed
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::removeBack()
	{
		this->count_--;
	}

	/*
		Check if the vector contains 'Data'
		Data - Data to be checked if it exists
		@PRECOND: Data is an object of 'Object' type (defined at declaration) 
		@POSTCOND
			Return: True - if it exists
			Return: False - otherwise
	*/
	template <typename Object>
	bool SortedDynamicVector<Object>::contains(const Object& Data)
	{
		for (int index = 0; index < this->count_; index++)
		{
			if (this->array_[index] == Data)
			{
				return (true);
			}
		}
		return (false);
	}

	/*
		Clears the list
		@PRECOND: None
		@POSTCOND: this->count_ = 0;
	*/
	template <typename Object>
	void SortedDynamicVector<Object>::clear()
	{
		delete[] this->array_;
		this->count_ = 0;
		this->capacity_ = 10;
		this->array_ = new Object[this->capacity_];
	}

	/*
		Returns the node count (this->count_)
		@PRECOND: None
		@POSTCOND:
			Return: count_ (element count in vector)
	*/
	template <typename Object>
	int SortedDynamicVector<Object>::size()
	{
		return (this->count_);
	}

	/*
		Returns an Iterator to the beginning of the vector
		@PRECOND: None
		@POSTCOND:
			Return: New iterator at beginning of vector
	*/
	template <typename Object>
	typename SortedDynamicVector<Object>::Iterator SortedDynamicVector<Object>::begin()
	{
		SortedDynamicVector<Object>::Iterator iterator;
		iterator.setCurrent(this->array_);
		return (iterator);
	}

	/*
		Returns an Iterator to the end of the vector
		@PRECOND: None
		@POSTCOND:
			Return: New iterator at end of vector
	*/
	template <typename Object>
	typename SortedDynamicVector<Object>::Iterator SortedDynamicVector<Object>::end()
	{
		SortedDynamicVector<Object>::Iterator iterator;
		iterator.setCurrent(this->array_ + this->count_);
		return (iterator);
	}
} // End of 'Containers' Namespace
#endif //_SORTEDDYNAMICVECTOR_H_
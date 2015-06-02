/**************************************************************************************************\
| Abstract Sorted List implementation                                                              |
|**************************************************************************************************|
| Main methods:                                                                                    |
|   - getAtIndex (index given)                                                                     |
|   - add (insert sorted)                                                                          |
|   - removeAtIndex (index given)                                                                  |
|   - contains (checks if list contains given data)                                                |
|   - clear (list is empty after call)                                                             |
|   - size (returns list node count)                                                               |
|**************************************************************************************************|
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _ABSTRACTSORTEDLIST_H_
# define _ABSTRACTSORTEDLIST_H_

template <typename T>
class AbstractSortedList
{
protected:
	int count_;

public:
	/*
		Get Object from 'Index' in list (counting from 0!!!)
		Index - The list element position
			@PRECOND: Index points between 0 and count, list is valid (nonempty)
			@POSTCOND:
			Return: Object contained at Index
	*/
	virtual T getAtIndex(const int& Index) = 0;

	/*
		Add element in the list (SORTED ASCENDING)
		Data - Element to be added in the list
		@PRECOND: Data is an object of 'Object' type (defined at declaration)
		@POSTCOND:
			List now contains T (sorted)
	*/
	virtual void add(const T& Object) = 0;

	/*
		Remove element from list at 'Index'
		Index - The list element position
		@PRECOND: Index points between 0 and count, list is valid (nonempty)
		@POSTCOND:
			Object at index 'Index' is now removed
	*/
	virtual void removeAtIndex(const int& Index) = 0;

	/*
		Check if the list contains 'Data'
		Data - Data to be checked if it exists
		@PRECOND: Data is an object of 'Object' type (defined at declaration)
		@POSTCOND
			Return: True - if it exists
			Return: False - otherwise
	*/
	virtual bool contains(const T& Key) = 0;

	/*
		Clears the list
			@PRECOND: None
			@POSTCOND: this->count_ = 0;
	*/
	virtual void clear() = 0;

	/*
		Returns the node count (this->count_)
		@PRECOND: None
		@POSTCOND:
			Return: count_ (element count in list)
	*/
	virtual int size() = 0;
};

#endif //_ABSTRACTSORTEDLIST_H_
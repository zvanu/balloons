/**************************************************************************************************\
| Abstract Sorted List Iterator FWD implementation                                                 |
|**************************************************************************************************|
| Methods:                                                                                         |
|   - isValid                                                                                      |
|   - hasNext                                                                                      |
|   - operator++ (next)                                                                            |
|   - operator* (getElement)                                                                       |
|**************************************************************************************************|
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _ABSTRACTSORTEDLISTITERATOR_H_
# define _ABSTRACTSORTEDLISTITERATOR_H_

template <typename T, typename O>
class AbstractSortedListIterator
{
protected:
	T* current_;

public:
	/*
	Check if the iterator is valid
		@PRECOND: None
		@POSTCOND:
			Return: True - iterator is valid
			Return: False - iterator is not valid
	*/
	virtual bool isValid() = 0;

	/*
		Check if the iterator has a 'next' element
		@PRECOND: current_ != NULL
		@POSTCOND:
			Return: True - iterator has a next element
			Return: False - otherwise
	*/
	virtual bool hasNext() = 0;

	/*
		Iterate through elements
		@PRECOND: Iterator is valid
		@POSTCOND: current_ becomes the next element
	*/
	virtual void operator++() = 0;

	/*
		Return the Object
		@PRECOND: Iterator is valid
		@POSTCOND:
			Return: Object contained in current_
	*/
	virtual O& operator*() const = 0;
};

#endif //_ABSTRACTSORTEDLISTITERATOR_H_
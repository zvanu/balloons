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
	virtual T getAtIndex(const int& Index) = 0;
	virtual void add(const T& Object) = 0;
	virtual void removeAtIndex(const int& Index) = 0;
	virtual bool contains(const T& Key) = 0;
	virtual void clear() = 0;
	virtual int size() = 0;
};

#endif //_ABSTRACTSORTEDLIST_H_
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
	virtual bool isValid() = 0;
	virtual bool hasNext() = 0;
	virtual void operator++() = 0;
	virtual O& operator*() const = 0;
};

#endif //_ABSTRACTSORTEDLISTITERATOR_H_
#ifndef _SORTEDLIST_H_
# define _SORTEDLIST_H_

template <typename Object>
class SortedList
{
protected:
	int count;

public:
	virtual Object GetAtIndex(const int& Index) = 0;
	virtual void Add(const Object& Object) = 0;
	virtual void RemoveAtIndex(const int& Index) = 0;
	virtual bool Contains(const Object& Key) = 0;
	virtual void Clear() = 0;
	virtual int Size() = 0;
};

#endif //_SORTEDLIST_H_
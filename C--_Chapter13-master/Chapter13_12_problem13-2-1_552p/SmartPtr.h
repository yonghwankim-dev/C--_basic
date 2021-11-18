#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__


template <class T>
class SmartPtr
{
private:
	T * posptr;
public:
	SmartPtr(T * ptr);
	T& operator*() const;
	T* operator->() const;
	~SmartPtr();
};
#endif // !__SMART_PTR_H__

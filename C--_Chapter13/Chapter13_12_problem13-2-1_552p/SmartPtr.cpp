#include "SmartPtr.h"
#include <iostream>

template <class T>
SmartPtr<T>::SmartPtr(T * ptr) : posptr(ptr)
{

}

template <class T>
T& SmartPtr<T>::operator*() const
{
	return *posptr;
}

template <class T>
T* SmartPtr<T>::operator->() const
{
	return posptr;
}

template <class T>
SmartPtr<T>::~SmartPtr()
{
	delete posptr;
}
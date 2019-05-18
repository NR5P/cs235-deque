/***********************************************************************
* Program:
*    Assignment 03, Deque
*    Brother JonesL, CS 235
* Author:
*    Griffin Pope, Dan Worwood, Nathan Riggs, Dallen Cluff
* Summary:
*    Implementation of Deque data structure
************************************************************************/
#ifndef DEQUE_H_
#define DEQUE_H_

namespace custom
{
#include <cassert>

template <typename T>
class deque
{
private:
   T *data;
   int iFront;
   int iBack;
   int numCapacity;

   void assign(const deque &rhs);
   void resize(int newCapacity);
   int iFrontNormalized() const
   {
      return iNormalize(iFront);
   }
   int iBackNormalized() const
   {
      return iNormalize(iBack);
   }
   int iNormalize(int i) const
   {
      return (i >= 0) ? (i % numCapacity) : 
      (numCapacity - ((-1 -i) % numCapacity) - 1);
   }

public:
   deque() : numCapacity(0), iFront(0), iBack(-1), data(nullptr) {};
   deque(int capacity);
   deque(const deque &rhs);
   ~deque();
   int size() const
   {
       return (iBack - iFront) + 1;
   }
   bool empty() const
   {
      return size() == 0;
   }
   deque &operator=(const deque &t);
   void clear()
   {
      iFront = 0;
      iBack = -1;
   }
   void push_back(const T &t);
   void push_front(const T &t);
   void pop_back();
   void pop_front();
   T &front();
   T &back();
   const T &front() const;
   const T &back() const;
   int capacity() const {return numCapacity;}
};

//test
// non default constructor that takes an int
template <typename T>
deque<T>::deque(int capacity)
   : iFront(0), iBack(-1), data(nullptr)
{
   resize(capacity);
   iFront = 0;
   iBack = -1;
}

// copy constructor
template <typename T>
deque<T>::deque(const deque &otherdeque)
   : iFront(0), iBack(-1), data(nullptr), numCapacity(0)
{
   assign(otherdeque);
}

template <typename T>
deque<T>::~deque()
{
   /*
   if (data != nullptr)
   {
      delete[] data;
      data = nullptr;
   }
   */
   if (numCapacity != 0)
      delete [] data;
}

template <typename T>
void deque<T>::pop_front()
{
   if (!empty())
      iFront++;
   else
      throw "ERROR: attempting to access an element in an empty deque";
    
}

template <typename T>
void deque<T>::pop_back()
{
   if (!empty())
      iBack--;
   else
      throw "ERROR: attempting to access an element in an empty deque";
}


template <typename T>
T &deque<T>::front()
{
   if (empty())
      throw "ERROR: attempting to access an element in an empty deque";
   return data[iFrontNormalized()];
}

template <typename T>
const T &deque<T>::front() const
{
   if (empty())
      throw "ERROR: attempting to access an element in an empty deque";
   return data[iFrontNormalized()];
}

template <typename T>
T &deque<T>::back()
{
   if (empty())
      throw "ERROR: attempting to access an element in an empty deque";
   return data[iBackNormalized()];
}

template <typename T>
const T &deque<T>::back() const
{
   if (empty())
      throw "ERROR: attempting to access an element in an empty deque";
   return data[iBackNormalized()];
}

template <typename T>
deque<T> &deque<T>::operator=(const deque<T> &rhs)
{
   assign(rhs);
   return *this;
}

template <typename T>
void deque<T>::assign(const deque<T> &rhs)
{
   int newSize = rhs.size();
   if (newSize == 0)
   {
      iFront = 0;
      iBack = -1;
      if (data != nullptr)
         delete[] data;
      data = nullptr;
      return;
   }

   if (numCapacity < newSize)
   {
      resize(newSize);
   }

   // copy the data
   //int iDestination = 0;
   int newI = -1;
   for (int iSource = rhs.iFront; iSource <= rhs.iBack; iSource++)
      push_back(rhs.data[iNormalize(iSource)]);
      //data[++newI] = rhs.data[iNormalize(iSource)];
      //push_back(rhs.data[iSource % rhs.numCapacity]); //TODO what to put in data brackets

   iFront = 0;
   iBack = rhs.size() - 1;
}

/*********************************************************
* DEQUE :: RESIZE
* Grow the size of the deque to (at a minimum) of a given
* size. If the size is set to zero, then the capacity will
* be doubled. If the stack is currently not empty, the contents
* will be copied over to the new buffer
*********************************************************/


   /****************************************************
* DEQUE :: GROW
* If the deque is currently empty, allocate to size 2.
* Otherwise, double the size
***************************************************/
template <class T>
void deque <T> :: resize(int newCapacity)
{
   // set the default size
   if (newCapacity <= 0 || newCapacity < numCapacity)
   newCapacity = (numCapacity ? numCapacity * 2 : 1);

   // allocate the new buffer
   T * newData = new(std::nothrow) T[newCapacity];
   if (NULL == newData)
   throw "ERROR: Unable to allocate a new buffer for deque";

   // copy the data
   int newIBack = -1;
   for (int i = iFront; i <= iBack; i++)
   newData[++newIBack] = data[iNormalize(i)];
   iFront = 0;
   iBack = newIBack;

   // set up the new values
   numCapacity = newCapacity;
   if (NULL != data)
   delete [] data;
   data = newData;
}

template <typename T>
void deque<T>::push_back(const T &t)
{
   if (size() == capacity())
   {
      resize(numCapacity > 0 ? numCapacity * 2 : 1);
   }
   iBack++;
   data[iBackNormalized()] = t;
}

template <typename T>
void deque<T>::push_front(const T &t)
{
   if (size() == capacity())
   {
      resize(numCapacity > 0 ? numCapacity * 2 : 1);
   }
   iFront--;
   data[iFrontNormalized()] = t;
}

}

#endif

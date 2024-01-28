//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic queue (First In First Out) implementation based on an linked list
//

#ifndef _AED_lQueue_
#define _AED_lQueue_

#include <cassert>
#include "sList.h"

template <typename T>
class lQueue
{
  private:
  sList<T> L;
  public:
    lQueue(void)
    {
      L;
    }
    ~lQueue(void)
    {
      L.~sList();
    }
    void clear(void)
    {
      while(L.size() != 0)
        L.remove();
    }
    int size(void) const
    {
      L.size();
    }
    int is_full(void) const
    {
      int i = 0;
      for(i = 0; i < L.size(); i++)
      {
        L.
      }
    }
    int is_empty(void) const
    {
        if(L.size() == 0)
          return 0;
        return -1;
    }
    void enqueue(T &v)
    {
      L.insert_after_tail(v);
    }
    T dequeue(void)
    {
      if(L.size != 0)
      {
        T tmp = L.value();
        L.remove_head();
        return tmp;
      }
      else  
        return -1;
    }
    T peek(void)
    {
    }
};

#endif

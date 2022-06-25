#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
    bool empty() const
    {
      if (first == nullptr && last == nullptr)
       {
           return true;
       }
       else
       {
           return false;
       }
    }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const
  {
    return list_size;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front()
    {
        assert(!empty());
        return first->datum;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back()
  {
     assert(!empty());
     return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum)
    {
        Node *p = new Node;
        p->datum = datum;
        p->prev = nullptr;
        if (empty())
        {
            first = last = p;
            p->next = nullptr;
        }
        else
        {
            p->next = first;
            first->prev = p;
            first = p;
        }
        ++list_size;
       
    }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum)
    {
        Node *p = new Node;
        p->datum = datum;
        p->next = nullptr;
        if (empty())
        {
            first = last = p;
            p->prev = nullptr;
        }
        else
        {
            last->next = p;
            p->prev = last;
            last = p;
        }
        ++list_size;
    }
    
  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front()
    {
        assert(!empty());
        Node *p = first;
        if (list_size > 1)
        {
          first = first->next;
          first->prev = nullptr;
          delete p;
        }
        else
        {
            delete p;
            first = last = nullptr;
        }
        --list_size;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back()
  {
    assert(!empty());
    Node *p = last;
    if (list_size > 1)
    {
        last = last->prev;
        last->next = nullptr;
        delete p;
    }
    else
    {
        delete p;
        first = last = nullptr;
    }
    --list_size;
  }
 
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear()
  {
     while (!empty())
     {
        pop_front();
     }
  }

    // default constructor
    List(): list_size(0), first(nullptr), last(nullptr) {}
    
    // copy constructor
    List(const List<T> &other): list_size(0), first(nullptr), last(nullptr)
    {
        copy_all(other);
    }
    
    // destructor
    ~List()
    {
        clear();
    }
    
    // overloaded assignment operator
    List & operator=(const List<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }
        clear();
        copy_all(other);
        return *this;
    }
    
  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other)
  {
      assert(empty());
      for (Node *ptr = other.first; ptr; ptr = ptr->next)
        {
            push_back(ptr->datum);
        }
   }

  int list_size; // size of the list (added by me)
  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.
      
      
      
  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
      
     // default constructor
     Iterator():node_ptr(nullptr) {}
      
      // implementation of *
      T & operator*() const
      {
          assert(node_ptr);
          return node_ptr->datum;
      }
      
      //implementation of ++ (prefix)
      typename List<T>::Iterator & operator++()
      {
          assert(node_ptr);
          node_ptr = node_ptr->next;
          return *this;
      }
      
      //implementation of ==
      bool operator==(Iterator other) const
      {
          return node_ptr == other.node_ptr;
      }
      
      //implementation of !=
      bool operator!=(Iterator other) const
      {
          return (!(node_ptr == other.node_ptr));
      }
   

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;

    // construct an Iterator at a specific position
      Iterator(Node *p) : node_ptr(p) {}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const
    {
        return Iterator();
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i)
    {
       
         if (i == begin())
         {
            pop_front();
         }
        else if (i.node_ptr->next == nullptr)
         {
            pop_back();
         }
        else
         {
             Node *node_ptr_copy = i.node_ptr;
             node_ptr_copy->prev->next = node_ptr_copy->next;
             //i.node_ptr->prev->next = i.node_ptr->next;
             node_ptr_copy->next->prev = node_ptr_copy->prev;
             //i.node_ptr->next->prev = i.node_ptr->prev;
             delete node_ptr_copy;
             --list_size;
          }
        
     }


  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum)
    {
             if (i == begin())
             {
                push_front(datum);
             }
             else if (i == end())
             {
                 push_back(datum);
             }
            else
             {
                 Node *p = new Node;
                 p->datum = datum;
                 p->next = i.node_ptr;
                 p->prev = i.node_ptr->prev;
                 i.node_ptr->prev->next = p;
                 i.node_ptr->prev = p;
                 ++list_size;
              }
      }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.



#endif // Do not remove this. Write all your code above this line.

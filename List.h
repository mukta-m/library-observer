#ifndef LIST_H
#define LIST_H

#include "Book.h"

// **************************************      //
// LIST CLASS                                 //
// PURPOSE: holds data of Book* and the next Node  //
// ************************************** //

class List
{
  class Node
  {
/*
    friend class List;
    private:
*/
    public:
      Book* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(Book*);
    void del(int, Book**);
    void print() const;
    Book* find(int id) const;
    void cleanup();

  private:
    Node* head;
};

#endif

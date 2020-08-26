#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"

// **************************************      //
// LIBRARY CLASS                               //
// PURPOSE: manages a collection of books //
// has a List that stores master collection and //
// stores observers as logger object pointers   //
// ************************************** //


class Library
{
  public:
  Library();
  ~Library();
  void subscribe(Logger* logger);
  void notify(Book* b);
  void add(Book* b);
  Book* find(int id);
  void checkOut(Book* b);
  void checkIn(Book* b);
  void print() const;

  private:
  List masterBook;
  vector<Logger*> observers;
};

#endif

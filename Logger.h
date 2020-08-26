#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"

// **************************************      //
// LOGGER CLASS                               //
// PURPOSE: Abstract class that  track the checking //
// in and checking out of books in the library  //
// ************************************** //

class Logger
{
  public:
    Logger(string="");
    ~Logger();
    virtual void update(Book*) = 0;
    void printLogs() const;

  protected:
    string name;
    List logInfo;

};
// **************************************      //
// CHECKINLOGGER CLASS                               //
// PURPOSE: Concrete class that tracks the checked //
// in books in the library  //
// ************************************** //
class CheckInLogger : public Logger
{
  public:
    CheckInLogger(string="Checked-in");
    virtual void update(Book* b);

};
// **************************************      //
// CHECKOUTLOGGER CLASS                               //
// PURPOSE: Concrete class that tracks the checked //
// out books in the library  //
// ************************************** //
class CheckOutLogger : public Logger
{
  public:
    CheckOutLogger(string = "Checked-out");
    virtual void update(Book* b);

};

#endif

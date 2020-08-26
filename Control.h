#ifndef CONTROL_H
#define CONTROL_H

#include "Library.h"
#include "View.h"

// **************************************      //
// CONTROL CLASS                               //
// PURPOSE: implements control flow for whole system  //
// ************************************** //

class Control
{
  public:
    Control();
    ~Control();
    void launch();
    void initBooks();

  private:
    Library library;
    View view;

};

#endif

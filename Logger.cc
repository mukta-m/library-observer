#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

Logger :: Logger(string n){
    name = n;
}

Logger :: ~Logger(){
  //cout << "logger dtor " << endl;
}

void Logger::printLogs() const {
    cout << "LOGS " << name << endl;
    logInfo.print();
}


CheckInLogger :: CheckInLogger(string n) : Logger(n){
      //cout << "-- checked in ctor " << endl;
}

void CheckInLogger::update(Book* b){
     if (b->isCheckedIn() == true){
         logInfo.add(b);
     }
     else{
         logInfo.del(b->getBookID(), &b);
     }
}

CheckOutLogger :: CheckOutLogger(string n):Logger(n)
{
      // cout << "-- checked out ctor " << endl;
}

void CheckOutLogger::update(Book* b){
     if (b->isCheckedIn() == false){
         logInfo.add(b);
     }
     else{
         logInfo.del(b->getBookID(), &b);
     }
}

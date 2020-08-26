#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

int Book::nextId = 1001;

Book::Book(string t, string a)
{
  id     = nextId;
  ++nextId;
  title  = t;
  author = a;
  checkedIn = true;
}

Book::Book(Book& orig)
{
  id     = orig.id;
  title  = orig.title;
  author = orig.author;
  checkedIn = orig.checkedIn;

}

Book::~Book(){}

void Book::checkIn(){ checkedIn = true; }

void Book::checkOut(){ checkedIn = false; }

int Book::getNextId() { return nextId; }

int Book::getBookID() const{ return id; }

string Book::getAuthor() const{ return author; }

bool Book::isCheckedIn() const{ return checkedIn; }

void Book::print() const
{
  string out;
  if (checkedIn == true){
    out = "Checked In";
  }
  else{
    out = "Checked Out";
  }
  cout<< id << "          " << title << "       by "<<author << "        " << out<<endl;
}

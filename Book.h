#ifndef BOOK_H
#define BOOK_H

// **************************************      //
// BOOK CLASS                               //
// PURPOSE: Book that has an ID, title, author and   //
// whether or not it has been checked in // 
// ************************************** //


class Book
{
  public:
    Book(string="", string="");
    Book(Book&);
    ~Book();
    int getBookID() const;
    string getAuthor() const;
    bool isCheckedIn() const;
    static int getNextId();
    void checkIn();
    void checkOut();
    void print() const;


  private:
    static int nextId;
    int id;
    string title;
    string author;
    bool checkedIn;
};

#endif

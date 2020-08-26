#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"

Library :: Library(){};

Library :: ~Library(){
    for (int i=0; i < observers.size(); i++){
        observers[i]->printLogs();
        delete observers[i];
    }
    masterBook.cleanup();
}

void Library::subscribe(Logger* logger){
    observers.push_back(logger);
}

void Library::notify(Book* b){
    for (int i=0; i < observers.size(); i++){
        observers[i]->update(b);
    }
}

void Library::add(Book* b){
    masterBook.add(b);
    notify(b);
}

Book* Library::find(int id){
    Book* found;

    found = masterBook.find(id);

    return found;
}

void Library::checkOut(Book* b){
    b->Book::checkOut();
    notify(b);
}

void Library::checkIn(Book* b){
    b->Book::checkIn();
    notify(b);
}

void Library::print() const{
    cout << "LIBRARY " << endl; 
    masterBook.print();
}

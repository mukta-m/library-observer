#include <iostream>
using namespace std;

#include "List.h"

List::List() : head(NULL) { }

List::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

void List::add(Book* stu)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = stu;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;


  while (currNode != NULL) {
    if (stu == currNode->data){
      return;
    }

    if (stu->getAuthor() < currNode->data->getAuthor())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

}

void List::del(int name, Book** stu)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getBookID() == name)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// when do we get here?  2 cases:  we found the data, or we didn't

  if (currNode == NULL) {
    *stu = NULL;
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  *stu = currNode->data;
  delete currNode;

}

Book* List::find(int id) const{
    Node* currNode;
    currNode = head;

    Book* foundBook;

    while (currNode != NULL){
      if (currNode->data->getBookID() == id){
        foundBook = currNode->data;
        return foundBook;
      }
      currNode = currNode->next;
    }
    return NULL;
}

void List::cleanup(){
      Node* currNode;
      currNode = head;

      while (currNode != NULL){
        delete currNode->data;
        currNode = currNode->next;
      }
}





void List::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

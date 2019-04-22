// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017


//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

// Node structure.
// Used to store student names and scores.
// Can linked to another node object.
struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

// initializing the Linked list.
void initList(ListType &list);

// filling the linked list, the new element is the first element in this linked list.
// if the element has already in the linked list, return true.
bool insertFront(ListType &list, string key, int value);

// remove specified element from the the linked list.
// if the element has already in the linked list, return true.
bool removeKey(ListType &list, string key);

// used to change and look up specified element in the linked list.
int* lookUp(ListType &list, string key);

// return the size of the linked list.
int size(ListType &list);

// print out all elements in the linked list to the screen.
void getAll(ListType &list);











// keep the following line at the end of the file
#endif

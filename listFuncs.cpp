// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017


#include <iostream>
#include <cassert>
#include<string>

#include "listFuncs.h"

using namespace std;

// initialize the first node in the linked list.
// para theKey: student name, theValue: score.
Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

// initialize a node if the node is not the first in the linked list.
// para theKey: student name, theValue: score, n: the address of the next node.
Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

// initialize the linked list by specify its first node(element).
// para list: the pointer to the linked list. Points to the first element in the linked list.
void initList(ListType &list)
{
  list = NULL;
}

// add the new node to the linked list, the new added node will be the first element
// in the linked list.
// return false if the student has already exist.
// para list: the pointer to the linked list, key: student name, value: score.
bool insertFront(ListType &list, const string key, int value)
{
  Node *p = list;

  // find out if the student name has already in the linked list.
  while(p != NULL)
  {
    if(p->key == key)
    {
      return false;
    }
    p = p->next;
  }

  // add new node to the linked list.
  // if the linked list is empty, add new node with student name and score.
  // if the linked list is not empty, add new node with student name, score
  // and the address of the next node.
  if(list == NULL)
  {
    list = new Node(key, value);
  }
  else
  {
    list = new Node(key, value, list);
  }
  return true;
};

// remove student from the table.
// return true if the student has already exist.
// para list: the pointer to the linked list, key: student name.
bool removeKey(ListType &list, string key)
{
  Node *p1 = list;

  if(list == NULL)
  {
    return false;
  }

  if(p1->next == NULL)
  {
    if(p1->key == key)
    {
      list = NULL;
      delete p1;
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    if(p1->key == key)
    {
      list = p1->next;
      delete p1;
      return true;
    }
    while(p1->next != NULL)
    {
      if(p1->next->key == key)
      {
        p1->next = p1->next->next;
        return true;
      }
      p1 = p1->next;
    }
    return false;
  }
}

// find and change a student score.
// return the address of the score value or NULL if not found.
// para list: the pointer to the linked list, key: student name.
int* lookUp(ListType &list, string key)
{
  Node *p = list;

  // find if the student has already exist.
  while(p != NULL)
  {
    if(p->key == key)
    {
      return &(p->value);
    }
    p = p->next;
  }
  return NULL;
}

// return the size of the linked list.
// para list: the pointer to the linked list.
int size(ListType &list)
{
  Node *p = list;
  int size = 0;

  while( p != NULL)
  {
    size = size + 1;
    p = p->next;
  }
  return size;
}

// print out all the elements in the linked list.
// para list: the pointer to the linked list.
void getAll(ListType &list)
{
  Node *p = list;
  while(p != NULL)
  {
    cout << p->key << "\t\t" << p->value << endl;
    p = p->next;
  }
  delete p;
  return;
}

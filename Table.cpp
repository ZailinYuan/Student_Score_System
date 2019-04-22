// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

// initialize the table class by default size.
Table::Table()
{
  hashMap = new ListType[HASH_SIZE];
  hashSize = HASH_SIZE;
  for(unsigned int i=0; i<hashSize; i++)
  {
    initList(hashMap[i]);
  }
}

// initialize the table class by customized size.
// para hSize: the size of the table customized by user.
Table::Table(unsigned int hSize)
{
  hashMap = new ListType[hSize];
  hashSize = hSize;
}

// return the address of the score of the student name in the table.
// para key: student name.
int * Table::lookup(const string &key)
{
  int index = hashCode(key);
  return lookUp(hashMap[index], key);
}

// remove the student from the table.
// return true if the student has already exist.
//para key: student name.
bool Table::remove(const string &key)
{
  int index = hashCode(key);
  return removeKey(hashMap[index], key);
}

// add student name and score to the table.
// return true if the student has already in the table.
// para: key: student name, value: student score.
bool Table::insert(const string &key, int value)
{
  int index = hashCode(key);
  return insertFront(hashMap[index], key, value);
}

// return the number of students in the table.
int Table::numEntries() const
{
  int total = 0;

  for(int i=0; i<hashSize; i++)
  {
    total = total + size(hashMap[i]);
  }
  return total;      // dummy return value for stub
}

// print all the student name and score to the screen.
void Table::printAll() const
{
  for(int i=0; i<hashSize; i++)
  {
    getAll(*(hashMap+i));
  }
}

// print current table stats to the screen.
// find out the longest chain in the table.
// para out: out_stream
void Table::hashStats(ostream &out) const
{
  int numEmpty = 0;
  int maxSize = 0;
  for(int i=0; i<hashSize; i++)
  {
    if(hashMap[i] == NULL)
    {
      numEmpty = numEmpty + 1;
    }
    else
    {
      if(size(hashMap[i]) > maxSize)
      {
        maxSize = size(hashMap[i]);
      }
    }
  }


  out << "number of buckets: " << hashSize << endl;
  out << "number of entries: " << numEntries() << endl;
  out << "number of non-Empty buckets: " << hashSize - numEmpty << endl;
  out << "longest chain: " << maxSize << endl;
}


// add definitions for your private methods here

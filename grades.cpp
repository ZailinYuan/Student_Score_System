// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void help();

// The main function.
// Treating the command line commands and reacts as command line specifies.
// Stimulate the IO console.
// Using Table class.
// para: argc: table size specified.
int main(int argc, char * argv[])
{

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1)
  {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1)
    {
      cout << "Command line argument (hashSize) must be a positive number" << endl;
      return 1;
    }

    grades = new Table(hashSize);

    }
    else
    {   // no command line args given -- use default table size
      grades = new Table();
    }

      grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*

  string word1, word2; // word1: command input, word2: student name input
  int score; // score: student score input

  // execute the IO console.
  // accept the command input and print out the results.
  // print out format is also defined here.
  while(1) // creating a endless loop.
  {
    cout << "cmd>";
    cin >> word1;

    if(cin.get() != '\n') // judge whether the student name input.
    {
      cin >> word2;

      if(cin.get()!= '\n') // judge whether the score input. //THREE WORDS COMMANDS
      {
        cin >> score;
        cin.clear();

        if(word1 == "insert")
        {
          if(grades->insert(word2, score)== 0) // judge whether the student name is already exist.
          {
            cout << word2 << " has already exist!" << endl << endl;
          }
        }
        else if(word1 == "change")
        {
          if(grades->remove(word2)) // judge whether the student name is already exist.
          {
            grades->insert(word2, score);
          }
          else
          {
            cout << word2 << " doesn't exist!" << endl << endl;
          }
        }
        else
        {
            // report error if the command is wrong.
          cout << "ERROR: invalid command" << endl << endl;
          cin.sync();
        }

      }
      else //TWO WORDS COMMANDS
      {
        if(word1 == "lookup")
        {
          if(grades->lookup(word2)== 0) // judge whether the student name is already exist.
          {
            cout << word2 << " doesn't exist!" << endl << endl;
          }
          else
          {
            cout << word2 << "\t\t" << *(grades->lookup(word2))<< endl << endl;
          }
        }
        else if(word1 == "remove")
        {
          if(grades->remove(word2)) // judge whether the student name is already exist.
          {
            cout << word2 << " is removed!" << endl << endl;
          }
          else
          {
            cout << word2 << " does not exist!" << endl << endl;
          }
        }
        else
        {
            // report error if the command is wrong.
          cout << "ERROR: invalid command" << endl << endl;
        }
      }
    }
    else//ONE WORDS COMMANDS
    {
      if(word1 == "print")
      {
          // print all student scores.
        grades->printAll();
        cout << endl;
      }
      else if(word1 == "size")
      {
        cout << "Number of entries: " << grades->numEntries() << endl << endl;
      }
      else if(word1 == "stats")
      {
          // print current stats of the table.
        grades->hashStats(cout);
        cout << endl;
      }
      else if(word1 == "help")
      {
          // get commands summary.
        help();
      }
      else if(word1 == "quit")
      {
          // quit the program (endless loop).
        break;
      }
      else
      {
          // report error if the command is wrong.
        cout << "ERROR: invalid command" << endl << endl;
      }
    }
  }
  return 0;
}

// commands summary
void help()
{
  cout << "insert name score" << endl;
  cout << "\t" << "Insert name and score in the grade table." << endl << endl;
  cout << "change name newscore" << endl;
  cout << "\t" << "Change the score of an existing name." << endl << endl;
  cout << "lookup name" << endl;
  cout << "\t" << "Look up a name in the table." << endl << endl;
  cout << "remove name" << endl;
  cout <<"\t" << "Remove student by this name." << endl << endl;
  cout << "print" << endl;
  cout << "\t" << "Prints out all names and scores in the table." << endl << endl;
  cout << "size" << endl;
  cout << "\t" << "Prints out the number of entries in the table." << endl << endl;
  cout << "stats" << endl;
  cout << "\t" << "Prints out statistics about the hash table at this point." << endl << endl;
  cout << "help" << endl;
  cout << "\t" << "Prints out a brief command summary." << endl << endl;
  cout << "quit" << endl;
  cout << "\t" << "Exits." << endl << endl;
}


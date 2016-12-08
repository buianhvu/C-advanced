#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_SIZE 10
#define INCREMENTAL_SIZE 5



typedef struct {
  char name[80];
  long number;
} PhoneEntry;

typedef struct {
  PhoneEntry *entries;
  int total;
  int size;
} PhoneBook;

PhoneBook creatPhoneBook() 
{
  PhoneBook new;
  new.entries = (PhoneEntry*) malloc(sizeof(PhoneEntry)*INITIAL_SIZE);
  new.total = 0;
  new.size = INITIAL_SIZE;
  return new;
}

void dropPhoneBook(PhoneBook *book)
{
  free(book->entries);
}

void addPhoneNumber(char *name, long number, PhoneBook *book)
{
  int i;
  PhoneEntry new;
  strcpy(new.name, name);
  new.number = number;
 if((*book).total < (*book).size)
    {
      book->entries[(*book).total] = new;
      (*book).total++;
    }
 else
    {
      PhoneBook *book2;
      PhoneBook *del;
      (*book2).entries = (PhoneEntry*) malloc( ( (*book).size + INCREMENTAL_SIZE ) * sizeof(PhoneEntry) );
      for(i = 0; i < (*book).total; i++)
	{
	  (*book2).entries[i] = (*book).entries[i];
	}
      (*book2).total = (*book).total;
      (*book2).size = (*book).size + INCREMENTAL_SIZE;
      (*book2).entries[(*book2).total] = new;
      (*book2).total++;
      del = book;
      book = book2;
      dropPhoneBook(del);
    }
}

PhoneEntry* getPhoneNumber(char *name, PhoneBook book)
{
  int i;
  int found = 0;
  for(i = 0; i < book.total; i++)
    {
      if(strcmp(name, book.entries[i].name) == 0)
	{
	  return &book.entries[i];
	  found = 1;
	}
    }
  if(found == 0)
    return NULL;
}
	
    

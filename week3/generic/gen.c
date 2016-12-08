#include<stdlib.h>
#include<stdio.h>
#define INITIAL_SIZE 100
#define INCREMENTAL_SIZE 10

typedef struct {
  void *key;
  void *value;
}Entry;

typedef struct {
  Entry *entries;
  int size, total;
  Entry (*makeNode)(void *, void *);
  int (*compare)(void *, void *);
}SymbolTable;
// makeNode is a function pointer refers to a function to create a node with a key and a value pass


SymbolTable creatSymbolTable(Entry (*makeNode)(void*, void*), int (*compare)(void*, void*) )
{
  SymbolTable tab;
  tab.size = INITIAL_SIZE;
  tab.total = 0;
  tab.entries = (Entry*) malloc(INITIAL_SIZE*sizeof(Entry));
  tab.makeNode = makeNode;
  tab.compare = compare;
  return tab;
}

void dropSymbolTable(SymbolTable *tab)
{
  int i = 0;
  if(tab == NULL)
    exit(1);
  if(tab->entries != NULL)
    {
      Entry *del;
      del = tab->entries;
      for(i = 0; i < tab->total; i++)
	{
	  free(del[i].key);
	  free(del[i].value);
	  free(&del[i]);
	  i++;
	}
      free(tab->entries);
    }
  free(&tab->total);
  free(&tab->size);
}

void addEntry(void* key, void* value, SymbolTable *tab)
{
  if(key == NULL || tab == NULL)
    exit(1);
  if(tab->entries == NULL)
    exit(1);
  if(tab->total == tab->size)
    {
      tab->size = tab->size + INCREMENTAL_SIZE;
      tab->entries = (Entry*) malloc( tab->size*sizeof(Entry));
      if(tab->entries == NULL)
	exit(1);
    }
  tab->entries[tab->total] = tab->makeNode(key, value);
  tab->total++;
}

Entry* getEntry(void* key, SymbolTable tab)
{
  int found = 0;
  int i;
  if(key == NULL)
    exit(1);
  for(i = 0; i< tab.total; i++)
    {
      if( tab.compare(key, tab.entries[i].key) == 0 )
	{
	return &tab.entries[i];
	found = 1;
	}
    }
  if(found == 0 )
    return NULL;
}

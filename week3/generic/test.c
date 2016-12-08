#include "gen.h"
#include<string.h>

main()
{
  Entry makePhone(void *name, void *phone)
  {
    Entry res;
    res.key = strdup( (char*) name);
    res.value = malloc ( sizeof(long));
    memcpy(res.value, phone, sizeof(long));
    return res;
  }

  int comparePhone(void *key1, void *key2)
  {
    return(strcmp((char*) key1, (char*) key2));
  }

  SymbolTable PhoneBook;
  PhoneBook = creatSymbolTable(makePhone, comparePhone);
  long number = 123456789;
  char name[] = "Ta Tuan Anh";
  addEntry(name, &number, &PhoneBook);
 
  return 0;
}

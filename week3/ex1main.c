#include "ex1.h"
#include "stdio.h"

main()
{
  int i;
  char s[80];
  long num;
  PhoneBook book1;
  PhoneEntry* temp;
  int choice;
  book1 = creatPhoneBook();
  do{
  printf("USER MENU \n");
  printf("1. Creat a phone book \n");
  printf("2. Delete phone book \n");
  printf("3. Add Phone Number \n");
  printf("4. Print List \n");
  printf("5. Get Phone Number \n");
  printf("6. Exit \n");
  scanf("%d", &choice);
  switch(choice)
    {
    case 1: 
      printf("Creatinn a phone book is done \n");
      book1 = creatPhoneBook();
      break;
    case 2:
      printf("Deletting all is done \n");
      dropPhoneBook(&book1);
      break;
    case 3:
      printf("Add phone number \n");
      printf("Input name\n");
      scanf("%s", s);
      printf("Input number\n");
      scanf("%ld", &num);
      addPhoneNumber(s, num, &book1);
      break;
    case 4:
      if(book1.total == 0)
	printf("Empty list \n");
      else
	for(i = 0; i < book1.total; i++)
	  {
	    printf("Name: %s\n", book1.entries[i].name);
	    printf("Number: %ld\n", book1.entries[i].number);
	  }
      break;
    case 5:
      printf("Get phone number \n");
      printf("Input a name \n");
      scanf("%s", s);
      temp = getPhoneNumber(s, book1);
      if(temp == NULL)
	printf(" **NOT FOUND \n");
      else 
	{
	  printf("Name: %s\n", s);
	  printf("Number: %ld\n", (*temp).number);
	}
      break;
    default:
      printf("Enter your choice again \n");
      break;
    }
  }while(choice != 6);

  return 0;
}


//version2 - menu_map.c

#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#define LINE_LEN 100
	#define CARRAY_LEN 5
	

	struct fun_desc
	{
	    char *name;
	    char (*fun)(char);
	};
	

	char *map(char *array, int array_length, char (*f)(char))
	{
	    char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
	    /* TODO: Complete during task 2.a */
	    for (int i = 0; i < array_length; i++)
	    {
	        mapped_array[i] = f(array[i]);
	    }
	    return mapped_array;
	}
	

	/* Ignores c, reads and returns a character from stdin using fgetc. */
	char my_get(char c)
	{
	    return fgetc(stdin); // Note that we lose some data here since EOF and character 255 will return the same result.
	}
	

	/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
	char cprt(char c)
	{
	    if (c >= 0x20 && c <= 0x7e)
	    {
	        printf("%c\n", c);
	    }
	    else
	    {
	        printf(".\n");
	    }
	

	    return c;
	}
	

	/* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. Otherwise return c unchanged */
	char encrypt(char c)
	{
	    if (c >= 0x20 && c <= 0x7e)
	    {
	        return c + 0x20;
	    }
	

	    return c;
	}
	

	/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. But if c was not between 0x40 and 0x7E it is returned unchanged */
	char decrypt(char c)
	{
	    if (c >= 0x40 && c <= 0x7E)
	    {
	        return c - 0x20;
	    }
	

	    return c;
	}
	

	/* xoprt prints the value of c in a hexadecimal representation, then in octal representation, followed by a new line, and returns c unchanged. */
	char xoprt(char c)
	{
	    printf("%hhx %hho\n", c, c);
	    return c;
	}
	

	void printMenu(struct fun_desc *menu)
	{
	    printf("Select operation from the following menu:\n");
	

	    for (int i = 0; menu[i].fun != NULL; i++)
	    {
	        printf("%d) %s\n", i, menu[i].name);
	    }
	

	    printf("Option : ");
	}
	

	int main()
	{
	    char *carray = (char *)malloc(CARRAY_LEN * sizeof(char));
	    carray[0] = '\0';
	    struct fun_desc menu[] = {
	        {"Get string", my_get},
	        {"Print string", cprt},
	        {"Encrypt", encrypt},
	        {"Decrypt", decrypt},
	        {"Print Hex and Octal", xoprt},
	        {NULL, NULL}};
	

	    int menuLen = 0; // TODO: Is it ok?
	    for (int i = 0; menu[i].fun != NULL; i++)
	    {
	        menuLen = i;
	    }
	

	    char line[LINE_LEN];
	    while (1)
	    {
	        printMenu(menu);
	        if (fgets(line, LINE_LEN, stdin) == NULL)
	        {
	            break;
	        }
	

	        int i = line[0] - '0';
	        if (i > menuLen)
	        {
	            printf("Not within bounds\n");
	            return 0;
	        }
	

	        printf("Within bounds\n");
	        char *result = map(carray, CARRAY_LEN, menu[i].fun);
	        free(carray);
	        carray = result;
	    }
	}



// version 3

//Makefile:
base : base.o 
    gcc -g -m32 -Wall -o base base.o

base.o: base.c
    gcc -g -m32 -Wall -c -o base.o base.c

addresses : addresses.o 
    gcc -g -m32 -Wall -o addresses addresses.o

addresses.o: addresses.c
    gcc -g -m32 -Wall -c -o addresses.o addresses.c

count-words : count-words.o 
    gcc -g -m32 -Wall -o count-words count-words.o

count-words.o: count-words.c
    gcc -g -m32 -Wall -c -o count-words.o count-words.c


  //count-words.c

  /* $Id: count-words.c 858 2010-02-21 10:26:22Z tolpin $ */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* return string "word" if the count is 1 or "words" otherwise */
char *words(int count)
{
  char *words = malloc(6); // allocate memory
  strcpy(words, "words"); // copys "words" to the allocated memory

  if (count == 1)
    words[strlen(words) - 1] = '\0';

  return words;
}

/* print a message reportint the number of words */
int print_word_count(char **argv)
{
  int count = 0;
  char **a = argv;
  while (*(a++))
    ++count;
  char *wordss = words(count);
  printf("The sentence contains %d %s.\n", count, wordss);
  
  free(wordss);
  return count;
}

/* print the number of words in the command line and return the number as the exit code */
int main(int argc, char **argv)
{
  print_word_count(argv + 1);
  return 0;
}


// addresses.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5;
int addr6;

int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();
char g = 'g';
void foo2();

int secondary(int x)
{
    int addr2;
    int addr3;
    char *yos = "ree";
    int *addr4 = (int *)(malloc(50));
    int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3];
    int iarray2[] = {1, 2, 3};
    char carray2[] = {'a', 'b', 'c'};
    int *iarray2Ptr;
    char *carray2Ptr;

    printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
    printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);

    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long)(&foo2 - &foo1));

    printf("Arrays Mem Layout (T1b):\n");

    /* task 1 b here */
    printf("address of iarray[0]: %p\n", &iarray[0]);
    printf("address of iarray[1]: %p\n", &iarray[1]);
    printf("address of iarray[2]: %p\n", &iarray[2]);
    printf("address of farray[0]: %p\n", &farray[0]);
    printf("address of farray[1]: %p\n", &farray[1]);
    printf("address of farray[2]: %p\n", &farray[2]);
    printf("address of darray[0]: %p\n", &darray[0]);
    printf("address of darray[1]: %p\n", &darray[1]);
    printf("address of darray[2]: %p\n", &darray[2]);
    printf("address of carray[0]: %p\n", &carray[0]);
    printf("address of carray[1]: %p\n", &carray[1]);
    printf("address of carray[2]: %p\n", &carray[2]);

    printf("address of iarray: %p\n", iarray);
    printf("address of iarray+1: %p\n", iarray + 1);
    printf("address of farray: %p\n", farray);
    printf("address of farray+1: %p\n", farray + 1);
    printf("address of darray: %p\n", darray);
    printf("address of darray+1: %p\n", darray + 1);
    printf("address of carray: %p\n", carray);
    printf("address of carray+1: %p\n", carray + 1);

    printf("Pointers and arrays (T1d): \n");

    /* task 1 d here */

    iarray2Ptr = iarray2;
    carray2Ptr = carray2;
    printf("value in iarray2[0] is: %d\n", *iarray2Ptr);
    printf("value in iarray2[1] is: %d\n", *(iarray2Ptr + 1));
    printf("value in iarray2[2] is: %d\n", *(iarray2Ptr + 2));
    printf("value in carray2[0] is: %c\n", *carray2Ptr);
    printf("value in carray2[1] is: %c\n", *(carray2Ptr + 1));
    printf("value in carray2[2] is: %c\n", *(carray2Ptr + 2));

    int *p;
    printf("printing a p pointer that is unintialized: %p\n", p);
}

int main(int argc, char **argv)
{

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);

    secondary(0);

    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here */

    for (int i = 0; i < argc; i++)
    {
        printf("the addsress of argv[%d] is : %p\n", i, argv + i);
        printf("the contant of argv[%d] is (which is address on itself) : %p\n", i, *(argv + i));
        printf("the sring value saved in argv[%d] is : %s\n", i, *(argv + i));
    }

    return 0;
}

void point_at(void *p)
{
    int local;
    static int addr0 = 2;
    static int addr1;

    long dist1 = (size_t)&addr6 - (size_t)p;
    long dist2 = (size_t)&local - (size_t)p;
    long dist3 = (size_t)&foo - (size_t)p;

    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);

    printf("Check long type mem size (T1a):\n");
    /* part of task 1 a here */
    printf("mem size of long: %u \n", sizeof(long));

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}







// base.c

  #include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *map(char *array, int array_length, char (*f)(char))
{
  char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
  /* TODO: Complete during task 2.a */

  for (int i = 0; i < array_length; i++)
  {
    mapped_array[i] = f(array[i]);
  }

  return mapped_array;
}

/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c)
{
  return fgetc(stdin);
}

/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
char cprt(char c)
{
  if (c >= 0x20 && c <= 0x7E)
    printf(" %c\n", c);
  else
    printf(".\n");

  return c;
}

/* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. Otherwise return c unchanged */
char encrypt(char c)
{
  if (c <= 0x20 && c >= 0x4E)
    c = c + 0x20;

  return c;
}

/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. But if c was not between 0x40 and 0x7E it is returned unchanged */
char decrypt(char c)
{
  if (c <= 0x40 && 0x7E)
  {
    c = c - 0x20;
  }
  return c;
}

/* xoprt prints the value of c in a hexadecimal representation, then in octal representation, followed by a new line, and returns c unchanged. */
char xoprt(char c)
{
  printf("%x , %o\n", c, c);
  return c;
}

int main(int argc, char **argv)
{
  /* TODO: Test your code */
 int base_len = 5;
char arr1[base_len];
char* arr2 = map(arr1, base_len, my_get);
char* arr3 = map(arr2, base_len, cprt);
char* arr4 = map(arr3, base_len, xoprt);
char* arr5 = map(arr4, base_len, encrypt);
free(arr2);
free(arr3);
free(arr4);
free(arr5);
}







// makefile(task3)

menu_map : menu_map.o 
    gcc -g -m32 -Wall -o menu_map menu_map.o

menu_map.o: menu_map.c
    gcc -g -m32 -Wall -c -o menu_map.o menu_map.c





  //menu_map.c

  #include <stdio.h>

/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c)
{
  return fgetc(stdin);
}

/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
char cprt(char c)
{
  if (c >= 0x20 && c <= 0x7E)
    printf(" %c\n", c);
  else
    printf(".\n");

  return c;
}

/* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. Otherwise return c unchanged */
char encrypt(char c)
{
  if (c <= 0x20 && c >= 0x4E)
    c = c + 0x20;

  return c;
}

/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. But if c was not between 0x40 and 0x7E it is returned unchanged */
char decrypt(char c)
{
  if (c <= 0x40 && 0x7E)
  {
    c = c - 0x20;
  }
  return c;
}

/* xoprt prints the value of c in a hexadecimal representation, then in octal representation, followed by a new line, and returns c unchanged. */
char xoprt(char c)
{
  printf("%x , %o\n", c, c);
  return c;
}

//int main()
//{
//  printf("Select operation from the following menu: \n");
//}

int main()
{
    char buffer[256];
    while (1)
    {
        printf("Select operation from the following menu:\n");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("EOF encountered, exiting...\n");
            break;
        }
        printf("You entered: %s\n", buffer);
    }
    return 0;
}




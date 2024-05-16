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

void print(void* arr, const char* typeArr) {
    printf("Memory addresses of %s array:\n", typeArr);
    for (int i = 0; i < 3; i++) {
        printf("&%s[%d]: %p\n", typeArr, i, &arr[i]); 
    }
}


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
	int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr;
    char* carray2Ptr; 
    
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
    printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");

    /* task 1 b here-------------------------------------- */
    print(iarray, "int");
    print(farray, "float");
    print(darray, "double");
    print(carray, "char");

    printf("Hexadecimal values of pointers:\n");
    printf("iarray:       %p\n", (void*)iarray);
    printf("iarray+1:     %p\n", (void*)(iarray + 1));
    printf("farray:       %p\n", (void*)farray);
    printf("farray+1:     %p\n", (void*)(farray + 1));
    printf("darray:       %p\n", (void*)darray);
    printf("darray+1:     %p\n", (void*)(darray + 1));
    printf("carray:       %p\n", (void*)carray);
    printf("carray+1:     %p\n", (void*)(carray + 1));
    // The '+' operator increments the pointer by the size of the type it points to.
    // For <type> arrays, each element is sizeof(<type>) bytes long.
    // -----------------------

    /* task 1 c here-------------------------------------- */
    // The distances printed in the point_at function represent the difference between the memory
    // address of certain variables and the memory address passed as an argument p.
    //-----------------------
    
    printf("Pointers and arrays (T1d): ");

    /* task 1 d here-------------------------------------- */
    iarray2Ptr = iarray2;
    carray2Ptr = carray2;
    printf("\n");

    printf("Values of iarray2: ");
    while (iarray2Ptr < iarray2 + (sizeof(iarray2) / sizeof(iarray2[0]))) {
        printf("%d ", *iarray2Ptr); 
        iarray2Ptr++;
    }
    printf("\n");

    printf("Values of carray2: ");
    while (carray2Ptr < carray2 + (sizeof(carray2) / sizeof(carray2[0]))) { 
        printf("%c ", *carray2Ptr); 
        carray2Ptr++;
    }
    printf("\n");

    int* p; // uninitialized pointer variable
    printf("Value of uninitialized pointer p: %p\n", p); // it changes every time
    //-----------------------

}


int main(int argc, char **argv)
{ 

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);
	
	secondary(0);
    

    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here-------------------------------------- */
    printf("Address of argv: %p\n", (void*)&argv);
    
    for (int i = 0; i < argc; i++) {
        printf("Address of argv[%d]: %p, Content: %s\n", i, (void*)&argv[i], argv[i]);
    }
    // stored on the stack. The memory location of argv itself points to a location on the stack
    //-----------------------
    
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
    /* part of task 1 a here-------------------------------------- */
    printf("Size of long data type: %zu bytes\n", sizeof(long));
    // -----------------------


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
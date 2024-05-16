#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    /* TODO: Complete during task 2.a */
    for (int i = 0 ; i < array_length ; i++){
        mapped_array[i] = f(array[i]);  
    }
    return mapped_array;
}

char return_T(char c) {
    printf("%c\n", 'T');
    return 'T';
}


char my_get(char c) {
    /* Ignores c, reads and returns a character from stdin using fgetc. */
    return fgetc(stdin);
}

char cprt(char c) {
    /* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line.
    Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
    if (c >= 0x20 && c <= 0x7E) {
        printf("%c\n", c);
    } else {
        printf("%c\n",'.');
    }
    return c;
}

char encrypt(char c) {
    /* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. Otherwise return c unchanged */
    if (c >= 0x20 && c <= 0x4E) {
        return c + 0x20;
    } else {
        return c;
    }
}

char decrypt(char c) {
    /* Gets a char c and returns its decrypted form subtractng 0x20 from its value.
    But if c was not between 0x40 and 0x7E it is returned unchanged */
    if (c >= 0x40 && c <= 0x7E) {
        return c - 0x20;
    } else {
        return c;
    }
}

char xoprt(char c) {
    /* xoprt prints the value of c in a hexadecimal representation, then in octal representation,
    followed by a new line, and returns c unchanged. */
    printf("%x %03o\n", c, c);
    return c;
}
 
int main(int argc, char **argv){
    // /* TODO: Test your code */
    // char arr1[] = {'H','E','Y','!'};
    // // char* arr2 = map(arr1, 4, return_T);
    // char* arr2 = map(arr1, 4, xoprt);

    // /* Print the mapped array */
    // printf("Mapped array: ");
    // for (int i = 0; i < 4; i++) {
    //     printf("%d ", arr2[i]);
    // }
    // printf("\n");

    // /* Free the dynamically allocated memory */
    // free(arr2);

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
    
    return 0;
}



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
        printf(".\n");
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

struct fun_desc {
    char *name;
    char (*fun)(char);
};

// void print_menu() {
//     printf("Select operation from the following menu (ctrl^D for exit):\n");
//     printf("0)  Get string\n");
//     printf("1)  Print string\n");
//     printf("2)  Encrypt\n");
//     printf("3)  Decrypt\n");
//     printf("4)  Print Hex and Octal\n");
// }
 
int main(int argc, char **argv){
    // /* TODO: Test your code */
    // test 1: -------------------------------
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

    // test 2: -------------------------------
    // int base_len = 5;
    // char arr1[base_len];
    // char* arr2 = map(arr1, base_len, my_get);
    // char* arr3 = map(arr2, base_len, cprt);
    // char* arr4 = map(arr3, base_len, xoprt);
    // char* arr5 = map(arr4, base_len, encrypt);
    // free(arr2);
    // free(arr3);
    // free(arr4);
    // free(arr5);


    // Task 3: 

    // char* input;
    // int choice;

    // while (1) {
    //     print_menu();
    //     printf("Enter your choice: ");

    //     if (fgets(input, sizeof(input), stdin) == NULL) {
    //         break; 
    //     }

    //     // Convert input to integer
    //     choice = atoi(input);

    //     switch (choice) {
    //         case 1:
    //             printf("Performing Option 1...\n");
    //             break;
    //         case 2:
    //             printf("Performing Option 2...\n");
    //             break;
    //         case 3:
    //             printf("Performing Option 3...\n");
    //             break;
    //         case 4:
    //             printf("Performing Option 4...\n");
    //             break;
    //         default:
    //             printf("Invalid choice. Please enter a number from 1 to 4.\n");
    //             break;
    //     }
    // }

    // printf("EOF encountered. Exiting program...\n");

    char carray[5] = "";
    int choice;

    struct fun_desc menu[] = {
        {"Get String", my_get},
        {"Print String (cprt)", cprt},
        {"Encrypt", encrypt},
        {"Decrypt", decrypt},
        {"Print Hex (xprt)", xoprt},
        {NULL, NULL}
    };

    // Main menu loop
    while (1) {

        printf("Select operation from the following menu:\n");
        for (int i = 0; menu[i].name != NULL; i++) {
            printf("%d) %s\n", i, menu[i].name);
        }
        printf("Option: ");

        if (scanf("%d", &choice) != 1) {
            if (feof(stdin)) {
                printf("\nEOF detected. Exiting...\n");
                break;
            } else {
                printf("\nInvalid input. Exiting...\n");
                break;
            }
        }

        if (choice < 0 || menu[choice].name == NULL) {
            printf("Not within bounds.\n");
            break;
        }

        printf("Within bounds\n");
        char *result = map(carray, 5, menu[choice].fun);
        // carray = map(carray, 5, menu[choice].fun);

        strncpy(carray, result, 5);
        free(result);
    }


    return 0;
}



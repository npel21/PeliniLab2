#include <iostream>

// data     - global / static variables with predefined value
// text     - executable code; read-only variables and constants
// bss      - unitialized (or 0) data
// heap     - allocated memory (malloc, free, etc)
// stack    - LIFO; initialized local function variables; function arguments

// Type                                             Size
// bool, char, unsigned char, signed char           1 byte
// short, unsigned short                            2 bytes
// float, int, unsigned int, long, unsigned long    4 bytes
// double, long double, long long                   8 bytes

// An local array will usually be created on stack
// A global or static array will usually be created on bss/data segments
// A dynamically created array will be created on heap

// 12 bytes stored in bss
int bss1, bss2, bss3;

// 3 bytes stored in bss
char bss4, bss5, bss6;


// Copies 12 bytes from the BSS section of the program to the stack.
void stackVariables() {
    // Automatic variables stored on stack
    int stack1 = 1;
    int stack2 = 2;
    int stack3 = 3;
    // Copy data from bss to stack
    stack1 = bss1;
    stack2 = bss2;
    stack3 = bss3;
    printf("stackVars %d %d %d\n\n", stack1, stack2, stack3);
}


int main() {
    
    /* 1. Copies 12 bytes from the BSS section of the program to the stack. */
    stackVariables();
    
    /* 2. Copies 13 bytes from the heap to the data section. */
    // Create 13 bytes of data
    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
    // Create array on heap and initialize data
    char *heapArray = new char[14]();
    for(int i = 0; i < 14; i++) {
        heapArray[i] = 'a';
        printf("heapArray[%d] = %c\n", i, heapArray[i]);

    }
    // Copy 13 bytes from heap to data
    c1 = heapArray[0];
    c2 = heapArray[1];
    c3 = heapArray[2];
    c4 = heapArray[3];
    c5 = heapArray[4];
    c6 = heapArray[5];
    c7 = heapArray[6];
    c8 = heapArray[7];
    c9 = heapArray[8];
    c10 = heapArray[9];
    c11 = heapArray[10];
    c12 = heapArray[11];
    c13 = heapArray[12];
    printf("cs: %c %c %c %c \n\n", c1, c2, c3, c4);
    
    /* 3. Copies 14 bytes from the stack to the heap. */
    // Create 14 bytes of data on stack
    char stackArray[14] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
    // Copy data from stack to heap
    for(int j = 0; j < 14; j++) {
        heapArray[j] = stackArray[j];
        printf("heapArray[%d] = %c\n", j, heapArray[j]);
    }
    
    /* 4. Copies 15 bytes from the data section to the BSS. */
    // Create 12 bytes of data
    int data1 = 1, data2 = 2, data3 = 3;
    // Copy 12 bytes from data to BSS
    bss1 = data1;
    bss2 = data2;
    bss3 = data3;
    // Copy 3 bytes from data to BSS
    bss4 = c1;
    bss5 = c2;
    bss6 = c3;
    printf("\ndatas: %d %d %d ; cs: %c %c %c\n\n", bss1, bss2, bss3, c1, c2, c3);

    /* 5. Copies 4 bytes from the text section to the data section. */
    // Const variable is stored in text memory
    const int textInt = 4;
    int dataInt = 2;
    // Copy 4 bytes from text to data
    printf("%d\n", dataInt);
    dataInt = textInt;
    printf("%d\n", dataInt);

    // Free dynamic memory
    delete [] heapArray;
    
    return 0;
}

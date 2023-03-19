#include <stdio.h> 
#include <stdlib.h> 

main(){ 

    // define pointer
    char *pblok; 

    // allocate a memory by the size of 500 byte
    pblok = (char *) malloc(500 * sizeof(char)); 
    
    if (pblok == NULL) 
        puts("Error on malloc"); 
    else { 
        puts("OK, alokasi memory sudah dilakukan"); puts("------"); 

        // release the memory address allocated and pointed by pblok
        free(pblok); 

        // set the pointer to NULL so it doesnt point to unexisted address
        pblok = NULL; 
        puts("Blok memory telah dibebaskan kembali"); 
        puts("dan pointernya sdh di-groundkan"); 
    } 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// define struct
typedef struct employee_st { 
    char name[40]; 
    int id; 
} Employee;

main() 
{ 
    // define struct variable
    Employee *workers, *wpt; 
    int num, i; 

    // input employees total
    printf("How many employees do you want ? ");
    scanf("%d",&num); 

    // allocate a memory address by the size of how much employees
    workers = (Employee *) malloc(num * sizeof(Employee));

    if (workers == NULL) { 
        printf("Unable to allocated space for employees\n"); exit(0); 
    } 

    // assign address pointed by workers to wpt
    wpt = workers; 

    // loop employee data input
    for(i=1; i<=num; i++) { 
        fflush(stdin); 

        // input employee name
        printf("Employee's name : "); 
        gets(wpt->name); 
        
        // input employee id
        printf("Employee's id : "); 
        scanf("%d", &wpt->id); 

        // increment the address
        wpt++; 
    }

    puts(""); 

    // reassign wpt with the address pointed by workers
    wpt = workers;
    
    // loop wpt to show the value of adrress pointed by wpt
    for(i=1; i<=num; i++) { 
        printf("Employee %d is %s\n", wpt->id, wpt->name);
        wpt++; 
    } 
    
    // release the address pointed by workers and ground the pointer
    free(workers); 
    workers = NULL; 
}

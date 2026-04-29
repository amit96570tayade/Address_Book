#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook);

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                int sortChoice;
                printf("\nSorting Choices:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("\nEnter your choice: ");
                scanf("%d", &sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("\nSaving and Exiting...\n");
                saveAndExit(&addressBook);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
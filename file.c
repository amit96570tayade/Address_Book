#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {

    FILE *fptr = fopen("contacts.txt", "w");
    if(fptr == NULL)
    {
        perror("");
        return;
    }
    for(int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fptr, "%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fptr);
    printf("\n%d contacts saved successfully\n", addressBook->contactCount);
}

void loadContactsFromFile(AddressBook *addressBook) {

    FILE *fptr = fopen("contacts.txt", "r");
    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
        printf("\nFile is empty\n");
        fclose(fptr);
        return;
    }
    rewind(fptr);
    while(fscanf(fptr, " %[A-Za-z ] %s %s", addressBook->contacts[addressBook->contactCount].name, addressBook->contacts[addressBook->contactCount].phone, addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
        if(addressBook->contactCount >= MAX_CONTACTS)
            break;
    }
    fclose(fptr);
    printf("\n%d contacts loaded successfully\n", addressBook->contactCount);
}
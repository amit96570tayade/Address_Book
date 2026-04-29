#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void sortByName(AddressBook *addressBook) {
    for(int i = 0; i < addressBook->contactCount - 1; i++) {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
            if(strcasecmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) {
                Contact tempContact = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = tempContact;
            }
        }
    }
    printf("\nSorted names: \n");
    for(int i = 0; i < addressBook->contactCount; i++) {
        printf("%s\n", addressBook->contacts[i].name);
    }
}

void sortByPhone(AddressBook *addressBook) {
    for(int i = 0; i < addressBook->contactCount - 1; i++) {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
            if(strcasecmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) {
                Contact tempContact = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = tempContact;
            }
        }
    }
    printf("\nSorted phone numbers: \n");
    for(int i = 0; i < addressBook->contactCount; i++) {
        printf("%s\n", addressBook->contacts[i].phone);
    }
}

void sortByEmail(AddressBook *addressBook) {
    for(int i = 0; i < addressBook->contactCount - 1; i++) {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
            if(strcasecmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) {
                Contact tempContact = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = tempContact;
            }
        }
    }
    printf("\nSorted email ID's: \n");
    for(int i = 0; i < addressBook->contactCount; i++) {
        printf("%s\n", addressBook->contacts[i].email);
    }
}

void listContacts(AddressBook *addressBook, int sortCriteria) {
    switch(sortCriteria) {
        case 1:
            sortByName(addressBook);
            break;
        case 2:
            sortByPhone(addressBook);
            break;
        case 3:
            sortByEmail(addressBook);
            break;
        default:
            printf("\nInvalid Choice. Please try again.\n");
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void createContact(AddressBook *addressBook) {
    if(addressBook->contactCount >= MAX_CONTACTS) {
        return;
    }
    int i = 0, j = 0;
    int onlyAlpha = 0, onlyDigit = 0, validEmail = 0;
    Contact newContact;
    printf("\nEnter name: ");
    scanf(" %[^\n]", newContact.name);
    while(newContact.name[i] != '\0') {
        if(!isalpha(newContact.name[i]) && !isspace(newContact.name[i])) {
            onlyAlpha = 1;
            break;
        }
        i++;
    }
    if(onlyAlpha == 1) {
        printf("\nInvalid Name! Name should contain only alphabets (a - z) or (A - Z)\n");
        return;
    }
    printf("Enter mobile number: ");
    scanf(" %[^\n]", newContact.phone);
    while(newContact.phone[j] != '\0') {
        if(!isdigit(newContact.phone[j])) {
            onlyDigit = 1;
            break;
        }
        j++;
    }
    if(onlyAlpha == 1 || j != 10) {
        printf("\nInvalid Phone! Phone should contain 10 DIGIT'S\n");
        return;
    }
    printf("Enter email: ");
    scanf(" %[^\n]", newContact.email);
    if(strchr(newContact.email, '@') != NULL && strchr(newContact.email, '.') != NULL) {
        validEmail = 1;
    }
    if(validEmail == 0)
        printf("\nInvalid Email! Email should contain '@' and '.'\n");
    addressBook->contacts[addressBook->contactCount] = newContact;
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) {
    char str[50];
    int found = 0;
    int searchChoice;
    printf("\nSearching Choices: \n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);
    switch(searchChoice) {
        case 1:
            printf("\nEnter name: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].name, str) != NULL) {
                    printf("\nContact found!\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found.\n");
            break;
        case 2:
            printf("\nEnter phone: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].phone, str) != NULL) {
                    printf("\nContact found!\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    found =1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        case 3:
            printf("\nEnter email: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].email, str) != NULL) {
                    printf("\nContact found!\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        default:
            printf("\nInvalid Choice. Please try again.\n");
    }
}

void editContact(AddressBook *addressBook) {
    char str[50];
    int found = 0;
    int editChoice;
    printf("\nEditing Choices: \n");
    printf("1. Edit Name\n");
    printf("2. Edit Phone\n");
    printf("3. Edit Email\n");
    printf("\nEnter your choice: ");
    scanf("%d", &editChoice);
    switch(editChoice) {
        case 1:
            printf("\nEnter name to search for the contact to edit: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].name, str) != NULL) {
                    printf("\nEnter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", addressBook->contacts[i].phone);
                    printf("Enter new email: ");
                    scanf(" %[^\n]", addressBook->contacts[i].email);
                    printf("\nContact updated successfully\n");
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        case 2:
            printf("\nEnter phone to search for the contact to edit: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].phone, str) != NULL) {
                    printf("\nEnter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", addressBook->contacts[i].phone);
                    printf("Enter new email: ");
                    scanf(" %[^\n]", addressBook->contacts[i].email);
                    printf("\nContact updated successfully\n");
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        case 3:
            printf("\nEnter email to search for the contact to edit: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].email, str) != NULL) {
                    printf("\nEnter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", addressBook->contacts[i].phone);
                    printf("Enter new email: ");
                    scanf(" %[^\n]", addressBook->contacts[i].email);
                    printf("\nContact updated successfully\n");
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}

void deleteContact(AddressBook *addressBook) {
    char str[50];
    int found = 0;
    int deleteChoice;
    printf("\nDeleting Choices: \n");
    printf("1. Delete By Name\n");
    printf("2. Delete By Phone\n");
    printf("3. Delete By Email\n");
    printf("\nEnter your choice: ");
    scanf("%d", &deleteChoice);
    switch(deleteChoice) {
        case 1:
            printf("\nEnter name to delete: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].name, str) != NULL) {
                    found = 1;
                    for(int j = i; j < addressBook->contactCount - 1; j++) {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    printf("\nContact deleted successfully\n");
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        case 2:
            printf("\nEnter phone to delete: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].phone, str) != NULL) {
                    found = 1;
                    for(int j = i; j < addressBook->contactCount - 1; j++) {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    printf("\nContact deleted successfully\n");
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        case 3:
            printf("\nEnter email to delete: ");
            scanf(" %[^\n]", str);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strcasestr(addressBook->contacts[i].email, str) != NULL) {
                    found = 1;
                    for(int j = i; j < addressBook->contactCount - 1; j++) {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    printf("\nContact deleted successfully\n");
                    break;
                }
            }
            if(found == 0)
                printf("\nContact not found\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}
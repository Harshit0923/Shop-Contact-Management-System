#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    char type;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

/* Insert  */
void insertRecord() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter phone: ");
    scanf("%s", newNode->phone);
    printf("Enter type: ");
    scanf(" %c", &newNode->type);

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

/* Display */
void showRecords() {
    struct Node *temp = head;
     if(head == NULL) {
        printf("No records found.\n");
        return;
    }

    while (temp != NULL) {
        printf("\nName: %s\nPhone: %s\nType: %c\n",
               temp->name, temp->phone, temp->type);
        temp = temp->next;
    }
}

/* Search  */
void findRecord() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    struct Node *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s\n%s\n%c\n",
                   temp->name, temp->phone, temp->type);
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

/* Delete */
void removeRecord() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    struct Node *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Deleted\n");
            return;
        }
        temp = temp->next;
    }
}

/* Filter  */
void filterType() {
    char t;
    printf("Enter type: ");
    scanf(" %c", &t);

    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->type == t) {
            printf("%s - %s\n", temp->name, temp->phone);
        }
        temp = temp->next;
    }
}

int main() {
    int ch;

    do {
        printf("------Business Conatacts Management System------\n");
        printf("\n1.Add\n2.Display\n3.Search\n4.Delete\n5.Filter\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: insertRecord();
            break;
            case 2: showRecords();
            break;
            case 3: findRecord();
            break;
            case 4: removeRecord();
            break;
            case 5: filterType();
            break;
            case 6: printf("Thank You!\n");
            break;
            default: printf("Invalid choice!\n");
        }

    } while(ch != 6);

    return 0;
}

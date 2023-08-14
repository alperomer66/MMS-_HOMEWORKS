#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

struct Book {
    char title[151];
    char author[101];
    int pages;
    float price;
    struct Book* next;
};

typedef struct Book Book;

void generateRandomData(Book* book) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";// tuk ne znaeh kak da vzema ot A-Z  i a-z za tova gi pisah na ruka 
    const int minTitleLength = 10;
    const int maxTitleLength = 20;
    const int minPages = 5;
    const int maxPages = 2000;
    const float minPrice = 1.0;
    const float maxPrice = 1000.0;

    int titleLength = minTitleLength + rand() % (maxTitleLength - minTitleLength + 1);
    for (int i = 0; i < titleLength; ++i) {
        book->title[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    book->title[titleLength] = '\0';

    int authorLength = minTitleLength + rand() % (maxTitleLength - minTitleLength + 1);
    for (int i = 0; i < authorLength; ++i) {
        book->author[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    book->author[authorLength] = '\0';

    book->pages = minPages + rand() % (maxPages - minPages + 1);
    book->price = minPrice + ((float)rand() / RAND_MAX) * (maxPrice - minPrice);
}

void insertBook(Book** list, Book* book) {
    if (*list == NULL || strcmp(book->title, (*list)->title) < 0) {
        book->next = *list;
        *list = book;
    } else {
        Book* current = *list;
        while (current->next != NULL && strcmp(book->title, current->next->title) > 0) {
            current = current->next;
        }
        book->next = current->next;
        current->next = book;
    }
}

void printBooks(Book* list) {
    printf("%-25s %-15s %-10s %-10s\n", "Title", "Author", "Pages", "Price");
    printf("----------------------------------------------------\n");

    Book* current = list;
    while (current != NULL) {
        printf("%-25s %-15s %-10d %-10.2f\n", current->title, current->author, current->pages, current->price);
        current = current->next;
    }
}

void freeBooks(Book* list) {
    while (list != NULL) {
        Book* temp = list;
        list = list->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));

    Book* bookList = NULL;

    for (int i = 0; i < COUNT; ++i) {
        Book* newBook = (Book*)malloc(sizeof(Book));
        generateRandomData(newBook);
        newBook->next = NULL;

        insertBook(&bookList, newBook);
    }

    printBooks(bookList);

    freeBooks(bookList);

    return 0;
}

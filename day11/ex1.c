#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

typedef struct Book {
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;

int compareTitlesAsc(const void* a, const void* b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int compareTitlesDesc(const void* a, const void* b) {
    return strcmp(((Book*)b)->title, ((Book*)a)->title);
}

int compareAuthorsAsc(const void* a, const void* b) {
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

int compareAuthorsDesc(const void* a, const void* b) {
    return strcmp(((Book*)b)->author, ((Book*)a)->author);
}

int comparePagesAsc(const void* a, const void* b) {
    return ((Book*)a)->pages - ((Book*)b)->pages;
}

int comparePagesDesc(const void* a, const void* b) {
    return ((Book*)b)->pages - ((Book*)a)->pages;
}

int comparePriceAsc(const void* a, const void* b) {
    return (((Book*)a)->price > ((Book*)b)->price) ? 1 : -1;
}

int comparePriceDesc(const void* a, const void* b) {
    return (((Book*)a)->price < ((Book*)b)->price) ? 1 : -1;
}

void generateRandomBook(Book* book) {
    char title[21];
    char author[21];

    for (int i = 0; i < 20; i++) {
        title[i] = 'a' + (rand() % 26);
        author[i] = 'a' + (rand() % 26);
    }
    title[20] = '\0';
    author[20] = '\0';

    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = rand() % 1996 + 5;
    book->price = (double)(rand() % 100000) / 100.0;
}

void printBooks(Book* books, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("Title: %s, Author: %s, Pages: %d, Price: %.2f\n",
        books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}

int main() {
    srand(time(NULL));

    Book books[COUNT];
    for (int i = 0; i < COUNT; i++) {
        generateRandomBook(&books[i]);
    }

    printf("Unsorted books:\n");
    printBooks(books, COUNT);
    printf("\n");

    
    qsort(books, COUNT, sizeof(Book), compareTitlesAsc);
    printf("Books sorted by title (ASC):\n");
    printBooks(books, COUNT);
    printf("\n");


    qsort(books, COUNT, sizeof(Book), compareAuthorsDesc);
    printf("Books sorted by author (DESC):\n");
    printBooks(books, COUNT);
    printf("\n");

    
    qsort(books, COUNT, sizeof(Book), comparePagesAsc);
    printf("Books sorted by pages (ASC):\n");
    printBooks(books, COUNT);
    printf("\n");

    
    qsort(books, COUNT, sizeof(Book), comparePriceDesc);
    printf("Books sorted by price (DESC):\n");
    printBooks(books, COUNT);

    return 0;
}

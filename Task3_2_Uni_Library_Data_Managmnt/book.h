#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdbool.h>

// Define the Book structure
struct Book
{
    char title[100];
    char author[100];
    char ISBN[20];
    int pub_year;
    char genre[50];
    int avail_copies;
};

// Static inline function to print book details
static inline void print_book_details(const struct Book *book)
{
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("ISBN: %s\n", book->ISBN);
    printf("Publication Year: %d\n", book->pub_year);
    printf("Genre: %s\n", book->genre);
    printf("Available Copies: %d\n", book->avail_copies);
}

// Static inline function to check if the book is available
static inline bool is_book_available(const struct Book *book)
{
    return book->avail_copies > 0;
}

#endif // BOOK_H

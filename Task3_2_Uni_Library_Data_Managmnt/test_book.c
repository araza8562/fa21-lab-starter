#include "book.h"

int main()
{
    // Test Case 1
    struct Book book1 = {
        "The Great Gatsby",
        "F. Scott Fitzgerald",
        "9780743273565",
        1925,
        "Fiction",
        5};
    printf("Test Case 1:\n");
    print_book_details(&book1);
    if (is_book_available(&book1))
    {
        printf("Yes, the book is available.\n");
    }
    else
    {
        printf("No, the book isn't available.\n");
    }
    printf("\n");

    // Test Case 2
    struct Book book2 = {
        "1984",
        "George Orwell",
        "9780451524935",
        1949,
        "Dystopian",
        0};
    printf("Test Case 2:\n");
    print_book_details(&book2);
    if (is_book_available(&book2))
    {
        printf("Yes, the book is available.\n");
    }
    else
    {
        printf("No, the book isn't available.\n");
    }
    printf("\n");

    // Test Case 3
    struct Book book3 = {
        "To Kill a Mockingbird",
        "Harper Lee",
        "9780060935467",
        1960,
        "Fiction",
        2};
    printf("Test Case 3:\n");
    print_book_details(&book3);
    if (is_book_available(&book3))
    {
        printf("Yes, the book is available.\n");
    }
    else
    {
        printf("No, the book isn't available.\n");
    }
    printf("\n");

    // Test Case 4
    struct Book book4 = {
        "The Catcher in the Rye",
        "J.D. Salinger",
        "9780316769488",
        1951,
        "Fiction",
        10};
    printf("Test Case 4:\n");
    print_book_details(&book4);
    if (is_book_available(&book4))
    {
        printf("Yes, the book is available.\n");
    }
    else
    {
        printf("No, the book isn't available.\n");
    }
    printf("\n");

    // Test Case 5
    struct Book book5 = {
        "Moby Dick",
        "Herman Melville",
        "9781503280786",
        1851,
        "Adventure",
        1};
    printf("Test Case 5:\n");
    print_book_details(&book5);
    if (is_book_available(&book5))
    {
        printf("Yes, the book is available.\n");
    }
    else
    {
        printf("No, the book isn't available.\n");
    }
    printf("\n");

    return 0;
}

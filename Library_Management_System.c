#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char book_name[50];
    char book_author[50];
    int number_of_pages;
    float price;
    int publication_year;
    char publisher[50];
};

void add_book(struct book **, int, char *, char *, int, float, int, char *);
int search_book(struct book **, int, char *);
void view_book_details(struct book **, int, char *);
void view_book_details_by_same_author(struct book **, int, char *);
void delete_book(struct book **, int, char *);

int main()
{
    struct book **library;
    library=(struct book **)malloc(100*sizeof(struct book *));
    int total_books=0;
    int flag=0;
    while(flag==0)
    {
        printf("Please choose from the cases below\n");
        printf("Case 1: Add a book\n");
        printf("Case 2: Search for a book\n");
        printf("Case 3: View Book Details\n");
        printf("Case 4: Display list of books written by the same author\n");
        printf("Case 5: Remove a book\n");
        printf("Case 6: View total number of books in the library\n");
        printf("Case 7: Exit\n");
        int ch;
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\n");
                char title[50];
                getchar();
                printf("Enter the name of the book : ");
                gets(title);
                if(search_book(library, total_books, title)==-1)
                {
                    char author[50];
                    printf("Enter the author of the book : ");
                    gets(author);
                    int num;
                    printf("Enter the number of pages in the book : ");
                    scanf("%d",&num);
                    float price;
                    printf("Enter the price of the book : Rs. ");
                    scanf("%f",&price);
                    int pub_year;
                    printf("Enter the publication year of the book : ");
                    scanf("%d",&pub_year);
                    getchar();
                    char pub_name[50];
                    printf("Enter the name of the publisher : ");
                    gets(pub_name);
                    add_book(library, total_books, title, author, num, price, pub_year, pub_name);
                    total_books++;
                    printf("\n");
                    printf("Book added successfully\n");
                }
                else
                {
                    printf("Book is already present\n");
                }
                printf("\n");
                break;
            }
            case 2:
            {
                printf("\n");
                getchar();
                char title[50];
                printf("Enter the name of the book : ");
                gets(title);
                int x=search_book(library, total_books, title);
                if(x==-1)
                {
                    printf("\n");
                    printf("Book is not present in the library\n");
                }
                else
                {
                    printf("\n");
                    printf("Book is present in the library\n");
                }
                printf("\n");
                break;
            }
            case 3:
            {
                printf("\n");
                getchar();
                char title[50];
                printf("Enter the name of the book : ");
                gets(title);
                int x=search_book(library, total_books, title);
                if(x==-1)
                {
                    printf("\n");
                    printf("Book is not present in the library\n");
                }
                else
                {
                    view_book_details(library, total_books, title);
                }
                printf("\n");
                break;
            }
            case 4:
            {
                printf("\n");
                getchar();
                char author[50];
                printf("Enter the name of the author : ");
                gets(author);
                int x=search_book(library, total_books,author);
                view_book_details_by_same_author(library, total_books, author);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\n");
                getchar();
                char title[50];
                printf("Enter the name of the book : ");
                gets(title);
                int x=search_book(library, total_books, title);
                if(x==-1)
                {
                    printf("\n");
                    printf("Book is not present in the library\n");
                }
                else
                {
                    delete_book(library, total_books, title);
                    total_books--;
                    printf("\n");
                    printf("Book Deleted Successfully\n");
                }
                printf("\n");
                break;
            }
            case 6:
            {
                printf("\n");
                printf("Total number of books in the library : %d\n", total_books);
                printf("\n");
                break;
            }
            case 7:
            {
                printf("\n");
                printf("Thank You\n");
                flag=1;
                printf("\n");
                break;
            }
            default:
            {
                printf("\n");
                printf("Wrong choice enterd\n");
                printf("\n");
                break;
            }
        }
    }
    free(library);
    return 0;
}

void add_book(struct book **library, int total_books, char *title, char *author, int pages, float price, int pub_year, char *pub_name)
{
    *(library+total_books)=(struct book *)malloc(sizeof(struct book));
    strcpy((*(library+total_books))->book_name, title);
    strcpy((*(library+total_books))->book_author, author);
    (*(library+total_books))->number_of_pages=pages;
    (*(library+total_books))->price=price;
    (*(library+total_books))->publication_year=pub_year;
    strcpy((*(library+total_books))->publisher, pub_name);
}

int search_book(struct book **library, int total_books, char *title)
{
    for(int i=0;i<total_books;i++)
    {
        char *name;
        name=(*(library+i))->book_name;
        if(strcmp(name, title)==0)
        {
            return i;
        }
    }
    return -1;
}

void view_book_details(struct book **library, int total_books, char *title)
{
    printf("\n");
    printf("\n");
    for(int i=0;i<total_books;i++)
    {
        char *name;
        name=(*(library+i))->book_name;
        if(strcmp(name, title)==0)
        {
            printf("Name of the book : %s\n", (*(library+i))->book_name);
            printf("Author of the book : %s\n", (*(library+i))->book_author);
            printf("Number of pages in the book : %d\n", (*(library+i))->number_of_pages);
            printf("Price of the book : Rs. %.2f\n", (*(library+i))->price);
            printf("Publishing year of the book : %d\n", (*(library+i))->publication_year);
            printf("Publisher of the book : %s\n", (*(library+i))->publisher);
            printf("\n");
            printf("\n");
            return;
        }
    }
    return;
}

void view_book_details_by_same_author(struct book **library, int total_books, char *author)
{
    printf("\n");
    printf("\n");
    int count=0;
    for(int i=0;i<total_books;i++)
    {
        char *auth;
        auth=((*(library+i))->book_author);
        if(strcmp(auth, author)==0)
        {
            printf("Name of the book : %s\n", (*(library+i))->book_name);
            printf("Author of the book : %s\n", (*(library+i))->book_author);
            printf("Number of pages in the book : %d\n", (*(library+i))->number_of_pages);
            printf("Price of the book : Rs. %.2f\n", (*(library+i))->price);
            printf("Publishing year of the book : %d\n", (*(library+i))->publication_year);
            printf("Publisher of the book : %s\n", (*(library+i))->publisher);
            printf("\n");
            printf("\n");
            count++;
        }
    }
    if(count==0)
    {
        printf("No books by the said author found\n");
    }
    return;
}

void delete_book(struct book **library, int total_books, char *title)
{
    for(int i=0;i<total_books;i++)
    {
        char *name;
        name=(*(library+i))->book_name;
        if(strcmp(title, name)==0)
        {
            for(int j=i;j<total_books-1;j++)
            {
                struct book b;
                b=*(*(library+j));
                *(*(library+j))=*(*(library+j+1));
                *(*(library+j+1))=b;
            }
            return;
        }
    }
}
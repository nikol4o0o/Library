#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include "User.h"
#include "Book.h"
#include "Usermass.h"
#include "Bookmass.h"

using namespace std;

int main()
{
    char username[256];
    char password[256];
    char command[32];
    char author[256];
    char header[256];
    char ganre[64];
    char resume[1024];
    size_t year;
    char keywords[128];
    double rating;
    size_t ID;
    char option[16];
    bool isUser = false;
    bool isAdmin = false;
    bool isOpen = false;
    Usermass users;
    Usermass defaults;
    Bookmass books;
    Bookmass initialbooks;
    User nikola("nikola", "nikola123");
    Book first("Leo Tolstoy", "Anna Karenina", "roman", "Anna Karenina tells of the doomed love affair between the sensuous and rebellious Anna and the dashing officer, Count Vronsky.", 1877, "affair", 9.8, 1210);
    Book second("Leo Tolstoy", "War and Piece", "roman", "A roman that reveals the strong and passionate love, even during the war", 1865, "love", 9.1, 1230);
    Book third("Francis Fitzgerald", "The great Gitsby", "tragedy", "The novel chronicles an era that Fitzgerald himself dubbed the Jazz Age.", 1925, "crime, millionaires", 9.2, 1212);
    Book fourth("William Shakespeare", "Hamlet", "tragedy", "Prince Hamlet exacts revenge on his uncle Claudius, who has murdered Hamlet's father, the King, and then taken the throne and married Gertrude, Hamlet's mother.", 1609, "drama", 8.7, 1242);
    Book fifth("Nikola Vaptsarov", "Proshtalno", "poetry", "It is autobiographis poetry that shows the love of the poet in the moment of his death! ", 1942, "love", 9.2, 1243);
    
   
    //Default testing...
    //users.AddUser(nikola);
   /* books.AddBook(first);
    books.AddBook(second);
    books.AddBook(third);
    books.AddBook(fourth);
    books.AddBook(fifth);*/
    ifstream Usersinput("Users.txt");
    users.readUsers(Usersinput);
    
    
    char filename[256];
    bool flagger = true;
    cout << "Welcome to library! To start it you need to open a file!" << endl;
    cout << "Type 'open'  " << endl;
    cin.getline(command, 32);
    
 
    while (strcmp(command, "open"))
    {
        cout << "You need to open file" << endl;
        cout << "Type 'open'  " << endl;
        cin.getline(command, 31);
    }
    if (strcmp(command, "open") == 0)
    {
        cout << "now the name of the file ____.txt" << endl;
        cin.getline(filename, 255);
        ifstream Booksinputinitial(filename);

        if (Booksinputinitial.is_open())
        {
            cout << filename << " is opened successfully" << endl;
            books.readBooks(Booksinputinitial);
            initialbooks = books;
            cout << books.getSize();
        }
        else
        {
            cout << filename << " is created succesfully" << endl;
            ofstream Booksoutputinitial(filename);
            Booksoutputinitial.close();
        }
        Booksinputinitial.close();
       
        isOpen = true;
    }
    ifstream Booksinput(filename);
    ofstream Booksoutput(filename);
    cout << "If you are new, just write 'help' on the console " << endl;
   
    while (strcmp(command, "exit") != 0)
    {
      
        if ((strcmp(command, "close") == 0)&& isOpen)
        {
            char filename2[256];
            flagger = true;
            initialbooks.saveBooks(Booksoutput);
            Booksoutput.close();
            //books.clear();
            Booksinput.close();
            cout << "The file is closed" << endl;
            cout << "Enter new file to continue" << endl;
            cin.getline(filename2, 255);
            ifstream Booksinput(filename2);
            if (Booksinput.is_open())
            {
                cout << filename2 << " successfully opened" << endl;
                if (strcmp(filename, filename2) != 0)
                {
                    books.readBooks(Booksinput);
                }
            }
            else
            {
                ofstream Booksoutput(filename2);
                cout << filename2 << " succesfully created!" << endl;
            }
            
        }

        if((strcmp(command, "save") == 0)&& isOpen)
        {
            flagger = false;
            books.saveBooks(Booksoutput);
        }

        if (strcmp(command, "save as") == 0 && isOpen) 
        {
            flagger = false;
            char nameit[256];
            cin.getline(nameit, 255);
            ofstream Booksfinal(nameit);
            books.saveBooks(Booksfinal);
            Booksfinal.close();
            books.saveBooks(Booksoutput);
            
        }

        if (strcmp(command, "help") == 0)
        {
            cout << "The following commands are supported:" << endl;
            cout << "open <file>	opens <file>"<<endl;
            cout << "close			closes currently opened file" << endl;
            cout << "save			saves the currently open file" << endl;
            cout << "saveas <file>	saves the currently open file in <file>" << endl;
            cout << "help			prints this information" << endl;
            cout << "exit			exists the program" << endl;
            cout << "login" << endl;
            cout << "logout" << endl;
            cout << "When you login you are able to do:" << endl;
            cout << "books all - shows you all available books in the library" << endl;
            cout << "books info - shows book info" << endl;
            cout << "books sort - sorts the book" << endl;
            cout << "If you are an admin, you can do:" << endl;
            cout << "users add - adds user" << endl;
            cout << "users remove - removes user" << endl;
            cout << "books add - adds book" << endl;
            cout << "books remove - removes book" << endl;
        }



        if ((strcmp(command, "login") == 0) && isOpen)
        {
            cout << "Enter username: " << endl;
            cin >> username;
            cout << "Enter password" << endl;
            int g = 0;
            char c = ' ';
            while (g <= 255)
            {
                password[g] = _getch();
                c = password[g];
                if (c == 13)
                {
                    break;
                }
                if (c == 32 || c == 27)
                {
                    continue;
                }
                if (c != 8)
                {
                    password[g] = c;
                    printf("*");
                    g++;
                }
                else
                {
                    g--;
                    if (g < 0)
                        g++;
                    else
                        printf("\b \b");
                }

            }
            printf("\b \b");
            password[g] = '\0';
            g = 0;
            cout << endl;
        
            if (((strcmp(username, "admin") == 0) && ((strcmp(password, "i<3c++") == 0))))
            {
                isUser = true;
                isAdmin = true;
                cout << "Welcome, Admin!" << endl;
                
            }

            else
            {
                bool flag1 = false;
                for (int i = 0; i < users.getSize(); i++)
                {
                    if (((strcmp(username, users[i].getUsername()) == 0) && ((strcmp(password, users[i].getPassword()) == 0))))
                    {
                        isUser = true;
                        cout << "Welcome" << ", " << username << endl;
                        flag1 = true;
                    }
                }
                if (flag1 == false)
                {
                    cout << "No such user, contact admin! " << endl;
                }
            }

            
        }

        if((strcmp(command, "logout") == 0 && isUser) && isOpen)
        {
            isUser = false;
            isAdmin = false;
            cout << "Logout successfull! See ya'! " << endl;
        }
        if ((strcmp(command, "logout") == 0 && (!isUser)))
        {
            cout << "You need to login first!" << endl;
        }


        if (((strcmp(command, "books all") == 0) && isUser) && isOpen)
        {
            cout << "Here is the full list of books in our library: " << endl;
            for (int i = 0; i < books.getSize(); i++)
            {
                cout << books[i].getHeader() << " " << books[i].getAuthor() << " " << books[i].getGanre() << " " << books[i].getID() << endl;
            }
        }
        if ((strcmp(command, "books all") == 0 && (isUser == false)))
        {
            cout << "You need to login first! " << endl;
        }


        if (((strcmp(command, "books info") == 0) && isUser) && isOpen)
        {
            cout << "Enter the ID: " << endl;
            cin >> ID;
            books.BookPrintByID(ID);
        }
        if ((strcmp(command, "books info") == 0 && (isUser == false)))
        {
            cout << "You need to login first! " << endl;
        }

        if (((strcmp(command, "books find") == 0) && isUser) && isOpen)
        {
            cout << "Choose your option: author/ title/ tag " << endl;
            cin.getline(option, 15);
            if (strcmp(option, "title") == 0)
            {
                cout << "Enter the title searched: " << endl;
                cin.getline(header, 255);
                for (int i = 0; i < books.getSize(); i++)
                {
                    if (strcmp(books[i].getHeader(), header) == 0)
                    {
                        books[i].printBook();
                    }
                }
            }

            else if (strcmp(option, "author") == 0)
            {
                cout << "Enter the author searched: " << endl;
                cin.getline(author, 255);
                for (int i = 0; i < books.getSize(); i++)
                {
                    if (strcmp(books[i].getAuthor(), author) == 0)
                    {
                        books[i].printBook();
                    }
                }
            }

            else if (strcmp(option, "tag") == 0)
            {
                cout << "Enter the tag searched: " << endl;
                cin.getline(keywords, 128);
                for (int i = 0; i < books.getSize(); i++)
                {
                    if (strcmp(books[i].getKeywords(), keywords) == 0)
                    {
                        books[i].printBook();
                    }
                }
            }
        }

        if ((strcmp(command, "books sort") == 0 && (isUser==true)) && isOpen)
        {
            char choices[16];
            char order[16];
            cout << "Choose to sort by author/header/year/rating: " << endl;
            cin.getline(choices, 15);
            cout << "Enter the order: (ascending/descending) " << endl;
            cin >> order;;

            if (strcmp(choices, "author") == 0)
            {
                books.SortBooksbyAuthor();
                books.printByOrder(order);
            }

            if (strcmp(choices, "header") == 0)
            {
                books.SortBooksbyHeader();
                books.printByOrder(order);
            }

            if (strcmp(choices, "year") == 0)
            {
                books.SortBooksbyYear();
                books.printByOrder(order);
            }


            if (strcmp(choices, "rating") == 0)
            {
                books.SortBooksbyRating();
                books.printByOrder(order);
            }
        }
        if (strcmp(command, "books sort") == 0 && (isUser == false))
        {
            cout << "You need to login first! " << endl;
        }




        if ((strcmp(command, "users add") == 0) && isAdmin)
        {
            cout << "Enter the username: " << endl;
            cin >> username;
            cout << "Enter the password: " << endl;
            cin >> password;
            if (users.checkforUser(username, password) == false)
            {
                User user1(username, password);
                users.AddUser(user1);
                cout << "Successfull!" << endl;
            }
            else
            {
                cout << "The user already exists" << endl;
            }
            
                        
        }
        if ((strcmp(command, "users add") == 0) && (isAdmin == false))
        {
            cout << "No such permissions, you are not admin!" << endl;
        }


        if ((strcmp(command, "users remove") == 0) && isAdmin)
        {
            cout << "Enter the username to be deleted: " << endl;
            cin >> username;
            users.RemoveUser(username);
            
        }
        if ((strcmp(command, "users remove") == 0) && (isAdmin == false))
        {
            cout << "No such permissions, you are not admin!" << endl;
        }

        if ((strcmp(command, "books add") == 0) && isAdmin)
        {
            cout << "Enter the author" << endl;
            cin.getline(author, 255);
            cout << "Enter the header" << endl;
            cin.getline(header, 255);
            
            cout << "Enter the ganre" << endl;
            cin.getline(ganre, 63);
          
            cout << "Enter the resume: " << endl;
            cin.getline(resume, 1023);
            cout << "Enter the keywords: " << endl;
            cin.getline(keywords, 127);
            cout << "Enter the year: " << endl;
            cin >> year;
            cout << "Enter the rating 0 to 10: " << endl;
            cin >> rating;
            cout << "Enter the ID: " << endl;
            cin >> ID;

            bool flag = true;
            for (int i = 0; i < books.getSize(); i++)
            {
                if (ID == books[i].getID())
                {
                    flag = false;
                }
            }
            if (flag)
            {
                Book newBook(author, header, ganre, resume, year, keywords, rating, ID);
                books.AddBook(newBook);
                
            }
            else
            {

                cout << "You should change the ID!" << endl;
            }
        }
        if ((strcmp(command, "books add") == 0) && (isAdmin == false))
        {
            cout << "No such permissions, you are not admin!" << endl;
        }

        if ((strcmp(command, "books remove") == 0) && isAdmin)
        {
            cout << "Enter the header of the book you would like to remove: " << endl;
            cin.getline(header, 255);
            books.RemoveBook(header);

            
            cout << header << ", successfully removed!" << endl;
        }
        if ((strcmp(command, "books remove") == 0) && (isAdmin == false))
        {
            cout << "No such permissions, you are not admin!" << endl;
        }

        cin.getline(command, 31);
    }
    cout << "Exiting the program..." << endl;
    
    ofstream Usersoutput("Users.txt");
    users.saveUsers(Usersoutput);

    Usersoutput.close();
    Usersinput.close();
    Booksinput.close();
    
    if (flagger)
    {
        initialbooks.saveBooks(Booksoutput);
    }
   
    
}


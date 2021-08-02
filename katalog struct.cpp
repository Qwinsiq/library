// katalog struct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Book
{
    char* name;
    char* autor;
    char* genre;
};

Book* initBooks(int &n);
void searchAutor(char* tempStr, Book* &library, int& n);
void searchName(char* tempStr, Book* &library, int& n);
void searchGenre(char* tempStr, Book* &library, int& n);
Book* addBook(Book* addBook, int& n);
void createBook(Book* createBook, int n);
void printBook(Book* printBook);
void editBook(Book* editBook, int n, int y);
Book* deleteBook(Book* deleteBook, int& n, int x);
void writeLibrary(Book* library, int n);
int main()
{
    int n = 0;
    Book* library = nullptr;
    library = initBooks(n);
    int x = 1;
    char* tempStr = new char[50];
    while(x!=0)
        {
        cout << " Search\n  1.By autor\n  2 By name\n  3 By genre\n   4. Add book\n 0. Exit\n";
        cin >> x;
        
    cin.ignore(1, '\n');
    if (x == 1)
    {
        cout << "Enter autor \n";
        cin.getline(tempStr, 50);
        searchAutor(tempStr, library, n);
    }
    if (x == 2)
    {
        cout << "Enter name \n";
        cin.getline(tempStr, 50);
        searchName(tempStr, library, n);
    }
    if (x == 3)
    {
        cout << "Enter genre \n";
        cin.getline(tempStr, 50);
        searchGenre(tempStr, library, n);
    }
    if (x == 4)
        library = addBook(library, n);
}
    int z = 0;
    cout << " Do you want to write catalog in the file?\n 1-yes\n 2-no\n";
    cin >> z;
    if (z == 1)
    {
        writeLibrary(library, n);
    }
    return 0;
}

Book* initBooks(int &n)
{
    /*n = 3;   
    Book* books = new Book[n];

    books[0].name = new char[strlen("Kolobok") + 1];
    strcpy_s(books[0].name, strlen("Kolobok") + 1, "Kolobok");
    books[0].autor = new char[strlen("folk tales") + 1];
    strcpy_s(books[0].autor, strlen("folk tales") + 1, "folk tales");
    books[0].genre = new char[strlen("Story") + 1];
    strcpy_s(books[0].genre, strlen("Story") + 1, "Story");

    books[1].name = new char[strlen("Idiot") + 1];
    strcpy_s(books[1].name, strlen("Idiot") + 1, "Idiot");
    books[1].autor = new char[strlen("Dostoevskiy F.M.") + 1];
    strcpy_s(books[1].autor, strlen("Dostoevskiy F.M.") + 1, "Dostoevskiy F.M.");
    books[1].genre = new char[strlen("novel") + 1];
    strcpy_s(books[1].genre, strlen("novel") + 1, "novel");

    
    books[2].name = new char[strlen(" Harry Potter") + 1];
    strcpy_s(books[2].name, strlen("Harry Potter") + 1, "Harry Potter");
    books[2].autor = new char[strlen("Rowling J.K.") + 1];
    strcpy_s(books[2].autor, strlen("Rowling J.K.") + 1, "Rowling J.K.");
    books[2].genre = new char[strlen("fantasy") + 1];
    strcpy_s(books[2].genre, strlen("fantasy") + 1, "fantasy");*/
 FILE* pf;
    fopen_s(&pf, "data.dat", "rb");
    if (!pf)
    {
        cout << "Error opening file\n";
        return 0;
    }
    int num=0;
    fread(&num, sizeof(int),1,pf);
    n=num;
    Book* books= new Book[n];
    short size=0;
    for(int i=0; i<num;i++)
    {
    fread(&size, sizeof(short), 1, pf);
    books[i].name= new char[size];
    fread(books[i].name, sizeof(char),size,pf);
    size=0;
    fread(&size, sizeof(short), 1, pf);
    books[i].autor= new char[size];
    fread(books[i].autor, sizeof(char), size,pf);
    size=0;
    fread(&size, sizeof(short), 1, pf);
    books[i].genre= new char[size];
    fread(books[i].genre, sizeof(char), size, pf);  
    }
    fclose(pf);
    return books;
}
void searchAutor(char* tempStr, Book* &library, int& n)
{
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(library[i].autor, tempStr) == 0)
        {
            cout << i << "book " << endl;
            printBook(&library[i]);
            z++;
            int x = 1, y = 0;
            cout << "Select book by index \n";
            cin >> y;
            cin.ignore(1, '\n');
            cout << " Select an action \n 1. Edit book \n 2. Delete book"<<endl;
            cin >> x;
            cin.ignore(1, '\n');
            if (x == 1)
                editBook(library, y,n);
            if (x == 2)
                library = deleteBook(library, n, y);
        }
    }
    if (z == 0) cout << " Not find";
}
void searchName(char* tempStr, Book* &library, int& n)
{
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(library[i].name, tempStr) == 0)
        {
            cout << "Index of Book " << i<< endl;
            printBook(&library[i]);
            z++;

            int x = 1, y = 0;
            cout << "Select book by index \n";
            cin >> y;
            cin.ignore(1, '\n');
            cout << " Select an action \n 1. Edit book \n 2. Delete book \n";
            cin >> x;
            cin.ignore(1, '\n');
            if (x == 1)
                editBook(library, y, n);
            if (x == 2)
                library = deleteBook(library, n, y);
        }
    }
    if (z == 0) cout << " Not find";

}
void searchGenre(char* tempStr, Book* &library, int& n)
{
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(library[i].genre, tempStr) == 0)
        {
            cout <<"Index of book "<< i << endl;
            printBook(&library[i]);
            z++;
            int x = 1, y = 0;
            cout << "Select book by index \n";
            cin >> y;
            cin.ignore(1, '\n');
            cout << " Select an action \n 1. Edit book \n 2. Delete book\n";
            cin >> x;
            cin.ignore(1, '\n');
            if (x == 1)
                editBook(library, y,n);
            if (x == 2)
                library = deleteBook(library, n, y);
        }
    }
    if (z == 0) cout << " Not find";
}
Book* addBook(Book* addBook, int& n)
{
    Book* newBook = new Book [n + 1];
    for (int i = 0; i < n; i++)
    {
        newBook[i] = addBook[i];
    }
    createBook(newBook, n);
       n++;
    delete[] addBook;
    return newBook;
}
void createBook(Book* createBook, int n)
{
    char* tempStr = new char[50];

    cout << " Enter Name \n";
    cin.getline(tempStr, 49);
    createBook[n].name = new char[strlen(tempStr) + 1];
    strcpy_s(createBook[n].name, strlen(tempStr)+1, tempStr);

    cout << " Enter Autor \n";
    cin.getline(tempStr, 49);
    createBook[n].autor = new char[strlen(tempStr) + 1];
    strcpy_s(createBook[n].autor, strlen(tempStr) + 1, tempStr);

    cout << " Enter Genre \n";
    cin.getline(tempStr, 49);
    createBook[n].genre = new char[strlen(tempStr) + 1];
    strcpy_s(createBook[n].genre, strlen(tempStr) + 1, tempStr);
}
void editBook(Book* editBook, int n, int y)
{
    char* tempStr = new char[50];
    cout << " Enter Name \n";
    cin.getline(tempStr, 49);
    strcpy_s(editBook[n].name, 50, tempStr);

    cout << " Enter Autor \n";
    cin.getline(tempStr, 49);
    strcpy_s(editBook[n].autor, 30, tempStr);

    cout << " Enter Genre \n";
    cin.getline(tempStr, 49);
    strcpy_s(editBook[n].genre, 20, tempStr);
    printBook(&editBook[n]);
    int x = 0;
    cout << " Do you want to write catalog in the file?\n 1-yes\n 2-no\n";
    cin >> x;
    if (x == 1)
    {
        writeLibrary(editBook, n);
    }
}
Book* deleteBook(Book* deleteBook, int& n, int x)
{
    Book* newBooks = new Book [n - 1];
    for (int i = 0; i < x; i++)
    {
        newBooks[i] = deleteBook[i];
    }
    for (int i = x + 1; i < n; i++)
    {
        newBooks[i - 1] = deleteBook[i];
    }
    n--;
    cout << " Book is deleted \n";
    int z = 0;
    cout << " Do you want to write catalog in the file?\n 1-yes\n 2-no\n";
    cin >> z;
    if (z == 1)
    {
        writeLibrary(newBooks, n);
    }
        return newBooks;
}
void printBook(Book* printBook)
{
    cout << "Name  : " << printBook->name << endl;
    cout << "Author: " << printBook->autor << endl;
    cout << "Genre : " << printBook->genre<< endl;
    cout << "****************************\n";
}
void writeLibrary(Book* library, int n)
{
    FILE* pf;
    fopen_s(&pf, "data.dat", "wb");
    if (!pf)
    {
        cout << "Error opening file\n";
    }

    fwrite(&n, sizeof(int), 1, pf);
    short size = 0;
    for (int i = 0; i < n; i++)
    {
        size = strlen(library[i].name) + 1;
        fwrite(&size, sizeof(short), 1, pf);
        fwrite(library[i].name, sizeof(char), size, pf);

        size = strlen(library[i].autor) + 1;
        fwrite(&size, sizeof(short), 1, pf);
        fwrite(library[i].autor, sizeof(char), size, pf);

        size = strlen(library[i].genre) + 1;
        fwrite(&size, sizeof(short), 1, pf);
        fwrite(library[i].genre, sizeof(char), size, pf);
    }
    fclose(pf);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>


using namespace std;

class Book
{
private:

	string name;
	string author;
	string genre;
	float rating;
	bool onRead;

public:
	void createBook( string na, string au, string ge, float ra, bool re);
	void showBook();
	void getBooks();
	bool getRead()
	{
		return onRead;
	}
	void report(){
		cout<<name<<"\t"<<author<<endl;
	}

}B;

void Book::createBook(string na, string au, string ge, float ra, bool re)
{


	B.name = na;
	B.author = au;
	B.genre = ge;
	B.rating = ra;
	B.onRead = re;

	ofstream fout;

	char ch;
    fout.open("bookDatabase.dat",ios::out|ios::app);
	if (!fout.is_open())
	{
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
    fout.write((char *)&B, sizeof(B));

	cout << "\n";
	cout << "\nThe Book with above attributes is Saved!\n";

	fout.close();
}

void Book::showBook()
{
	cout<<"\nBOOK DETAILS\n";
    int flag=0;
	ifstream fin;
    fin.open("bookDatabase.dat",ios::in);
    while(fin.read((char*)&B,sizeof(Book)))
    {
        if(!fin.eof())
        {
            cout << "\nName of the Book: " << B.name;
            cout << "\nAuthor: " << B.author;
            cout << "\nGenre: " << B.genre;
            cout << "\nRating: " << B.rating;;
            flag=1;
        }
    }

    fin.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

int getBooks()
{
	Book B;
	ifstream fin;
	fin.open("bookDatabase.dat", ios::binary| ios::in);
	if (!fin.is_open())
	{
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	int Bcount = 0;
	fin.seekg(0);

	while (fin.read((char *)&B, sizeof(Book)))
	{
		Bcount++;
		B.showBook();
	}
	fin.close();
	return Bcount;
}
/*
void display_allb()
{

	fstream fout;
    fout.open("book.dat",ios::in);
    if(!fout)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\nBook LIST\n\n";

    cout<<"Book Number      "<<"Book Name	"<<"Author		\n";

    while(fout.read((char*)&B,sizeof(Book)))
    {
        B.report();
    }
         fout.close();
         getch();
}
*/
int main()
{

	Book B;
	int choice, noB;
	string name, author, genre;
	float rating;
	char wish = 'y', re;

	while (wish == 'y' || wish == 'Y')
	{
		cout << "\n -: Menu :-\n";
		cout << "\n 1. Create Book\n 2. Display Books on read\n 3. More functions soon\n 4. Exit\n";
		cout << "\nEnter corresponding serial number: ";
		cin >> choice;
		getchar();

		switch (choice)
		{
		case 1:

			cout << "\nEnter name of the book: ";
			getline(cin, name);
			cout << "Enter name of the author: ";
			getline(cin, author);
			cout << "Enter genre: ";
			getline(cin, genre);
			cout << "Rate the book: ";
			cin >> rating;
		readChoice:
			cout << "Add book on read (y/n): ";
			cin >> re;
			if (re == 'y' || re == 'Y')
				B.createBook(name, author, genre, rating, true);
			else if (re == 'n' || re == 'N')
				B.createBook(name, author, genre, rating, false);
			else
			{
				cout << "Wrong choice! Enter again...\n";
				goto readChoice;
			}
			break;
		case 2:
			noB = getBooks();
			if (!noB)
				cout << "No books are on read.\n";
			break;
		case 3:
			cout << "Stay tuned !!\n";
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Wrong Choice.\n";
			break;
		}
		cout << "\nWant to enter more? (y/n): ";
		cin >> wish;
	}
	return 0;
}

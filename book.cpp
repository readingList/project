#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>


using namespace std;

class Book
{
private:
	char bookName[50];
	char authorName[20];
	float rating;
	bool onRead;

public:
	void create_book()
		{
			cout<<"\n...Add New Book...\n";
			cout<<"\nEnter name of the Book: ";
			gets(bookName);
			cout<<"\nEnter Author's name: ";
			gets(authorName);
			cout<<"\nEnter Book's rating: ";
			cin>>rating;
			cout<<"\nAdd book on read (y/n): ";
			cin>>onRead;
			while(onRead != 'y' || onRead != 'Y' || onRead != 'n' || onRead != 'N')
				{
					cout<<"\nWrong choice! Enter again...\n";
					cout<<"\nAdd book on read (y/n): ";
					cin>>onRead;
				}
			cout<<"\n\nBook Created !";
		}

	void show_book()
		{
			cout<<"\nBook Name: ";
			puts(bookName);
			cout<<"\nAuthor Name: ";
			puts(authorName);
			cout<<"\nRating: "<<rating;
		}

	void modify_book()
		{
			cout<<"\nModify Book Name: ";
			gets(bookName);
			cout<<"\nModify Author's Name: ";
			gets(authorName);
			cout<<"\nModify Book's rating: ";
			cin>>rating;
		}

	bool get_read()
		{
			return onRead;
		}

};

fstream fp,fp1;
Book bk;

void write_book()
	{
		char ch;
		fp.open("book.dat",ios::out|ios::app);
		do
			{
				bk.create_book();
				fp.write((char*)&bk,sizeof(Book));
				cout<<"\n\nDo you want to add more record..(y/n?)";
				cin>>ch;
			}while(ch=='y' || ch=='Y');
		fp.close();
	}

void display_book()
	{
		cout<<"\nBook Details\n";
		int flag=0;
		fp1.open("book.dat",ios::in);
		while(fp1.read((char*)&bk,sizeof(Book)))
			{
				if(bk.get_read())
					{
						bk.show_book();
						flag=1;
					}
			}
		fp1.close();
		if(flag==0)
			cout<<"\n\nBook does not exist";
	}

void all_books()
	{
		fp1.open("book.dat",ios::in);
		if(!fp1)
			{
				cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
					return;
			}

		cout<<"\nAll Books\n\n";
		while(fp1.read((char*)&bk,sizeof(Book)))
			{
				bk.show_book();
			}
		fp1.close();
	}


int main()
{

	int choice, noB;
	char wish = 'y';

	while(wish == 'y' || wish == 'Y')
		{
			cout << "\n -: Menu :-\n";
			cout << "\n 1. Create Book\n 2. Display Books on read\n 3. Display All Books\n 4. Exit\n";
			cout << "\nEnter corresponding serial number: ";
			cin >> choice;

			switch (choice)
				{
				case 1:
					write_book();
					break;
				case 2:
					display_book();
					break;
				case 3:
					all_books();
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

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>


using namespace std;

class Book
{
private:
	char bookNum[6];
	char bookName[50];
	char authorName[20];
	float rating;
    char onRead;

public:
	void create_book()
	{
        cout<<"\nCREATE NEW BOOK\n";
        cout<<"\nEnter The book number: ";
        cin>>bookNum;
        cout<<"\nEnter Book's name: ";
        gets(bookName);
        cout<<"\nEnter Author's name: ";
        gets(authorName);
        cout<<"\nEnter Ratting of book: ";
        cin>>rating;
        cout<<"\nWant to add book to read? (y/n): ";
        cin>>onRead;
        while(onRead != 'y' || onRead != 'Y' || onRead != 'n' || onRead != 'N');
        {
            cout<<"\n\nWrong Choice !!";
            cout<<"\nWant to add book to read? (y/n): ";
            cin>>onRead;
        }
        cout<<"\n\nBook Created..";
    }

	void show_book()
		{
			cout<<"\nBook Number: "<<bookNum;
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
			cout<<"\nWant to add book to read? (y/n): ";
			cin>>onRead;
			while(onRead != 'y' || onRead != 'Y' || onRead != 'n' || onRead != 'N');
			{
				cout<<"\n\nWrong Choice !!";
				cout<<"\nWant to add book to read? (y/n): ";
				cin>>onRead;
			}
		}

	bool get_read()
		{
			return onRead;
		}
	
    void report()
    {cout<<bookNum<<setw(30)<<bookName<<setw(30)<<authorName<<endl;}

};

fstream fp,fp1;
Book bk;

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        clrscr();
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
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

void modify_book()
	{
		char n[6];
		int found=0;
		clrscr();
		cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
		cout<<"\n\n\tEnter The book no. of The book";
		cin>>n;
		fp.open("book.dat",ios::in|ios::out);
		while(fp.read((char*)&bk,sizeof(book)) && found==0)
		{
			if(strcmpi(bk.getBookNum(),n)==0)
			{
				bk.show_book();
				cout<<"\nEnter The New Details of book"<<endl;
				bk.modify_book();
				int pos=-1*sizeof(bk);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&bk,sizeof(book));
					cout<<"\n\n\t Record Updated";
					found=1;
			}
		}

			fp.close();
			if(found==0)
				cout<<"\n\n Record Not Found ";
			getch();
	}


int main()
{

	int choice, noB;
	char wish = 'y';

	while(wish == 'y' || wish == 'Y')
		{
			cout << "\n -: Menu :-\n";
			cout << "\n 1. Create Book\n 2. Display Books on read\n 3. Display All Books\n4. Modify Book\n5. Delete Book\n 6. Exit\n";
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
					modify_book();
					break;
				case 5:
					//delete book func
					break;
				case 6:
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

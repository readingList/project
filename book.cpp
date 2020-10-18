#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;

class Book{
	private:
        string name;
        string author;
        string genre;
        float rating;
        bool onRead;
		
    public:
        void createBook(string na, string au, string ge, int ra, bool re);
        void showBook();
		void getBooks();
        bool getRead(){
        	return onRead;
		}
}B;

void Book::createBook(string na, string au, string ge, int ra, bool re){
    
	B.name = na;
    B.author = au;
    B.genre = ge;
    B.rating = ra;
    B.onRead = re;

	ofstream fout;
	fout.open("bookDatabase.txt", ios::out | ios::app);
	if( !fout.is_open() ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
	}
	
	fout.write((char*)&B, sizeof(B));
	
	cout<<"\nThe Book with above attributes is Saved!\n";
	
	fout.close();
}
void Book::showBook(){
	
	cout<<"\nName of the Book: "<<B.name;
    cout<<"\nAuthor: "<<B.author;
    cout<<"\nGenre: "<<B.genre;
    cout<<"\nRating: "<<B.rating;
}

int getBooks(){
	
	ifstream fin;
	fin.open("bookDatabase.txt", ios::in);
	
	int Bcount = 0;
	
	fin.seekg(0);
	
	while(!fin.eof()){
		if (B.getRead()){
			fin.read((char*)&B, sizeof(B));
			cout<<"Book"<<++Bcount;
			B.showBook();
			cout<<"\n";
		}
		fin.read((char*)&B, sizeof(B));
	}
	
	fin.close();
	
	return Bcount;
}

int main(){

    
    int choice, noB;
    string name, author, genre;
	float rating;
    char wish = 'y', re;
    
    while(wish=='y' || wish=='Y'){
    	cout<<"\n -: Menu :-\n";
    	cout<<"\n1. Create Book \n2. Display Books on read \n3. More functions soon \n4. Exit\n";
		cout<<"\nEnter corresponding serial number: ";
    	cin>>choice;
		getchar();
    
		switch(choice){
			case 1: cout<<"\nEnter name of the book: ";
					getline(cin, name);
					cout<<"Enter name of the author: ";
					getline(cin, author);
					cout<<"Enter genre: ";
					getline(cin, genre);
					cout<<"Rate the book: ";
					cin>>rating;
					readChoice:
						cout<<"Add book on read (y/n): ";
						cin>>re;
						if(re=='y' || re=='Y')
							B.createBook(name, author, genre, rating, true);
						else if(re=='n' || re=='N')
							B.createBook(name, author, genre, rating, false);
						else{
							cout<<"Wrong choice! Enter again...\n";
							goto readChoice;
						}
					break;
			case 2: noB = getBooks();
					if(!noB) cout<<"No books are on read.\n";
					break;
			case 3: cout<<"Stay tuned !!\n";
					break;
			case 4: exit(0);
					break;
			default: cout<<"Wrong Choice.\n";
					 break;
		}
		cout<<"\nWant to enter more? (y/n): ";
		cin>>wish;
	}
    return 0;
}

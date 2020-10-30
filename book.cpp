#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

class Book{
	private:
        string name;
        string author;
        string genre;
        float rating;
        bool onRead;
    public:
        void createBook(string na, string au, string ge, float  ra, bool re);
        void showBook();
		void getBooks();
        bool getRead(){
        	return onRead;
		}
};

void Book::createBook(string na, string au, string ge, float ra, bool re){

    Book B;
	B.name = na;
    B.author = au;
    B.genre = ge;
    B.rating = ra;
    B.onRead = re;

    /*
	ofstream fout;
	fout.open("bookDatabase.txt", ios::binary | ios::app);
	if(!fout.is_open()){
      cerr << "Error: file could not be opened" << endl;
      exit(1);
	}
	fout.write((char*)&B, sizeof(B));

	*/

	string Stringified = "*" + na + "*" + au + "*" + ge + "*" + to_string(ra) + "*" + to_string(re);
	cout<<"->"<<Stringified<<"\n";

	ofstream fout;
	fout.open("bookDatabase.txt", ios::app);
	fout<<Stringified;
	fout<<"\n";
	cout<<"\nThe Book with above attributes is Saved!\n";
	fout.close();

}
void Book::showBook(){
	cout<<"\nName of the Book: "<<name;
    cout<<"\nAuthor: "<<author;
    cout<<"\nGenre: "<<genre;
    cout<<"\nRating: "<<rating;
}

int getBooks(){
    /*
    Book B;
	ifstream fin;
	fin.open("bookDatabase.txt");
    if(!fin.is_open()){
      cerr << "Error: file could not be opened" << endl;
      exit(1);
	}
	int Bcount = 0;
	//fin.seekg(0);

	fin>>
	fin.close();
	return Bcount;
	*/
	return 0;
}

int main(){

    Book B;
    int choice, noB;
    string name, author, genre;
	float rating;
    char wish = 'y', re;

    while(wish=='y' || wish=='Y'){
    	cout<<"\n -: Menu :-\n";
    	cout<<"\n 1. Create Book\n 2. Display Books on read\n 3. More functions soon\n 4. Exit\n";
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

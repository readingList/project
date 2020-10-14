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
        void createBook(string na, string au, string ge, int ra, bool re){
            name = na;
            author = au;
            genre = ge;
            rating = ra;
            onRead = re;
        }
        void showBook(){
            cout<<"\nName of the Book: "<<name;
            cout<<"\nAuthor: "<<author;
            cout<<"\nGenre: "<<genre;
            cout<<"\nRating: "<<rating;
        }
        bool getRead(){
        	return onRead;
		}
};

void saveFile(Book myBook){
	ofstream fout("bookDatabase.dat",ios::app|ios::binary);
	fout.write((char*)&myBook,sizeof(Book));
	fout.close();
	cout<<"\nThe Book is Saved!\n";
}
/*
int getBook(){
	Book readB;
	int flag = 0;
	ifstream fin("bookDatabase.dat",ios::binary);
	while(fin.read((char*)&readB,sizeof(Book))){
		if(readB.getRead()){
			flag += 1;
			cout<<"Book "<<flag<<": ";
			readB.showBook();
			cout<<"\n";
		}
	}
	return flag;
}
*/
int main(){

    Book B;
    int choice;
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
					saveFile(B);
					break;
			case 2: //if(!getBook())
						cout<<"Book on read will be displayed here...\n";
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

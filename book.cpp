#include <iostream>
#include <cstring>

using namespace std;

class Book{
    private:
        string name;
        string author;
        string genre;
        float rating;
        int pages;
        bool onRead;
    public:
        void createBook(string na, string au, string ge, int ra, int pa, bool re){
            name = na;
            author = au;
            genre = ge;
            rating = ra;
            pages = pa;
            onRead = re;
        }
        void showBook(){
            cout<<"\nName of the Book: "<<name;
            cout<<"\nAuthor: "<<author;
            cout<<"\nGenre: "<<genre;
            cout<<"\nRating: "<<rating;
            cout<<"\nNo. of Pages: "<<pages;
        }
};

int main(){

    Book B1;
    int choice;
    string na, au, ge;
	int ra, pa;
	bool re;
	char c;
    
    cout<<"Menu: (Enter corresponding serial number)";
    cout<<"\n1. Create Book \n2. Display Book \n3. Modify \n";
    cin>>choice;
    
    switch(choice)
	{
		case 1: {
				cout<<"\nEnter name of the book: ";
				cin>>c;
				getline(cin, na);
				cout<<"\nEnter name of the author: \n";
				getline(cin, au);
				cout<<"\nEnter genre: \n";
				getline(cin, ge);
				cout<<"\nRate the book: \n";
				cin>>ra;
				cout<<"\nEnter number of pages read: \n";
				cin>>pa;
				B1.createBook(na, au, ge, ra, pa, true);
   			    break;
   			}
   		case 2: {
			    B1.showBook();
   			    break;
   			}
	}

    cout<<"\nThe end is near...\n";
    return 0;
    
}

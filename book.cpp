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
    B1.createBook("A Brief History of Time",
                  "Stephen Hawking",
                  "Popular Science",
                  4.8,
                  256,
                  true
    );

    B1.showBook();

    cout<<"\nThe end is near...\n";
    return 0;
    
}
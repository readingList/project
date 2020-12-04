#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>


class book{
	char bookNum[6];
	char bookName[50];
	char authorName[20];
	char genre[20];
    char onRead;
public:
	void create_book(){
        cout<<"\nCREATE NEW BOOK...\n";
        cout<<"\nEnter The book no.: ";
        cin>>bookNum;
        cout<<"\nEnter The Name of The Book: ";
        gets(bookName);
        cout<<"\nEnter The Author's Name: ";
        gets(authorName);
        cout<<"\nEnter Genre of book: ";
        gets(genre);
        cout<<"\nWant to add book to read? (y/n): ";
        cin>>onRead;
        cout<<"\n\n\nBook Created..";
    }
    void show_book(){
        cout<<"\nBook no.: "<<bookNum;
        cout<<"\nBook Name: ";
        puts(bookName);
        cout<<"\nAuthor Name: ";
        puts(authorName);
        cout<<"\nGenre: ";
        puts(genre);
    }
    void modify_book(){
        cout<<"\nBook no. : "<<bookNum;
        cout<<"\nModify Book Name : ";
        gets(bookName);
        cout<<"\nModify Author's Name of Book : ";
        gets(authorName);
        cout<<"\nModify Genre of Book : ";
        gets(genre);
        cout<<"\nModify wheter to add book to read? (y/n): ";
        cin>>onRead;
    }
    char* getBookNum(){
	    return bookNum;
    }
    char getRead(){
        return onRead;
    }
    void report(){
	    cout<<bookNum<<setw(25)<<bookName<<setw(25)<<authorName<<setw(25)<<genre<<endl;
    }
};

fstream fp,fp1;
book bk;

void write_book(){
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do{
        clrscr();
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void display_onRead(){
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book))){
        if(bk.getRead() == 'y'){
            bk.show_book();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

void modify_book(){
    char n[6];
    int found=0;
    clrscr();
    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
    cout<<"\n\n\tEnter The book no. of The book";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0){
        if(strcmpi(bk.getBookNum(),n)==0){
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

void delete_book(){
    char n[6];
    clrscr();
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book))){
        if(strcmpi(bk.getBookNum(),n)!=0){
            fp2.write((char*)&bk,sizeof(book));
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}

void display_all(){
    clrscr();
    fp.open("book.dat",ios::in);
    if(!fp){
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"----------------------------------------------------------------------------\n";
    cout<<"Book No."<<setw(12)<<"Book Name"<<setw(30)<<"Author"<<setw(25)<<"Genre\n";
    cout<<"----------------------------------------------------------------------------\n";
    while(fp.read((char*)&bk,sizeof(book))){
        bk.report();
    }
    fp.close();
    getch();
}


void main_menu(){
    clrscr();
    int ch2;
    cout<<"\n\n\n\t -: MENU :-";
    cout<<"\n\n\t1.CREATE BOOK ";
    cout<<"\n\n\t2.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t3.DISPLAY BOOK(S) ON READ ";
    cout<<"\n\n\t4.MODIFY BOOK ";
    cout<<"\n\n\t5.DELETE BOOK ";
    cout<<"\n\n\t6.EXIT ";
    cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
    cin>>ch2;
    switch(ch2){
        case 1: clrscr();
                write_book();break;
        case 2: display_all();break;
        case 3: {
                   clrscr();
                   display_onRead();
                   break;
                }
        case 4: modify_book();break;
        case 5: delete_book();break;
        case 6: exit(0);
        default:cout<<"\a";
    }
    main_menu();
}

void main(){
    main_menu();
}

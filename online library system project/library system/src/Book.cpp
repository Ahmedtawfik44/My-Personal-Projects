#include "Book.h"

int Book:: count=0;
Book::Book()
{
    title=" ";
    isbn=" ";
    category=" ";
    averageRating=0.0;
    count++;
    id=count;
   // author= User; //call empty constructor user
    numrate=0;
    sumrate=0.0;
}
 Book::Book(string title, string isbn, string category)
 {
     this->title=title;
     this->isbn=isbn;
     this->category=category;
     count++;
     id=count;
    // author=new User;
     numrate=0;
    sumrate=0.0;
 }
 Book::Book(const Book&b )
 {
     title=b.title;
     isbn=b.isbn;
     category=b.category;
     averageRating=b.averageRating;
     id=b.id;
     author=b.author;
     numrate=b.numrate;
    sumrate=b.sumrate;
 }
 void Book::setTitle(string t)
 {
     title=t;
 }
 string Book::getTitle() const
 {
     return title;
 }
 void Book::setIsbn(string i)
 {
     isbn=i;
 }
 string Book::getIsbn() const
 {
     return isbn;
 }
 void Book::setId(int d)
 {
     id=d;
 }
 int Book::getId() const
 {
     return id;
 }
 void Book::setCategory(string c )
 {
     category=c;
 }
 string Book::getCategory()const
 {
     return category;
 }
 void Book::setAuthor(const User &u )
 {
       author=u;
 }
 User Book::getAuthor() const
 {
     return author;
 }
 void Book::rateBook(double r)
 {
     sumrate+=r;
     numrate++;
     averageRating=sumrate/numrate;

 }
 double Book::getAverageRating () const
 {
     return averageRating;
 }
 bool Book::operator==(const Book&b)
 {
     return(id==b.id || title==b.title ||isbn==b.isbn ||category==b.category ||averageRating==b.averageRating ||author==b.author);

 }
  ostream &operator<<(ostream &o, const Book &b)
 {
        o<<endl<<"     User "<<b.id<<endl<<"information ... "<<endl;
        cout<<"=================================="<<endl;
        o<<"->"<<"title : "<<b.title<<endl<<"->";
        o<<"isbn : "<<b.isbn<<endl<<"->";
        o<<"category : "<<b.category<<endl<<"->";
        o<<"average Rating : "<<b.averageRating<<endl<<"->";
        o<<"ID : "<<b.id<<endl;
        if(b.author.getName()!="")
            o<<"author : "<<b.author<<endl;
        cout<<"==================================="<<endl;
        return o;
 }
 istream &operator>>( istream &i, Book &b)
 {
     cout<<" Enter the user Information in this order"<<endl;
        cout<<" Enter Title : "<<endl;
        i>>b.title;
        cout<<"Enter isbn : "<<endl;
        i>>b.isbn;
        cout<<"Enter Category : "<<endl;
        i>>b.category;
        return i;
 }


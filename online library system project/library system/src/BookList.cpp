#include "BookList.h"

BookList::BookList()
{
    capacity=0;
    booksCount=0;
}
BookList::BookList(int capacity)
{
    this->capacity=capacity;
    booksCount=0;
    books=new Book[capacity];
}
void BookList::addBook(const Book&b)
{
    if(booksCount<capacity)
    {
        books[booksCount]=b;
        books[booksCount].setId(booksCount+1); //because avoid incorrect id
        booksCount++;
    }
    else
        cout<<"the size is full "<<endl;
}
Book* BookList::searchBook(string name)
{
    for(int i=0; i<booksCount; i++)
        if(books[i].getTitle()==name)
            return &books[i];
    return nullptr;
}
Book* BookList::searchBook(int id)
{
    for(int i=0; i<booksCount; i++)
        if(books[i].getId()==id)
            return &books[i];
    return nullptr;
}
void BookList::deleteBook(int id)
{
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getId()==id)
        {
            while(i<booksCount-1)
            {
                books[i]=books[i+1];
                books[i].setId(i+1);
                i++;
            }
            booksCount--;
            capacity--;
            break;
        }
    }

}
Book BookList::getTheHighestRatedBook()
{
    double maxx_rate=-1.0;
    int index=0;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getAverageRating()>maxx_rate)
        {
            maxx_rate=books[i].getAverageRating();
            index=i;
        }
    }
    return books[index];
}
void BookList::getBooksForUser(const User &u)
{
    bool ch=0;
    for(int i=0; i<booksCount; i++)
        if(books[i].getAuthor()==u)
        {
            ch=1;
            cout<<books[i]<<" "<<endl;
        }

    if(ch==0)
        cout<<"No Books of this author "<< " "<<endl;

}
Book& BookList::operator[] (int index)
{
    if(index<0 || index>=booksCount)
        cout<<" Index Error"<< " "<<endl;
    else
        return books[index];
}
ostream&operator<<(ostream &o,const BookList &bl )
{
    for(int i=0; i<bl.booksCount; i++)
        o<<bl.books[i]; //call object in class book
    return o;
}
BookList::~BookList()
{
    delete []books;
}

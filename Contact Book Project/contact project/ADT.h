#include<iostream>
using namespace std;
#include"person.h"
#include<fstream>
#include<iomanip>
template<class  t>
class ADT_dynamic
{
private:
    t* a;
    size_t capacity;
    size_t size_a;
    //Utility function
    void Resiz(size_t c)
    {
        t *temp=new t[c];
        for(size_t i=0; i<size_a; i++)
            temp[i]=a[i];

        delete []a;

        a=temp;
        capacity=c;
    }

public:
    ADT_dynamic(size_t c):capacity(c),size_a(0)
    {
        a=new t[capacity];
    }

    void Append( const t& x)
    {
        if(size_a>=capacity)
            Resiz(capacity*2);
        a[size_a++]=x;
    }

    void Insert(const t& x,size_t index )
    {
        if(index>size_a)
            throw out_of_range("index out of range");

        if(index>=capacity)
            throw out_of_range("index out of range");

        if(size_a>=capacity)
            Resiz(capacity*2);

        for(size_t i=size_a; i>index; i--)
            a[i]=a[i-1];

        size_a++;
        a[index]=x;
    }


    t Remove()
    {
        if(size_a==0)
            throw out_of_range("the array is Empty");

        if(size_a<capacity/4)
            Resiz(capacity/2); //shrink capacity


        return a[--size_a];

    }

    void Delete(const size_t pos)
    {
        if(size_a==0)
            throw out_of_range("the array is Empty");
        if (pos>=size_a)
            throw "index out of range";

        for(size_t i=pos; i<size_a; i++)
            a[i]=a[i+1];

        size_a--;

        if(size_a<capacity/4)
            Resiz(capacity/2); //shrink capacity
    }

    t& Get(const size_t index) const  //                       ,
    {
        if (index>size_a)
            throw "index out of range";
        if(index>=capacity)
            throw out_of_range("index out");

        return a[index];
    }

    size_t Get_size()const
    {
        return size_a;
    }

    void Reverse()
    {
        for(int i=0,j=size_a-1; i<j; i++,j--)
        {
            person temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }


    }
//search by last name    2 in main

    void Buble_sort_last_name()
    {
        for(size_t i=0; i<size_a-1; i++)
        {
            bool ch=0;
            for(size_t j=0; j<size_a-1-i; j++)
            {
                if(a[j].get_last_name()>a[j+1].get_last_name())
                {
                    person temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp ;
                    ch=1;
                }
            }
            if(ch==0)
            {
                break;
            }

        }

    }

    bool linear_search(string x)
    {
        bool ch=0;
        for(size_t i=0; i<size_a; i++)
            if(a[i]==x)
                ch=1;
        if(ch==1)
        {
            cout<<"found"<<endl;
            return true;
        }
        else
        {
            cout<<"not found"<<endl;
            return false;
        }
    }

    //search by last name    2 in main

    void Binairy_search_last_name(string x)
    {
        Buble_sort_last_name();
        size_t l=0,h=size_a-1;
        bool ch=0;
        while(l<=h)
        {
            size_t m=(l+h)/2;
            if(a[m].get_last_name()==x)
            {
                ch=1;
                a[m].showdata(m+1);
                // return;
            }

            if(a[m].get_last_name()>x)
                h=m-1;
            else
                l=m+1;
        }

         if(ch==0)
            cout<<" Not Found ";
        else
            cout<< " ";
    }

//end search by last name

// search by classification 3 in main

    void Buble_sort_classification()
    {
        for(size_t i=0; i<size_a-1; i++)
        {
            bool ch=0;
            for(size_t j=0; j<size_a-1-i; j++)
            {
                if(a[j].get_classification()>a[j+1].get_classification())
                {
                    person temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp ;
                    ch=1;
                }
            }
            if(ch==0)
            {
                break;
            }

        }

    }


    void Binairy_search_classification(string x)
    {
        Buble_sort_classification();
        size_t l=0,h=size_a-1;
        bool ch=0;
        while(l<=h)
        {
            size_t m=(l+h)/2;
            if(a[m].get_classification()==x)
            {
                ch=1;
                a[m].showdata(m+1);
                //return;
            }

            if(a[m].get_classification()>x)
                h=m-1;
            else
                l=m+1;
        }

        if(ch==0)
            cout<<" Not Found ";
        else
            cout<< " ";
    }

//end search classification


    void print()
    {
        for(size_t i=0; i<size_a; i++)
            cout<<a[i]<<" ";
        cout<<endl;

    }


    void clear_all_variable()
    {
        size_a=0;
        Resiz(0);//shrink
    }

    //4 in main
    void print_all()
    {
        if(size_a==0)
            cout<<"No contact "<<endl;
        for(size_t i=0; i<size_a; i++)
        {
            a[i].showdata(i+1);
        }


    }

//5 in main
    void print_fav()
    {

        for(int i=0; i<size_a; i++)
        {
            if(a[i].get_favorate())
            {
                a[i].showfav(i+1);

            }
        }
    }

// saved file
    void save_to_file()
    {
        ofstream file_save("savecontact.txt");
        if (!file_save)
        {
            cout << "cant open file" << endl;
            return;
        }

        file_save << setw(20) << left << "ID"
                  << setw(20) << "FName"
                  << setw(20) << "LName"
                  << setw(20) << "Classification"
                  << setw(10) << "Fav"
                  << setw(40) << "Address"
                  << setw(80) << "Phone Number" << endl;

        file_save << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


        for (size_t i = 0; i < size_a; i++)
        {
            file_save << setw(20) << left << i + 1
                      << setw(20) << a[i].get_first_name()
                      << setw(20) << a[i].get_last_name()
                      << setw(20) << a[i].get_classification()
                      << setw(10) << a[i].get_favorate()
                      << setw(40) << a[i].get_street_number() + " " + a[i].get_street_name() + " " + a[i].get_city() + " " + a[i].get_country()
                      << setw(80) << a[i].get_phone()
                      << endl;
        }

        file_save.close();
        cout << "Data saved to file" << endl;

    }

//Modifiy
    void update(size_t index)
    {
        Delete(index);

    }

    ~ADT_dynamic()
    {
        delete []a;
    }
};


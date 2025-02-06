#ifndef ADDRESE_H
#define ADDRESE_H
#include<iostream>
#include<iomanip>
using namespace std;
#include<string>

class addrese
{
    public:
        addrese();
        string get_street_name()const;
        string get_street_number()const;
        string get_country()const;
        string get_city()const;
        void display();



 protected:
        string street_name;
        string street_number;
        string city;
        string country;
};

#endif // ADDRESE_H

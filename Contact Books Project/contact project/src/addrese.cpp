#include "addrese.h"

addrese::addrese( ){
street_name=" ";
street_number=" ";
city=" ";
country=" ";

}


string addrese::get_street_name()const
{
    return street_name;
}

string addrese::get_street_number()const
{
    return street_number;
}

string addrese::get_country()const
{
    return country;
}

string addrese::get_city()const
{
    return city;
}

void addrese::display()
{
    cout<<"          ::Enter Addrese details::"<<endl;
    cout<<"streetnum:";
    cin>>street_number;
    cout<<endl;
    cout<<"streetname:";
    cin>>street_name;
    cout<<endl;
    cout<<"town:";
    cin>>city;
    cout<<endl;
    cout<<"state:";
    cin>>country;
    cout<<endl;
}


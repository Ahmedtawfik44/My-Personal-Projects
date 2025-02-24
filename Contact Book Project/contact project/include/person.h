#ifndef PERSON_H
#define PERSON_H
#include"addrese.h"
using namespace std;
#include<iostream>
#include<string>
#include<fstream>

class person:public addrese
{
    public:
        person();
        person(string fn,string ln,string p,string cla,string m,bool f,addrese a);
        string get_first_name()const;
        string get_last_name()const;
        string get_classification()const;
        string get_phone()const;
        string get_mail()const;
        bool get_favorate()const;
        void print_cin_add();
        void showdata(size_t id);
     void showfav(size_t id);
        size_t getid();
        void load();

    protected:
        string first_name;
        string last_name;
        addrese Addrese;
        string classification;
        string phone;
        string mail;
        bool favorate;
        size_t id=0;


};



#endif // PERSON_H

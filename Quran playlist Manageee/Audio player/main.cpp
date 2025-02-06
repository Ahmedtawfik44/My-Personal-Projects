#include <iostream>
#include"audio.h"
#include"playlist.h"
#include"surah.h"

using namespace std;



int main() {
  playlist p;
  surah s(p);

while(true){
int n;

s.show_consol();

cout<<"                           Enter Your Choise : ";
cin>>n;
cout<<endl;

switch(n){
case 1 :
    p.add_playlist();
     break;

case 2 :
    s.add_surah();
    break;

case 3 :
   s.remove_surah();
    break;

case 4 :
   s.update_surah();
    break;

case 5:
   p.display_playlist();
    break;

case 6 :
   s.display_surah();
    break;

case 7 :
   s.display_specific();
     break;

case 8 :
   s.play_specific();
    break;

case 9 :
    s.save_playlist();
    break;

case 10 :
   s.load_all();
    break;

case 11 :
   p.remove_playlist();
    break;

case 12 :
    return 0;
}

}

}

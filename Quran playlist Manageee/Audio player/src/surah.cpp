#include "surah.h"
void surah::add_surah() {
    char choise;

    string p_list_name;
    cout << "Enter Playlist Name: ";
    cin >> p_list_name;

    do{

    playlistnode* playlistNode = playlist_object.find_playlist(p_list_name);

    if (playlistNode) {
        audio_object.cin_add_surah();
        playlistNode->surah_list.insert_End(audio_object);
    } else {
        cout << "Playlist not found." << endl;
        return;
    }

    cout<<"Add another surah to the current list? press(y) ";
    cin>>choise;
   }while(choise=='Y'||choise=='y');
}

void surah::load_all(){
char choise;
 ifstream f("load.txt");

    if(!f.is_open()){
      cout<<"  "<<endl;
     return;
    }

    string p_list_name;
    cout << "Enter Playlist Name: ";
    f >> p_list_name;

    do{

    playlistnode* playlistNode = playlist_object.find_playlist(p_list_name);

    if (playlistNode) {
        audio_object.cin_add_surah();
        playlistNode->surah_list.insert_End(audio_object);
    } else {
        cout << "Playlist not found." << endl;
        return;
    }

    cout<<"Add another surah to the current list? press(y) ";
    f>>choise;
   }while(choise=='Y'||choise=='y');

playlist_object.load_playlist(f);

f.close();
}

void surah::display_surah(){
          playlistnode* playlist =playlist_object.h;

          if (playlist == nullptr) {
        cout << "No playlists available" << endl;
        return;
    }

 cout<<"----------------------"<<endl;
       while(playlist!=nullptr){

      cout<< "              Playlist : "<< playlist->playlistname<<endl;
        playlist->surah_list.print();
        playlist=playlist->next;

       }

}


void surah::save_playlist(){

    ofstream f("save_playlist");
          playlistnode* playlist =playlist_object.h;

          if (playlist == nullptr) {
        cout << "No playlists available" << endl;
        f.close();
        return;
    }

      if (!f)
        {
            cout << "cant open file" << endl;
            return;
        }

 f<<"----------------------"<<endl;
       while(playlist!=nullptr){

      f<< "              Playlist : "<< playlist->playlistname<<endl;
        playlist->surah_list.print_file(f);
        playlist=playlist->next;

       }
    f.close();
    cout<<"Data Saved..."<<endl;

}


void surah::display_specific(){
string s;
cout<<"Enter Playlist Name : ";
cin>>s;

playlistnode* check=playlist_object.find_playlist(s);

 if (check == nullptr) {
        cout << "No playlists available" << endl;
        return;//بدل م اكتب else
    }

 cout<<"----------------------"<<endl;
       cout<< "              Playlist : "<< check->playlistname<<endl;
        check->surah_list.print();
}


void surah::play_specific() {
    string x;
    cout << "Enter playlist name: ";
    cin >> x;

    playlistnode* check = playlist_object.find_playlist(x);
    if (check == nullptr) {
        cout << "Playlist not found..." << endl;
        return;
    }

    Node<audio>* temp = check->surah_list.return_head();
    if (temp == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }

    atomic<bool> stop_audio(false);
    atomic<bool> paused_audio(false);
    atomic<bool> exit_playlist(false);


    while (temp != nullptr && !exit_playlist) {
        audio& content_audio = temp->data;
 cout << "\nYou are listening to => " << content_audio.get_name_file() << "..." << endl;

        stop_audio = false;
        paused_audio = false;

        thread audio_thread([&]() {
            while (!stop_audio) {
                if (!paused_audio) {
                    PlaySound(content_audio.get_path_file().c_str(), NULL, SND_FILENAME | SND_ASYNC);
                    while (!paused_audio && !stop_audio) {
                        this_thread::sleep_for(chrono::milliseconds(100));
                    }
                } else {
                    PlaySound(NULL, 0, 0);
                    while (paused_audio && !stop_audio) {
                        this_thread::sleep_for(chrono::milliseconds(100));
                    }
                }
            }
            PlaySound(NULL, 0, 0);
        });

        string s;
        while (true) {
            cin >> s;

            if (s == "->") {
                stop_audio = true;
                audio_thread.join();
                if (temp->next != nullptr) temp = temp->next;
                else cout << "This is the last surah." << endl;
                break;
            } else if (s == "<-") {
                stop_audio = true;
                audio_thread.join();
                if (temp->prev != nullptr) temp = temp->prev;
                else cout << "This is the first surah." << endl;
                break;
            } else if (s == "=") {
                paused_audio = true;
                cout << "Surah paused." << endl;
            } else if (s == "^") {
                if (paused_audio) {
                    paused_audio = false;
                    cout << "Surah resumed." << endl;
                } else {
                    cout << "Surah is already playing." << endl;
                }
            } else if (s == "q") {
                stop_audio = true;
                exit_playlist = true;
                break;
            } else {
                cout << "Invalid input. Use '<', '>', '=', '^', or 'q'." << endl;
            }
        }

        if (audio_thread.joinable()) audio_thread.join();
    }

    cout << "Exiting playlist..." << endl;
}


 void surah::update_surah(){
     string x;
    cout<<"Enter Playlist name : ";
    cin>>x;

    playlistnode* check=playlist_object.find_playlist(x);


 if (check == nullptr) {
        cout << "No playlists available" << endl;
        return;
    }


    check->surah_list.update();


 }

 void surah::remove_surah(){
     string x;
    cout<<"Enter Playlist name : ";
    cin>>x;

    playlistnode* check=playlist_object.find_playlist(x);


 if (check == nullptr) {
        cout << "No playlists available" << endl;
        return;
    }


    check->surah_list.Remove();

 }

 void surah::show_consol(){


    cout<<endl;
    cout<<"                          =========================================================================                                 "<<endl;
    cout<<"                                                  Quran Playlist Manager Menue                                                        "<<endl;
    cout<<"                          -------------------------------------------------------------------------                                    "<<endl;
    cout<<"                           1-Add a new Playlist                                                                                       "<<endl;
    cout<<"                           2-Add Surah to existing Playlist                                                                         "<<endl;
    cout<<"                           3-Remove Surah from an existing  Playlist                                                                "<<endl;
    cout<<"                           4-Update the order of exsisting playlist                                                                 "<<endl;
    cout<<"                           5-Display All Current Playlist                                                                             "<<endl;
    cout<<"                           6-Display All Playlist Surah                                                                                  "<<endl;
    cout<<"                           7-Display Surah in a specific Playlist                                                                         "<<endl;
    cout<<"                           8-Play Surah from specific Playlist                                                                                "<<endl;
    cout<<"                             Use left arrow (<-) to play the previous surah                                                               "<<endl;
    cout<<"                             Use right arrow (->) to play the next surah                                                               "<<endl;
    cout<<"                             Use left arrow (=) to pause the current surah                                                               "<<endl;
    cout<<"                             press q to exit current playlist & return Back to Menue                                                        "<<endl;
    cout<<"                           9-Save an existing Playlist to a file                                                                              "<<endl;
    cout<<"                           10-Load an existing Playlist from afile                                                                               "<<endl;
    cout<<"                           11-Remove an existing Playlist                                                                                      "<<endl;
    cout<<"                           12-Exit                                                                                                    "<<endl;
    cout<<"                          =========================================================================                                   "<<endl;


 }

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<iostream>
#include"../DLL.h"
#include"audio.h"
#include <iomanip>
#include<string>
#include<fstream>


struct playlistnode{    //«··Ì‰ﬂœ·Ì”  Â  ›—⁄ „‰Â«
string playlistname;
sll<audio> surah_list;
playlistnode *next;
playlistnode *prev;
playlistnode():next(nullptr),prev(nullptr){}
};

class playlist
{
    public:
    playlist();
    void add_playlist();
    playlistnode* find_playlist(string&);
    void display_playlist();
    void delete_playlist_first();
    void delete_playlist_pos(string);
    void remove_playlist();
    void load_playlist(ifstream &f);
    playlistnode *h;
    private:



};

#endif // PLAYLIST_H

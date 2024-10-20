#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Song
{
public:
    string title;
    Song *next;
    Song *prev;
    Song(string name);
};

class Playlist
{
private:
    Song *head;
    Song *tail;
    Song *current;

public:
    Playlist();
    void addSongAtStart(string name);
    void addSongAtEnd(string name);
    void insertSongAfter(string afterSong, string name);
    void removeSong(string name);
    void displaySongsFromStart();
    void displaySongsFromEnd();
    bool searchSong(string name);
    void playNext();
    void playPrevious();
    void savePlaylistToFile(string filename);
    void loadPlaylistFromFile(string filename);
};

#endif // PLAYLIST_H

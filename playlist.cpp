#include "playlist.h"

Song::Song(string name)
{
    title = name;
    next = NULL;
    prev = NULL;
}

Playlist::Playlist()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

void Playlist::addSongAtStart(string name)
{
    Song *newSong = new Song(name);
    if (head == NULL)
    {
        head = tail = current = newSong;
    }
    else
    {
        newSong->next = head;
        head->prev = newSong;
        head = newSong;
    }
    cout << "Song added: " << name << " at the start of the playlist." << endl;
}

void Playlist::addSongAtEnd(string name)
{
    Song *newSong = new Song(name);
    if (tail == NULL)
    {
        head = tail = current = newSong;
    }
    else
    {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    cout << "Added song: " << name << " at the end of the playlist." << endl;
}

void Playlist::insertSongAfter(string afterSong, string name)
{
    Song *temp = head;
    while (temp != NULL && temp->title != afterSong)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song '" << afterSong << "' not found in the playlist." << endl;
        return;
    }
    Song *newSong = new Song(name);
    newSong->next = temp->next;
    newSong->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newSong;
    }
    else
    {
        tail = newSong;
    }
    temp->next = newSong;
    cout << "Inserted song: " << name << " after " << afterSong << "." << endl;
}

void Playlist::removeSong(string name)
{
    Song *temp = head;
    while (temp != NULL && temp->title != name)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song '" << name << "' not found in the playlist." << endl;
        return;
    }
    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else if (temp == tail)
    {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if (temp == current)
    {
        current = head;
    }

    delete temp;
    cout << "Removed song: " << name << " from the playlist." << endl;
}

void Playlist::displaySongsFromStart()
{
    Song *temp = head;
    if (temp == NULL)
    {
        cout << "The playlist is empty." << endl;
        return;
    }
    cout << "Songs from start to end: " << endl;
    while (temp != NULL)
    {
        cout << temp->title << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Playlist::displaySongsFromEnd()
{
    Song *temp = tail;
    if (temp == NULL)
    {
        cout << "The playlist is empty." << endl;
        return;
    }
    cout << "Songs from end to start: " << endl;
    while (temp != NULL)
    {
        cout << temp->title << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

bool Playlist::searchSong(string name)
{
    Song *temp = head;
    while (temp != NULL)
    {
        if (temp->title == name)
        {
            cout << "Song '" << name << "' found in the playlist." << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Song '" << name << "' not found in the playlist." << endl;
    return false;
}

void Playlist::playNext()
{
    if (current == NULL || current->next == NULL)
    {
        cout << "There are no more songs to play next." << endl;
    }
    else
    {
        current = current->next;
        cout << "Playing next song: " << current->title << endl;
    }
}

void Playlist::playPrevious()
{
    if (current == NULL || current->prev == NULL)
    {
        cout << "There are no previous songs to play." << endl;
    }
    else
    {
        current = current->prev;
        cout << "Playing previous song: " << current->title << endl;
    }
}

void Playlist::savePlaylistToFile(string filename)
{
    ofstream outfile(filename);
    if (!outfile.is_open())
    {
        cout << "Error: Could not open file for saving." << endl;
        return;
    }
    Song *temp = head;
    while (temp != NULL)
    {
        outfile << temp->title << endl;
        temp = temp->next;
    }
    outfile.close();
    cout << "Playlist saved to " << filename << endl;
}

void Playlist::loadPlaylistFromFile(string filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "Error: Could not open file for loading." << endl;
        return;
    }
    string line;
    while (getline(infile, line))
    {
        addSongAtEnd(line);
    }
    infile.close();
    cout << "Playlist loaded from " << filename << endl;
}

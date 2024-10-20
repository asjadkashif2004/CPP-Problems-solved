#include "playlist.h"

int main()
{
    Playlist myPlaylist;
    int choice;
    string songName, afterSong, filename;

    do
    {
        cout << "Welcome to Asjad's Playlist!" << endl;
        cout << "\n--- Playlist Menu ---" << endl;
        cout << "1. Add song at the beginning" << endl;
        cout << "2. Add song at the end" << endl;
        cout << "3. Insert song after a specific song" << endl;
        cout << "4. Remove a song" << endl;
        cout << "5. Display songs from start to end" << endl;
        cout << "6. Display songs from end to start" << endl;
        cout << "7. Search for a song" << endl;
        cout << "8. Play next song" << endl;
        cout << "9. Play previous song" << endl;
        cout << "10. Save the playlist" << endl;
        cout << "11. Load the playlist" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter song name to add at the beginning: ";
            cin.ignore();
            getline(cin, songName);
            myPlaylist.addSongAtStart(songName);
            break;
        case 2:
            cout << "Enter song name to add at the end: ";
            cin.ignore();
            getline(cin, songName);
            myPlaylist.addSongAtEnd(songName);
            break;
        case 3:
            cout << "Enter the name of the song after which to insert: ";
            cin.ignore();
            getline(cin, afterSong);
            cout << "Enter the new song name: ";
            getline(cin, songName);
            myPlaylist.insertSongAfter(afterSong, songName);
            break;
        case 4:
            cout << "Enter song name to remove: ";
            cin.ignore();
            getline(cin, songName);
            myPlaylist.removeSong(songName);
            break;
        case 5:
            myPlaylist.displaySongsFromStart();
            break;
        case 6:
            myPlaylist.displaySongsFromEnd();
            break;
        case 7:
            cout << "Enter song name to search: ";
            cin.ignore();
            getline(cin, songName);
            myPlaylist.searchSong(songName);
            break;
        case 8:
            myPlaylist.playNext();
            break;
        case 9:
            myPlaylist.playPrevious();
            break;
        case 10:
            cout << "Enter filename to save the playlist: ";
            cin >> filename;
            myPlaylist.savePlaylistToFile(filename);
            break;
        case 11:
            cout << "Enter filename to load the playlist: ";
            cin >> filename;
            myPlaylist.loadPlaylistFromFile(filename);
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

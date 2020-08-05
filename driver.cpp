#include "Dlists.h"
#include <iostream>
using namespace std;

int PromptMenu();
SongType createSong();

int main()
{
	Dlists myList;
	SongType newSong, tempSong;
	string songName;
	int choice;
	bool find;

	do
	{
		cout << endl;
		// Display menu and get input choice
		choice = PromptMenu();

		// switch statement to process input choice
		switch (choice)
		{
		case 1: cout << "\n~Displaying the list~" << endl;
			myList.print();
			break;
		case 2: newSong = createSong();
			myList.PutSong(newSong);
			break;
		case 3: cout << "Enter the song to be deleted via song name: ";
			cin.ignore();
			getline(cin, songName);
			tempSong.setSongName(songName);
			myList.DeleteSong(tempSong);
			break;
		case 4: cout << "Enter song to be modified: ";
			cin.ignore();
			getline(cin, songName);
			tempSong.setSongName(songName);
			myList.ModifySong(tempSong);
			break;
		case 5: cout << "Enter song name to find: ";
			cin.ignore();
			getline(cin, songName);
			tempSong.setSongName(songName);
			find = myList.FindSong(tempSong);
			if (find)
				cout << "'" << songName << "' was found in database." << endl;
			else
				cout << "'" << songName << "' was not found in database." << endl;
			break;
		case 6: cout << "\nQuitting the menu...\n";
			break;
		} // end of switch
	} while (choice != 6);  // end of do-while loop
	return 0;
}

int PromptMenu()
{
	// to hold user choice
	int choice;

	// display menu to screen
	cout << endl;
	cout << "\t~SONG DATABASE MENU AND FEATURES~\n"
		<< "\t----------------------\n"
		<< "\t1) Display the list\n"
		<< "\t2) Put a song into the list\n"
		<< "\t3) Delete a song from the list\n"
		<< "\t4) Modify a song in the list\n"
		<< "\t5) Find a song in the list\n"
		<< "\t6) QUIT\n";

	// user enters choice
	cout << "Enter input 1-6: ";
	cin >> choice;

	// validate the input
	while (choice < 1 || choice > 6)
	{
		cout << "Invalid number...\n"
			<< "Enter input 1-6: ";
		cin >> choice;
	}
	return choice;
}

SongType createSong()
{
	SongType song;
	int d, releaseYear;
	string songName, songArtist, genre, language;

	cout << "Enter the song's name: ";
	cin.ignore();
	getline(cin, songName);
	song.setSongName(songName);
	cout << "Enter the song's artist: ";
	getline(cin, songArtist);
	song.setArtist(songArtist);
	cout << "Enter the song's duration: ";
	cin >> d;
	song.setDuration(d);
	cout << "Enter the song's genre: ";
	cin.ignore();
	getline(cin, genre);
	song.setGenre(genre);
	cout << "Enter the song's release year: ";
	cin >> releaseYear;
	song.setReleaseYear(releaseYear);
	cout << "Enter the song's language: ";
	cin >> language;
	song.setSongLanguage(language);

	return song;
}

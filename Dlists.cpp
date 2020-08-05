#include "Dlists.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

struct SongNode
{
	SongType info;
	SongNode* next;
	SongNode* back;
};

Dlists::Dlists()
{
	length = 0;
	listData = nullptr;
	currentPos = nullptr;
}

SongType Dlists::GetSong(SongType &song)
{
	SongNode *location = getListData();
	bool moreToSearch = location != nullptr;
	bool found = false;

	while (moreToSearch && !found)
	{
		switch (song.ComparedTo(location->info))
		{
		case GREATER: location = location->next;
			moreToSearch = location != nullptr;
			break;
		case EQUAL:   song = location->info;
			found = true;
			break;
		case LESS:	moreToSearch = false;
			break;
		}
	}
	return song;
}

bool Dlists::FindSong(SongType song)
{
	SongNode *location = listData;
	bool moreToSearch = (location != NULL);
	bool found = false;

	while (moreToSearch && !found)
	{
		if (song.getSongName() == location->info.getSongName())
		{
			found = true;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return found;
}

void Dlists::PutSong(SongType song)
{
	SongNode *traverse;
	SongNode *newNode = new SongNode;
	traverse = listData;

	if (listData == NULL)
	{
		listData = newNode;
		newNode->info = song;
		newNode->back = NULL;
		newNode->next = NULL;
	}
	else
	{
		while (traverse->next != nullptr)
		{
			traverse = traverse->next;
		}
		traverse->next = newNode;
		newNode->next = NULL;
		newNode->back = traverse;
		newNode->info = song;
	}
	length++;
}

void Dlists::DeleteSong(SongType song)
{
	SongNode *location;
	location = listData;

	if (location == NULL)	//checks for empty list
	{
		return;
	}
	else if (song.getSongName() == listData->info.getSongName() && length == 1)
	{
		location->next = NULL;
		location->back = NULL;
		listData = NULL;
		length--;
		delete location;
	}
	else if (song.getSongName() == listData->info.getSongName())	// checks first node
	{
		location->next->back = NULL;
		listData = location->next;
		length--;
		delete location;
	}
	else
	{
		location = location->next; // move to second node and check rest of list
		bool found = false;
		while (location != NULL && !found)
		{
			if (song.getSongName() == location->info.getSongName())
			{
				found = true;
				if (location->next == NULL)
				{
					location->back->next = NULL;
					delete location;
				}
				else
				{
					location->back->next = location->next;
					location->next->back = location->back;
					delete location;
				}
			}
			else
				location = location->next;
		}
		if (!found)
			return;
		else
			length--;
	}
}

void Dlists::print() const
{	
	SongNode *head;
	head = listData;
	if (head == NULL)
	{
		cout << "List is Empty!" << endl;
	}

	while (head != NULL)
	{
	cout << "Song Name: " << head->info.getSongName() << endl;
	cout << "Artist: " << head->info.getArtist() << endl;
	cout << "Duration: " << head->info.getDuration() << " sec" << endl;
	cout << "Genre: " << head->info.getGenre() << endl;
	cout << "Release Year: " << head->info.getReleaseYear() << endl;
	cout << "Song Language: " << head->info.getSongLanguage() << endl;
	cout << "------------------------------------------------";
	cout << endl;
	head = head->next;
	}
	
}
int Dlists::MenuForModifySong()
{
	int choice;
	{
		cout << "\tModify Song Menu\n"
			<< "\t1) Change song name\n"
			<< "\t2) Change song artist\n"
			<< "\t3) Change song duration\n"
			<< "\t4) Change song genre\n"
			<< "\t5) Change song release year\n"
			<< "\t6) Change song language\n"
			<< "\t7) QUIT\n";
		cout << "Enter an input choice: ";
		cin >> choice;
	}
	return choice;
}

void Dlists::ModifySong(SongType &song)
{
	int choice;
	string temp;
	int temp1;
	int x;

	SongNode *location;
	location = listData;
	if (location == NULL)	//checks for empty list
	{
		cout << "List is empty!" << endl;
		return;
	}
	else
	{
		bool seen = false;
		while (location != NULL && !seen)
		{
			if (location->info.getSongName() == song.getSongName())
			{
				seen = true;
			}
			else
				location = location->next;
		}
		if (seen)
		{
			choice = MenuForModifySong();

			switch (choice)
			{
			case 1: cout << "Enter the new song name: ";
				cin.ignore();
				getline(cin, temp);
				location->info.setSongName(temp);
				break;
			case 2: cout << "Enter the new song artist: ";
				cin.ignore();
				getline(cin, temp);
				location->info.setArtist(temp);
				break;
			case 3: cout << "Enter the new song duration: ";
				cin >> x;
				location->info.setDuration(x);
				break;
			case 4: cout << "Enter the new song genre: ";
				cin.ignore();
				getline(cin, temp);
				location->info.setGenre(temp);
				break;
			case 5: cout << "Enter the new song release year: ";
				cin >> temp1;
				location->info.setReleaseYear(temp1);
				break;
			case 6: cout << "Enter the new song language: ";
				cin >> temp;
				location->info.setSongLanguage(temp);
				break;
			default: break;
			}
		}
		else
		{
			cout << "Not found!" << endl;
			return;
		}
	}
}

Dlists::~Dlists()
{
	SongNode *tempPtr;          	// create a temporary pointer.

	while (listData != nullptr)     	// while head isn't empty.
	{
		tempPtr = listData;         	// set tempPtr to point at head.
		listData = listData->next;      	// set head to point at next node.
		delete tempPtr;         	// delete the temporary pointer.
	}
	length = 0;                 	// set the length of the list to zero.
	cout << "\nDeconstructor is called.\n";
}

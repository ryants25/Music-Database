#ifndef SONGTYPE_H
#define SONGTYPE_H
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class SongType
{
public:
	SongType();
	RelationType ComparedTo(SongType) const;

	void setDuration(int);    	// setters
	void setSongName(string);
	void setArtist(string);
	void setGenre(string);
	void setReleaseYear(int);
	void setSongLanguage(string);

	int getDuration() const;        	// getters
	string getSongName() const;
	string getArtist() const;
	string getGenre() const;
	int getReleaseYear() const;
	string getSongLanguage() const;

private:
	int duration;
	string songName;
	string artist;
	string genre;
	int releaseYear;
	string songLanguage;
};
#endif 	// SONGTYPE_H



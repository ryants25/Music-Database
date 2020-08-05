#include "SongType.h"
#include <string>
using namespace std;

SongType::SongType()
{
	duration = 0;
	artist = "";
	songName = "";
	genre = "";
	releaseYear = 0;
	songLanguage = "";
}

RelationType SongType::ComparedTo(SongType otherSong) const
{
	if (songName < otherSong.songName)
		return LESS;
	else if (songName > otherSong.songName)
		return GREATER;
	else if (songName == otherSong.songName)
		return EQUAL;
}

void SongType::setDuration(int number)
{
	duration = number;
}

void SongType::setSongName(string song)
{
	songName = song;
}

void SongType::setArtist(string person)
{
	artist = person;
}

void SongType::setGenre(string otherGenre)
{
	genre = otherGenre;
}

void SongType::setSongLanguage(string otherSongLanguage)
{
	songLanguage = otherSongLanguage;
}

void SongType::setReleaseYear(int otherRY)
{
	releaseYear = otherRY;
}

string SongType::getSongName() const
{
	return songName;
}

int SongType::getDuration() const
{
	return duration;
}

string SongType::getArtist() const
{
	return artist;
}

string SongType::getGenre() const
{
	return genre;
}

int SongType::getReleaseYear() const
{
	return releaseYear;
}

string SongType::getSongLanguage() const
{
	return songLanguage;
}


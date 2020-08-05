#ifndef DLISTS_H
#define DLISTS_H

#include "SongType.h"
using namespace std;

struct SongNode;
class Dlists
{
public:
	Dlists();
	~Dlists();
	void PutSong(SongType song);
	void DeleteSong(SongType song);
	SongType GetSong(SongType &song);
	bool FindSong(SongType song);
	void ModifySong(SongType &song);
	int MenuForModifySong();
	void print() const;
	int getLength() const { return length; }
	SongNode *getListData() { return listData; }
private:
	SongNode *listData;
	int length;
	SongNode *currentPos;
};
#endif // DLISTS_H



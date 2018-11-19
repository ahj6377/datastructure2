#pragma once
#include"MusicType.h"


class ManageType {
private:
	string Pkey;
	int played;
	int Index;
	string name;
	string artist;
public:
	ManageType() {
		Pkey = "";
		played = 0;
		Index = 0;
	};
	~ManageType() {};
	void setPkey(string key)
	{
		Pkey = key;
	}
	void setIndex(int I)
	{
		Index = I;
	}
	void IncreasePlayed()
	{
		played++;
	}
	void setName(string N)
	{
		name = N;
	}
	void setArtist(string A)
	{
		artist = A;
	}
	string getArtist()
	{
		return artist;
	}
	string getPkey()
	{
		return Pkey;
	}
	int getPlayed()
	{
		return played;
	}
	int getIndex()
	{
		return Index;
	}
	string getName()
	{
		return name;
	}

	void PrintNameNArtist()
	{
		cout << "\t°î¸í : " << name << endl;
		cout << "\t¾ÆÆ¼½ºÆ® : " << artist << endl << endl;
	}
	void PrintNameNIndex()
	{
		cout << "\t°î¸í : " << name << endl;
		cout << "\tIndex : " << Index << endl << endl;
	}

};


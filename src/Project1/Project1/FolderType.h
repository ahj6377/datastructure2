#pragma once


#include<iostream>

#include"ManageType.h"
#include"UnSortedLinkedList.h"
class FolderType {
private:
	UnSortedLinkedList<FolderType> Subfolder;
	UnSortedLinkedList<ManageType*> Musics;
	string Foldername;
	FolderType* Motherfolder;
public:
	FolderType() { Foldername = ""; Motherfolder = NULL; };
	~FolderType() {};
	void setFname(string N)
	{
		Foldername = N;
	};
	string getFname()
	{
		return Foldername;
	}
	void AddMusic(ManageType* in);
	void AddFolder();
	void DisplayAllinFolder();

	void setMfolder(FolderType* ptr)
	{
		Motherfolder = ptr;
	}
	FolderType* retMfodler()
	{
		return Motherfolder;
	}

	bool operator==(const FolderType& data)
	{
		if (Foldername == data.Foldername && Motherfolder == data.Motherfolder)
			return true;
		else
			return false;
	}
};
#pragma once
#include"MusicType.h"


class ManageType {
private:
	MusicType* mptr;
	bool Isdeleted;
public:
	ManageType() {
		bool Isdeleted = false;
		mptr = NULL;
	};
	~ManageType() {};
	void setPtr(MusicType* P)
	{
		mptr = P;
	}
	MusicType* getPtr()
	{
		return mptr;
	}
	void Deleted()
	{
		Isdeleted = true;
		mptr = NULL;
	}
	int getIndex()
	{
		if (Isdeleted == false)
		{
			return (mptr->GetNum());
		}
	}
	string getName()
	{	if(Isdeleted == false)
		return mptr->GetName();
	}
	string getPkey()
	{	if(Isdeleted == false)
		return mptr->GetPkey();
	}
	bool PrintNameNIndex();

	bool operator==(const ManageType& data)
	{
		if (mptr == data.mptr && Isdeleted == false)
			return true;
		else
			return false;
	}

};


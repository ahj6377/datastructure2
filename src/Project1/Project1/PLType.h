#pragma once
#include"ManageType.h"
#include"UnSortedLinkedList.h"
class PLType {
private:

	UnSortedLinkedList<ManageType*> PlayList;
	string PLname;
	int length;
public:
	PLType() { length = 0; PLname = ""; }
	~PLType() {}
	PLType(const PLType& data);
	void setPLname(string N)
	{
		PLname = N;
	}
	string getPLname()
	{
		return PLname;
	}
	void AddListinList(ManageType* data)
	{
		PlayList.Add(data);
		length++;
	}
	void Printall();
};

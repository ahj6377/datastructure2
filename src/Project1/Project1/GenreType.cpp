#include"GenreType.h"

void GenreType::PrintAll()
{
	cout << "\t Àå¸£¸í :" << G_name << endl;
	DoublyIter2<MusicType*> Mptriter(G_List);
	while (Mptriter.NotNull())
	{
		Mptriter.GetCurrentNode().data->DisplayNameNIndex();
		Mptriter.Next();
	}
	cout << "\t -------------------------------" << endl;
}

GenreType GenreType::operator=(const GenreType& data)
{
	G_name = data.G_name; 
	G_List = data.G_List;
	return *this;
}
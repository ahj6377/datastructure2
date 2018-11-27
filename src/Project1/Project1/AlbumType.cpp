#include"AlbumType.h"

AlbumType AlbumType::operator=(const AlbumType& D)
{
	ArtistName = D.ArtistName;
	AlbumName = D.AlbumName;
	Ab_List = D.Ab_List;
	return *this;
}
void AlbumType::AddListinList(MusicType* in)
{
	Ab_List.Add(in);
}

void AlbumType::Printall()
{
	cout << "\t앨범명 : " << AlbumName << endl;
	cout << "\t아티스트명 : " << ArtistName << endl;
	DoublyIter2<MusicType*> Mptriter(Ab_List);
	while (Mptriter.NotNull())
	{
		Mptriter.GetCurrentNode().data->DisplayNameNIndex();
		Mptriter.Next();
	}
	cout << "\t ---------------------------------" << endl;
}
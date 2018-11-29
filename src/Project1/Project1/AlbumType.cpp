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
		//Mptriter.GetCurrentNode().data->DisplayNameNIndex();
		Mptriter.GetCurrentNode().data->DisplayRecordOnScreen();
		Mptriter.Next();
	}
	cout << "\t ---------------------------------" << endl;
}

void AlbumType::SearchInListbyGenre()
{

	string str;
	cout << "\t장르로 찾기" << endl;
	cout << "\t검색어 : ";
	cin >> str;
	DoublyIter2<MusicType*> iter(Ab_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data->GetGenre() == str)
		{
			iter.GetCurrentNode().data->DisplayNameNIndex();

		}
		iter.Next();
	}
}

void AlbumType::FindInListbyGenre(string str)
{
	DoublyIter2<MusicType*> iter(Ab_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data->GetGenre() == str)
			iter.GetCurrentNode().data->DisplayNameNIndex();
		iter.Next();
	}

}
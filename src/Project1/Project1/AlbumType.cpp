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
	cout << "\t�ٹ��� : " << AlbumName << endl;
	cout << "\t��Ƽ��Ʈ�� : " << ArtistName << endl;
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
	cout << "\t�帣�� ã��" << endl;
	cout << "\t�˻��� : ";
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
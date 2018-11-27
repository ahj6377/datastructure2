#include"GenreType.h"

void GenreType::PrintAll()
{
	cout << "\t �帣�� :" << G_name << endl;
	DoublyIter2<MusicType*> Mptriter(G_List);
	while (Mptriter.NotNull())
	{
		//Mptriter.GetCurrentNode().data->DisplayNameNIndex();
		Mptriter.GetCurrentNode().data->DisplayRecordOnScreen();
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

void GenreType::SearchInListbyAlbum()
{
	string str;
	cout << "\t�ٹ����� ã��" << endl;
	cout << "\t�˻��� : ";
	cin >> str;
	DoublyIter2<MusicType*> iter(G_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data->GetAlbum()==str)
		{
			iter.GetCurrentNode().data->DisplayNameNIndex();

		}
		iter.Next();
	}
}

void GenreType::SearchInListbyArtist()
{
	string str;
	cout << "\t��Ƽ��Ʈ�� ã��" << endl;
	cout << "\t�˻��� : ";
	cin >> str;
	DoublyIter2<MusicType*> iter(G_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data->GetSinger()==str)
		{
			iter.GetCurrentNode().data->DisplayNameNIndex();

		}
		iter.Next();
	}

}
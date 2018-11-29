
#include"ArtistType.h"

void ArtistType::PrintListinList()
{
	DoublyIter<AlbumType> Abiter(AlbumList);
	cout << "\t ----------------" << endl;
	cout << "\t ��Ƽ��Ʈ�� : " << ArtistName << endl;
	cout << "\t ----------------" << endl;
	while (Abiter.NotNull())
	{
		cout << "\t�ٹ���" << Abiter.GetCurrentNode().data.GetAlbumName() << endl;
		Abiter.GetCurrentNode().data.Printall();
		Abiter.Next();
	}
}

ArtistType::ArtistType(const ArtistType& data)
{
	ArtistName = data.ArtistName;
	AlbumList = data.AlbumList;

}

void ArtistType::SearchInListbyGenre()
{
	string str;
//	cout << "\t�帣�� ã��" << endl;
	cout << "\t�˻��� : ";
	cin >> str;
	DoublyIter<AlbumType> Abiter(AlbumList);
	while (Abiter.NotNull())
	{
		Abiter.GetCurrentNode().data.FindInListbyGenre(str);
		

		Abiter.Next();
	}


}


#include"ArtistType.h"

void ArtistType::PrintListinList()
{
	DoublyIter<AlbumType> Abiter(AlbumList);
	cout << "\t ----------------" << endl;
	cout << "\t 아티스트명 : " << ArtistName << endl;
	cout << "\t ----------------" << endl;
	while (Abiter.NotNull())
	{
		cout << "\t앨범명" << Abiter.GetCurrentNode().data.GetAlbumName() << endl;
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
//	cout << "\t장르로 찾기" << endl;
	cout << "\t검색어 : ";
	cin >> str;
	DoublyIter<AlbumType> Abiter(AlbumList);
	while (Abiter.NotNull())
	{
		Abiter.GetCurrentNode().data.FindInListbyGenre(str);
		

		Abiter.Next();
	}


}

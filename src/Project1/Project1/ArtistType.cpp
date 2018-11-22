
#include"ArtistType.h"

void ArtistType::PrintListinList()
{
	DoublyIter<AlbumType> Abiter(AlbumList);
	cout << "\t ----------------" << endl;
	cout << "\t ��Ƽ��Ʈ�� : " << ArtistName << endl;
	while (Abiter.NotNull())
	{
		cout << "\t�ٹ���" << Abiter.GetCurrentNode().data.GetAlbumName() << endl;
		Abiter.Next();
	}
}

ArtistType::ArtistType(const ArtistType& data)
{
	ArtistName = data.ArtistName;
	AlbumList = data.AlbumList;

}
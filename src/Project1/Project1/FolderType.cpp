#include"FolderType.h"


void FolderType::AddMusic(ManageType* in)
{
	Musics.Add(in);

}

void FolderType::AddFolder()
{
	string str;
	cout << "\t���� �̸��� �Է����ּ��� : ";
	cin >> str;
	FolderType newFolder;
	str = Foldername + "/" + str;
	newFolder.setFname(str);
	newFolder.setMfolder(this);
	Subfolder.Add(newFolder);

}
void FolderType::DisplayAllinFolder()
{
	DoublyIter2<FolderType> Fiter(Subfolder);
	while (Fiter.NotNull())
	{
		cout << "����:" << Fiter.GetCurrentNode().data.getFname() << endl;
		Fiter.Next();
	}
	DoublyIter2<ManageType*> Mgiter(Musics);

	while (Mgiter.NotNull())
	{
		cout << "���� : " << endl;
		Mgiter.GetCurrentNode().data->PrintNameNIndex();
		Mgiter.Next();
	}


}
#include"FolderType.h"


void FolderType::AddMusic(ManageType* in)
{
	Musics.Add(in);

}

void FolderType::AddFolder()
{
	string str;
	cout << "\t폴더 이름을 입력해주세요 : ";
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
		cout << "폴더:" << Fiter.GetCurrentNode().data.getFname() << endl;
		Fiter.Next();
	}
	DoublyIter2<ManageType*> Mgiter(Musics);

	while (Mgiter.NotNull())
	{
		cout << "음악 : " << endl;
		Mgiter.GetCurrentNode().data->PrintNameNIndex();
		Mgiter.Next();
	}


}
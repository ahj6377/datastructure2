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
	newFolder.setFname(str);
	str = FolderLoc + "/" + str;
	newFolder.setFloc(str);
	newFolder.setMfolder(this);
	Subfolder.Add(newFolder);

}
void FolderType::DisplayAllinFolder()
{
	cout << "\t --- 현재 경로 : " << FolderLoc << endl;
	cout << "\t --- 폴더:" << endl;
	DoublyIter2<FolderType> Fiter(Subfolder);
	while (Fiter.NotNull())
	{
		cout << "\t ---  " <<  Fiter.GetCurrentNode().data.getFname() << endl;
		Fiter.Next();
	}
	DoublyIter2<ManageType*> Mgiter(Musics);

	cout << "\t --- 음악  " << endl;
	while (Mgiter.NotNull())
	{
		
		Mgiter.GetCurrentNode().data->PrintNameNIndex();
		Mgiter.Next();
	}


}

void FolderType::DisplayFolders()
{
	cout << "\t --- 폴더:" << endl;
	DoublyIter2<FolderType> Fiter(Subfolder);
	while (Fiter.NotNull())
	{
		cout << "\t" <<Fiter.GetCurrentNode().data.getFname() << endl;
		Fiter.Next();
	}
	DoublyIter2<ManageType*> Mgiter(Musics);
}

FolderType* FolderType::ReturnSubFolder(string str)
{
	cout << "\t --- 현재 경로 : " << FolderLoc << endl;
	DoublyIter2<FolderType> iter(Subfolder);
	while (iter.NotNull())
	{
		if (str == iter.GetCurrentNode().data.getFname())
			return iter.GetCurrentPtr();
		iter.Next();
	}
	cout << "\t 찾지 못했습니다!" << endl;
	return this;
}

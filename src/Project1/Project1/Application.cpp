#include"Application.h"



// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddMusic();
			break;
		case 2:		// display all the records in list on screen.
			Delete();
			break;
		case 3:
			Update();
			break;
		case 4:	
			SearchModule(); 
			break;
		case 5:	
			DisplayModule(); 
			break;
		case 6:	
			DIsplayNewMusic();
			break;
		case 7:	
			PlayListModule(); 
			break;
		case 8:		// load list data from a file.
			Play(); 
			break;
		case 9:
			DisplayRecentlyPlayedMusic(); 
			break;
		case 10:
			FolderModule();
			break;
		case 99:
			ReadDataFromFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;

	cout << "\t   ���� ��� : " << FolderTracker->getFloc() << endl;
	/*
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Replace Music" << endl;
	cout << "\t   4 : Search by Song Name" << endl;
	cout << "\t   5 : Search by Artist(Singer)" << endl;
	cout << "\t   6 : Search by Album" << endl;
	cout << "\t   7 : Search by Genre" << endl;
	cout << "\t   8 : Display all Music" << endl;
	cout << "\t   9 : Display New Music" << endl;
	cout << "\t   10 : Display Music by Genre" << endl;
	cout << "\t   11 : search by Name and Genre" << endl;
	cout << "\t   12 : Display Music by Album" << endl;
	cout << "\t   13 : Display Music by Artist" << endl;
	cout << "\t   20 : ������ �����" << endl;
	cout << "\t   21 : �����Ͽ� �߰��ϱ�" << endl;
	cout << "\t   22 : ������ ����" << endl;
	cout << "\t   23 : �ֱ� ����� ��� ����" << endl;
	cout << "\t   30 : ����ϱ�" << endl;
	cout << "\t   40 : ���� �߰��ϱ�" << endl;
	cout << "\t   41 : ���� ����" << endl;
	cout << "\t   42 : ���� ������" << endl;
	cout << "\t   43 : ���� ������" << endl;
	cout << "\t   98 : Get from file" << endl;
	cout << "\t   99 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;
	*/
	cout << "\t   1 : ���� �߰�" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ���� ����" << endl;
	cout << "\t   4 : �˻� ���" << endl;
	cout << "\t   5 : ���� ���� �з����� ����" << endl;
	cout << "\t   6 : �ֱ� �߰��� ��� ���� " << endl;
	cout << "\t   7 : ������ ���� ���" << endl;
	cout << "\t   8 : ����ϱ�" << endl;
	cout << "\t   9 : �ֱ� ����� ��� ����" << endl;
	cout << "\t   10 : ���� ���� ���" << endl;
	cout << "\t   99 : ���Ͽ��� �о����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMusic()
{
	string genre;	//�帣�� ������ �ӽú���
	string name;	//����� ������ �ӽú���
	MusicType item;

	item.SetInfoFromKB();
	m_List.Add(item);		//MusicList�� ���� �߰�
	RemakeSubList();		//MusicList�� ��ȭ�� �������Ƿ� ���� ����Ʈ���� �ٽ� �������� �Ѵ�.
	SetMusicIndex();		//MusicList�� ��ȭ�� �������Ƿ� Index�� �ٽ� �ο��Ѵ�.
	DoublyIter<MusicType> Miter(m_List);
	ManageType mgitem;
	while (Miter.NotNull())
	{
		if (Miter.GetCurrentNode().data == item)
		{
			MusicType* tempmptr = Miter.GetCurrentPtr();
			mgitem.setPtr(tempmptr);
		}
		Miter.Next();
	}

	
	mg_List.Add(mgitem);
	DoublyIter2<ManageType> mgiter(mg_List);
	
	while (mgiter.NotNull())
	{
		if (mgitem == mgiter.GetCurrentNode().data)	//ManageType�� Ư�� ������ �ּҰ��� �޾ƿ´�.
		{
			ManageType* mgptr;
			mgptr = mgiter.GetCurrentPtr();
			FolderTracker->AddMusic(mgptr);

		}
		mgiter.Next();
	}
	//�ֱ� �߰���Ͽ� �߰��ϱ�
	/*
	Simpletype.SetRecord(num, name);
	if (!AddRecentlyMusicList.IsFull())		//�ֱ� �߰��ȸ���� �������� �ʾ������
		AddRecentlyMusicList.EnQueue(Simpletype);			//ť�� �ϳ� �߰�
	else									//�ֱ� �߰��ȸ���� 30�� �� á�����
	{
		SimplifiedType S_temp;
		AddRecentlyMusicList.DeQueue(S_temp);		//�ϳ��� �����
		AddRecentlyMusicList.EnQueue(Simpletype);	//��� �߰��� ���ڵ带 ����ִ´�
	}
	*/
	// ���� list ���
	DisplayAllMusic();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	DoublyIter<MusicType> iter(m_List);
	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	while (iter.NotNull())
	{
		iter.GetCurrentNode().data.DisplayRecordOnScreen();
		iter.Next();

	}

}



//ã�� ID�� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
void Application::Delete()
{
	DisplayAllMusic();
	cout << "\t���� : ";
	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetNumFromKB();	//����ڿ��Լ� �� ��ȣ�� �Է¹޴´�.
	SearchByIndex(data);
	DoublyIter2<ManageType> Mgiter(mg_List);
	ManageType* mgptr;
	while (Mgiter.NotNull())
	{
		if (Mgiter.GetCurrentNode().data.getIndex() == data.GetNum())
		{
			mgptr = Mgiter.GetCurrentPtr();
			//���⼭���� ���� �߰��� �ڵ�
			MusicType* tempmptr;
			tempmptr = mgptr->getPtr();
			DoublyIter2<ManageType> Mgiter2(RecentlyPlayedList);	
			while (Mgiter2.NotNull())
			{
				MusicType* thismptr = Mgiter2.GetCurrentNode().data.getPtr();
				if (tempmptr == thismptr)
				{
					ManageType* mgtempptr = Mgiter2.GetCurrentPtr();
					mgtempptr->Deleted();		//�ֱ� ����� ��Ͽ����� ����ǥ�ø� ���ش�.
				}
				Mgiter2.Next();
			}
			//�������
			mgptr->Deleted();		//������, �ֱ� �߰���Ͽ��� ����ǥ�ø� ���ش�.
		}
		Mgiter.Next();
	}
	/*DoublyIter<MusicType> Miter(m_List);
	if (data.GetNum() < 1 || data.GetNum() > m_List.GetLength())
		return;
	for (int i = 1; i < data.GetNum(); i++) {
		Miter.Next();
		
	}*/
	//data = Miter.GetCurrentNode().data;
	if (m_List.Delete(data))
	{
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
		RemakeSubList();		//MusicList�� ��ȭ�� �������Ƿ� ���� ����Ʈ���� �ٽ� �������� �Ѵ�.
		
		
	
		if (m_List.GetLength() != 0)		//���̰� 0�̸� �ε����� �ο��Ҽ� ����.
		{
			SetMusicIndex();//MusicList�� ��ȭ�� �������Ƿ� Index�� �ٽ� �ο��Ѵ�.
		}
	}
	else
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.


}


//ã�� ID�� ����ڿ��� �Է¹ް� SortedList�� Update�Լ��� ȣ���Ѵ�.
void Application::Update()
{
	DisplayAllMusic();
	cout << "\t������ ���ϴ� �׸��� ";
	MusicType data;	//Replace�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetNumFromKB();	//����ڿ��Լ� ������ �׸��� �� ��ȣ�� �Է¹޴´�.
	SearchByIndex(data);
	if (!m_List.Get(data))	//����ڰ� �Է��� �׸��� List�� �ֳ� �˻�
	{
		cout << "\t�׸��� ã�� �� �����ϴ�." << endl;		//ã�� �� ������ �޽����� ����Ѵ�.
		return;
	}
	else	//ã�� �� ������
	{
		
		if (m_List.Delete(data))//���� �׸��� �����ϰ�
		{
			data.SetNameFromKB(); //����ڿ��Լ� ����� �Է¹޴´�.
			data.SetSingerFromKB();	//����ڿ��Լ� ������ �Է¹޴´�.
			data.SetAlbumFromKB();	//����ڿ��Լ� �ٹ��� �Է¹޴´�.
			data.SetGenreFromKB();  //����ڿ��Լ� �帣�� �Է¹޴´�.
			data.SetLyricsFromKB(); // ����ڿ��Լ� ���縦 �Է¹޴´�.
			data.SetPkey();	//�����͸� ���������Ƿ� Pkey�� �ٽ� �������ش�.
			m_List.Add(data);
			cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ �������� �� �޽����� ����Ѵ�.
			DoublyIter<MusicType> Miter(m_List);
			while (Miter.NotNull())
			{
				if (Miter.GetCurrentNode().data == data)
				{
					MusicType* mptr;
					mptr = Miter.GetCurrentPtr();
					DoublyIter2<ManageType> Mgiter(mg_List);
					while (Mgiter.NotNull())
					{
						if (Mgiter.GetCurrentNode().data.getPkey() == data.GetPkey())
						{
							ManageType* mgptr;
							mgptr = Mgiter.GetCurrentPtr();
							mgptr->setPtr(mptr);

						}
						Mgiter.Next();
					}

				}
				Miter.Next();
			}


			RemakeSubList();		//MusicList�� ��ȭ�� �������Ƿ� ���� ����Ʈ���� �ٽ� �������� �Ѵ�.
			if (m_List.GetLength() != 0)		//���̰� 0�̸� �ε����� �ο��Ҽ� ����.
			{
				SetMusicIndex();//MusicList�� ��ȭ�� �������Ƿ� Index�� �ٽ� �ο��Ѵ�.
			}
		}
		else
			cout << "\t������ �����߽��ϴ�." << endl;	//������ �������� �� �޽����� ����Ѵ�.
	}

}
//����ڿ��� ã�����ϴ� Name�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByName()
{
	MusicType temp;
	cout << "\tã�� ";
	temp.SetNameFromKB();	//SearchByName�Լ��� �Ѱ��� temp�� Name�� ����ڿ��� �Է¹޴´�.
	SearchByName(temp);	//���������� ã�� ������ �ϴ� SearchByName�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


//����ڰ� ã�����ϴ� Name�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	DoublyIter<MusicType> iter(m_List);
	int count = 0;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data.GetName().find(inData.GetName()) != -1)
		{
			iter.GetCurrentNode().data.DisplayRecordOnScreen();
			count++;
		}
		iter.Next();
	}




	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//����ڿ��� ã�����ϴ� Singer�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordBySinger()
{
	MusicType temp;
	cout << "\tã�� ";
	temp.SetSingerFromKB();	//SearchBySinger�Լ��� �Ѱ��� temp�� Name�� ����ڿ��� �Է¹޴´�.
	SearchBySinger(temp);	//���������� ã�� ������ �ϴ� SearchBySinger�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


//����ڰ� ã�����ϴ� Singer�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchBySinger(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	DoublyIter<MusicType> iter(m_List);
	int count = 0;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data.GetSinger().find(inData.GetSinger()) != -1)
		{
			iter.GetCurrentNode().data.DisplayRecordOnScreen();
			count++;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//����ڿ��� ã�����ϴ� Album�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	cout << "\tã�� ";
	temp.SetAlbumFromKB();	//SearchByAlbum�Լ��� �Ѱ��� temp�� Album�� ����ڿ��� �Է¹޴´�.
	SearchByAlbum(temp);	//���������� ã�� ������ �ϴ� SearchByAlbum�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


//����ڰ� ã�����ϴ� Album�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByAlbum(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "����Ʈ�� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	DoublyIter<MusicType> iter(m_List);
	int count = 0;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data.GetAlbum().find(inData.GetAlbum()) != -1)
		{
			iter.GetCurrentNode().data.DisplayRecordOnScreen();
			count++;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}
//����ڿ��� ã�����ϴ� Genre�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByGenre()
{
	MusicType temp;
	cout << "\tã�� ";
	temp.SetGenreFromKB();	//SearchByGenre�Լ��� �Ѱ��� temp�� Genre�� ����ڿ��� �Է¹޴´�.
	SearchByGenre(temp);	//���������� ã�� ������ �ϴ� SearchByGenre�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


//����ڰ� ã�����ϴ� Genre�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByGenre(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "����Ʈ�� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	DoublyIter<MusicType> iter(m_List);
	int count = 0;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data.GetGenre().find(inData.GetGenre()) != -1)
		{
			iter.GetCurrentNode().data.DisplayRecordOnScreen();
			count++;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{

	MusicType data;	// �б�� �ӽ� ����
	ifstream ReadData;
	ReadData.open("text.txt");
	string OneLine;
	while (getline(ReadData, OneLine))
	{
		istringstream L(OneLine);
		string name, singer, Album, Genre, Lyrics;
		L >> name;
		L >> singer;
		L >> Album;
		L >> Genre;
		L >> Lyrics;
		data.SetRecord(name, singer, Album, Genre, Lyrics);
		m_List.Add(data);
	}
	/*
	char fileName[FILENameSIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> fileName;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(fileName))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close
	*/
	SetMusicIndex();
	// ���� list ���
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{

	m_OutFile.close();	// file close

	return 1;
}

//�ֱ� �߰��� 30�� ���
void Application::DIsplayNewMusic()
{

	if (m_List.IsEmpty() == true)
	{
		cout << "����Ʈ�� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
	int cnt = 0;
	DoublyIter2<ManageType> Mgiter(mg_List);
	Mgiter.Last();

	while (Mgiter.NotNull() && cnt < 30)
	{
		bool Printed = true;
		NodeType2<ManageType>  temp1 = Mgiter.GetCurrentNode();
		ManageType temp2 = temp1.data;
		Printed = temp2.PrintNameNIndex();
		Mgiter.Prev();
		if(Printed == true)
			cnt++;
	}





}

bool Application::Search(int key, MusicType& inData)
{
	inData.SetNum(key);
	if (m_List.Get(inData))
		return true;

	else
		return false;
}
//Display Music by genre through genre list
void Application::DisplayMusicbyGenre()
{
	if (m_List.GetLength() == 0)
		return;
	if (RemakeGenreList == true)
	{
		GenreList.MakeEmpty();	//������ ����Ʈ�� ����
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			GenreType thisGenre;
			thisGenre.SetGenre(Miter.GetCurrentNode().data.GetGenre());
			GenreList.Add(thisGenre);
			Miter.Next();
		}		//�� �ݺ����� ������ �帣����Ʈ�� �帣�� ���ĵǾ� ��
		DoublyIter<MusicType> Miter2(m_List);
		while (Miter2.NotNull())
		{
			DoublyIter<GenreType> Giter(GenreList);
			while (Giter.NotNull())
			{
				if (Giter.GetCurrentNode().data.GetGenre() == Miter2.GetCurrentNode().data.GetGenre())
				{
					MusicType* mptr;
					mptr = Miter2.GetCurrentPtr();
					GenreType* gptr;
					gptr = Giter.GetCurrentPtr();
					gptr->addListinList(mptr);
				}
				Giter.Next();
			}
			Miter2.Next();
		}//������� �з��� genretype�� ����Ʈ�θ���Ʈ�� Musictype*�� �߰��ȴ�.

	}
	
	RemakeGenreList = false;			//����Ʈ�� �ٽ� ��������Ƿ� ������ ������ �ٽ� �����ʿ䰡 ����

	//�Ʒ��� ����ϴ� �ڵ�
	DoublyIter<GenreType> Giter(GenreList);

	while (Giter.NotNull())
	{
		Giter.GetCurrentNode().data.PrintAll();
		Giter.Next();
	}
	string str;
	cout << "������� �帣�� �Է����ּ���" << endl;
	cin >> str;
	Giter.First();

	GenreType* gptr;
	while (Giter.NotNull())
	{
		if (Giter.GetCurrentNode().data.GetGenre() == str)
		{
			gptr = Giter.GetCurrentPtr();
			int a = 1;
			while (a)
			{
				cout << "\t 1. �帣����Ʈ ������ �ٹ����� �˻�" << endl;
				cout << "\t 2. �帣����Ʈ ������ ��Ƽ��Ʈ�� �˻�" << endl;
				cout << "\t 0. ������" << endl;
				
				cin >> a;
				switch (a)
				{
				case 1:
					gptr->SearchInListbyAlbum();
					break;
				case 2:
					gptr->SearchInListbyArtist();
					break;
				case 0:
					
					break;
				}

			}
		}
		Giter.Next();
	}
}



//name �� genre ������ �޾� Search�Լ��� �ѱ��.
void Application::RetreiveRecordByNameNGenre()
{
	MusicType temp;
	cout << "\tã�� ";
	temp.SetNameFromKB();
	temp.SetGenreFromKB();	//SearchByGenre�Լ��� �Ѱ��� temp�� Genre�� ����ڿ��� �Է¹޴´�.
	SearchByNameNGenre(temp);	//���������� ã�� ������ �ϴ� SearchByGenre�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.


}

void Application::SearchByNameNGenre(MusicType& inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "����Ʈ�� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	DoublyIter<MusicType> iter(m_List);
	int count = 0;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode().data.GetName().find(inData.GetName()) != -1 && iter.GetCurrentNode().data.GetGenre().find(inData.GetGenre()) != -1)
		{
			iter.GetCurrentNode().data.DisplayRecordOnScreen();
			count++;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.


}

void Application::DisplayMusicByAlbum()
{

	if (m_List.GetLength() == 0)
		return;
	//���� �����ϱ�
	if (RemakeAlbumList == true)		//�ٹ� ����Ʈ�� �ٽø����� �ϴ°�
	{
		AlbumList.MakeEmpty();
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			AlbumType thisAlbum(Miter.GetCurrentNode().data.GetAlbum(), Miter.GetCurrentNode().data.GetSinger());
			AlbumList.Add(thisAlbum);
			Miter.Next();
		}	//�̱��� �ٹ��� ���ĵǾ� ����.
		DoublyIter<MusicType> Miter2(m_List);
		while (Miter2.NotNull())
		{
			DoublyIter<AlbumType> Abiter(AlbumList);
			while (Abiter.NotNull())
			{
				string Martist, Malbum,Aartist,Aalbum;
				Martist = Miter2.GetCurrentNode().data.GetSinger();
				Malbum = Miter2.GetCurrentNode().data.GetAlbum();
				Aartist = Abiter.GetCurrentNode().data.GetArtistName();
				Aalbum = Abiter.GetCurrentNode().data.GetAlbumName();
				if(Martist == Aartist && Malbum == Aalbum)
				{
					MusicType* mptr = Miter2.GetCurrentPtr();
					AlbumType* abptr = Abiter.GetCurrentPtr();
					abptr->AddListinList(mptr);

				}
				Abiter.Next();
			}//�� �ٹ�Ÿ�Կ� Musictype�� �����Ͱ� �߰��ȴ�.
			Miter2.Next();
		}

	}	//�ٹ��� ���ĵȴ�
	RemakeAlbumList = false;		//����Ʈ�� ���������Ƿ� �ٽø��� �ʿ䰡 ����.
	//���⼭���ʹ� ����ڵ�


	DoublyIter<AlbumType> Abiter(AlbumList);
	while (Abiter.NotNull())
	{
		AlbumType thisAlbum;
		thisAlbum = Abiter.GetCurrentNode().data;
		thisAlbum.Printall();
		Abiter.Next();
	}
	cout << "������� �ٹ��� : " << endl;
	string str;
	cin >> str;
	Abiter.First();
	while (Abiter.NotNull())
	{	
		AlbumType* aptr;
		if (str == Abiter.GetCurrentNode().data.GetAlbumName())
		{
			int a = 1;
			while (a)
			{
				cout << "\t 1: �帣�� ã��" << endl;
				cout << "\t 0: ������" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
					Abiter.GetCurrentNode().data.SearchInListbyGenre();
					break;
				case 0:
					break;
				}
			}
		}
		Abiter.Next();
		
	}



}

void Application::DisplayMusicByArtist()
{
	if (m_List.GetLength() == 0)
		return;
	if (RemakeArtistList == true)		//��Ƽ��Ʈ ����Ʈ�� �ٽ� ������ �ϴ°�
	{
		ArtistList.MakeEmpty();
		AlbumList.MakeEmpty();		//��Ƽ��Ʈ ����Ʈ�� �ٹ�����Ʈ�� ����
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			ArtistType thisArtist;
			thisArtist.SetArtistName(Miter.GetCurrentNode().data.GetSinger());
			ArtistList.Add(thisArtist);
			Miter.Next();
		}//��Ƽ��Ʈ����Ʈ�� ��Ƽ��Ʈ�� ���ĵǾ� ���Եȴ�.	


		DoublyIter<MusicType> Miter2(m_List);
		while (Miter2.NotNull())
		{
			AlbumType thisAlbum(Miter2.GetCurrentNode().data.GetAlbum(), Miter2.GetCurrentNode().data.GetSinger());
			AlbumList.Add(thisAlbum);
			Miter2.Next();
		}
		//AlbumList�� �ٹ��߰���
		Miter2.First();
		while (Miter2.NotNull())
		{
			DoublyIter<AlbumType> Abiter(AlbumList);
			while (Abiter.NotNull())
			{
				string Martist, Malbum, Aartist, Aalbum;
				Martist = Miter2.GetCurrentNode().data.GetSinger();
				Malbum = Miter2.GetCurrentNode().data.GetAlbum();
				Aartist = Abiter.GetCurrentNode().data.GetArtistName();
				Aalbum = Abiter.GetCurrentNode().data.GetAlbumName();
				if (Martist == Aartist && Malbum == Aalbum)
				{
					MusicType* mptr = Miter2.GetCurrentPtr();
					AlbumType* abptr = Abiter.GetCurrentPtr();
					abptr->AddListinList(mptr);

				}
				Abiter.Next();
			}//�� �ٹ�Ÿ�Կ� Musictype�� �����Ͱ� �߰��ȴ�.
			Miter2.Next();
		}
		DoublyIter<AlbumType> Abiter(AlbumList);			//�ٹ��� �ش� �ٹ��� ���� ��Ƽ��Ʈ�� ���� ��Ƽ��Ʈ Ÿ���� ����Ʈ�� �߰��Ѵ�.
		while (Abiter.NotNull())
		{
			DoublyIter<ArtistType> Atiter(ArtistList);
			while (Atiter.NotNull())
			{
				if (Atiter.GetCurrentNode().data.GetArtistName() == Abiter.GetCurrentNode().data.GetArtistName())
				{
					ArtistType* temp;
					temp = Atiter.GetCurrentPtr();
					AlbumType thisAlbum = Abiter.GetCurrentNode().data;
					temp->AddListinList(thisAlbum);
				}
				Atiter.Next();
			}
			Abiter.Next();
		}


	}
	RemakeArtistList = false;	//����Ʈ�� ���������Ƿ� �ٽø��� �ʿ䰡 ����.
	//���⼭���� ����ڵ�
	DoublyIter<ArtistType> Atiter2(ArtistList);
	while (Atiter2.NotNull())
	{
		ArtistType *Atptr;
		Atptr = Atiter2.GetCurrentPtr();
		Atptr->PrintListinList();
		Atiter2.Next();
	}
	Atiter2.First();
	string str;
	cout << "\t���� ���� ��Ƽ��Ʈ : ";
	cin >> str;
	while (Atiter2.NotNull())
	{
		if (Atiter2.GetCurrentNode().data.GetArtistName() == str)
		{
			int a = 1;
			while (a)
			{
				cout << "\t 1: �帣�� ã��" << endl;
				cout << "\t 0: ������" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
					Atiter2.GetCurrentNode().data.SearchInListbyGenre();
					break;
				case 0:
				
					
					break;
				}
			}
		}
		Atiter2.Next();
	}

}
void Application::SetMusicIndex()
{
	int Index = 1;
	DoublyIter<MusicType> Miter(m_List);

	while (Miter.NotNull())
	{
		MusicType* Mptr;
		Mptr = Miter.GetCurrentPtr();
		Mptr->SetNum(Index);
		Index++;
		Miter.Next();
	}
	//List�� ������ �ε����� �ο��Ѵ�. �ε����� �ִ밪�� MusicList�� �����̴�.



}
void Application::SearchByIndex(MusicType &indata)
{
	DoublyIter<MusicType> Miter(m_List);
	int Index = indata.GetNum();
	while (Miter.NotNull())
	{
		if (Index == Miter.GetCurrentNode().data.GetNum())
		{
			indata = Miter.GetCurrentNode().data;
			//Miter.GetCurrentNode().data.DisplayRecordOnScreen();
		}
		Miter.Next();
	}


}

void Application::makePlayList()
{
	string N;
	PLType PL;
	cout << "������ �̸� :";
	cin >> N;
	PL.setPLname(N);
	PlayLists.Add(PL);
}


void Application::AddMusicInPL()
{
	DoublyIter2<PLType> PLiter(PlayLists);
	while (PLiter.NotNull())
	{
		cout << "�����ϸ� : " << PLiter.GetCurrentNode().data.getPLname();
		cout << endl;
		PLiter.Next();
	}
	string N;
	cout << "�߰��ϰ��� �ϴ� ������ ���� : " << endl;
	cin >> N;
	DoublyIter2<PLType> PLiter2(PlayLists);
	PLType* ptr;
	while (PLiter2.NotNull())
	{
		if (PLiter2.GetCurrentNode().data.getPLname() == N)
		{
			ptr = PLiter2.GetCurrentPtr();
			DisplayAllMusic();
			int num = 1;
			while (1)
			{
				cout << "�߰��ϰ��� �ϴ� ���� Index�� �Է����ּ��� 0�� �Է��ϸ� �׸� �߰��մϴ�" << endl;
				cin >> num;
				if (num > m_List.GetLength() || num == 0)
					break;
				DoublyIter2<ManageType> Mgiter(mg_List);
				ManageType* mgPtr;
				while (Mgiter.NotNull())
				{
					if (Mgiter.GetCurrentNode().data.getIndex() == num)
					{
						mgPtr = Mgiter.GetCurrentPtr();
						ptr->AddListinList(mgPtr);
					}
					Mgiter.Next();
				}

			}
		}
		PLiter2.Next();
	}

}
void Application::PrintPL()
{
	DoublyIter2<PLType> PLiter(PlayLists);
	while (PLiter.NotNull())
	{
		cout << "�����ϸ� : " << PLiter.GetCurrentNode().data.getPLname();
		cout << endl;
		PLiter.Next();
	}
	string N;
	cout << "������ ���� : " << endl;
	cin >> N;
	DoublyIter2<PLType> PLiter2(PlayLists);
	PLType* ptr;
	while (PLiter2.NotNull())
	{
		if (PLiter2.GetCurrentNode().data.getPLname() == N)
		{
			ptr = PLiter2.GetCurrentPtr();
			ptr->Printall();
		
			while (1)
			{
				int temp;
				cout << "����� ���� �������ּ��� 0�� �Է��ϸ� �����Ͽ��� �����ϴ�" << endl;
				cin >> temp;
				if (temp == 0)
					break;
				Play(temp);
			}
			
		}
		PLiter2.Next();
	}



}

void Application::Play()
{
	if (RemakeListForPlay == true)		//�� ����Ʈ�� ������ ������ ��� ListForPlay�� �ٽ� ������ش�
	{
		delete[] ListforPlay;
		int length = m_List.GetLength();
		ListforPlay = new MusicType*[length];
		DoublyIter<MusicType> Miter(m_List);
		for (int i = 0; i < length; i++)
		{
			ListforPlay[i] = Miter.GetCurrentPtr();
			Miter.Next();
		}
		RemakeListForPlay = false;
	}
	cout << "\t����� ���� Index�� �Է����ּ���. " << endl;
	int cmdIndex;
	cin >> cmdIndex;
	if (cmdIndex < 0)
		return;
	if (cmdIndex > m_List.GetLength())
	{
		cout << "\t�߸��� �Է��Դϴ�" << endl;
		return;
	}
	ListforPlay[cmdIndex - 1]->cntPlayed();
	ListforPlay[cmdIndex - 1]->DisplayNameOnScreen();
	ListforPlay[cmdIndex - 1]->DisplaySingerOnScreen();
	cout << "\t��� Ƚ�� : " << ListforPlay[cmdIndex - 1]->DisplayPlayed() << endl;
	AddRecentlyPlayedList(ListforPlay[cmdIndex-1]);
}

void Application::Play(int Index)
{
	if (RemakeListForPlay == true)		//�� ����Ʈ�� ������ ������ ��� ListForPlay�� �ٽ� ������ش�
	{
		delete[] ListforPlay;
		int length = m_List.GetLength();
		ListforPlay = new MusicType*[length];
		DoublyIter<MusicType> Miter(m_List);
		for (int i = 0; i < length; i++)
		{
			ListforPlay[i] = Miter.GetCurrentPtr();
			Miter.Next();
		}
		RemakeListForPlay = false;
	}
	int cmdIndex = Index;

		ListforPlay[cmdIndex - 1]->cntPlayed();
		ListforPlay[cmdIndex - 1]->DisplayNameOnScreen();
		ListforPlay[cmdIndex - 1]->DisplaySingerOnScreen();
		cout << "\t��� Ƚ�� : " << ListforPlay[cmdIndex - 1]->DisplayPlayed() << endl;
		AddRecentlyPlayedList(ListforPlay[Index-1]);
	
}

void Application::AddRecentlyPlayedList(MusicType* mptr)
{
	ManageType mg;
	mg.setPtr(mptr);
	
	RecentlyPlayedList.Delete(mg);
	RecentlyPlayedList.Add(mg);

}
void Application::DisplayRecentlyPlayedMusic()
{
	int i = 0;
	DoublyIter2<ManageType> mgiter(RecentlyPlayedList);
	mgiter.Last();
	bool Printed = true;
	while (mgiter.NotNull() && i < 30)
	{
		Printed = mgiter.GetCurrentNode().data.PrintNameNIndex();
		if (Printed == true)
			i++;
		mgiter.Prev();

	}


}

void Application::AddFolder()
{
	FolderTracker->AddFolder();
}

void Application::GotoMotherFolder()
{
	if (FolderTracker->getMfolder() != NULL)
	{
		FolderTracker = FolderTracker->getMfolder();
		cout << "���� �̵� ����!" << endl;
	}
	else
		cout << "���� ������ �����ϴ�!" << endl;
}

void Application::GotoSubFolder()
{
	FolderTracker->DisplayFolders();
	string str;
	cout << "\t�̵��ϰ� ���� ������ �Է����ּ��� : ";
	cin >> str;
	FolderTracker = FolderTracker->ReturnSubFolder(str);
	
	
}
void Application::DisplayFolder()
{
	FolderTracker->DisplayAllinFolder();
}

void Application::SearchModule()
{
	int cmd;
	while (1)
	{

		cout << "\t   1: ������� ã��" << endl;
		cout << "\t   2: �帣�� ã��" << endl;
		cout << "\t   3: �ٹ����� ã��" << endl;
		cout << "\t   4: ��Ƽ��Ʈ�� ã��" << endl;
		cout << "\t   0: ������" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			RetreiveRecordByName();
			break;
		case 2:
			RetreiveRecordByGenre();
			break;
		case 3:
			RetreiveRecordByAlbum();
			break;
		case 4:
			RetreiveRecordBySinger();
			break;
		case 0:
			return;
		}
	}



}

void Application::DisplayModule()
{
	int cmd;
	while (1)
	{
		cout << "\t   1: �帣���� ����" << endl;
		cout << "\t   2: �ٹ����� ����" << endl;
		cout << "\t   3: ��Ƽ��Ʈ���� ����" << endl;

		cout << "\t   0: ������" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			DisplayMusicbyGenre();
			break;
		case 2:
			DisplayMusicByAlbum();
			break;
		case 3:
			DisplayMusicByArtist();
			break;
		case 0:
			return;
		}
	}


}

void Application::FolderModule()
{
	int cmd;

	while (1)
	{
		cout << "\t   ���� ��� : " << FolderTracker->getFloc() << endl;
		cout << "\t   1 : ���� �߰��ϱ�" << endl;
		cout << "\t   2 : ���� ����" << endl;
		cout << "\t   3 : ���� ������" << endl;
		cout << "\t   4 : ���� ������" << endl;
		cout << "\t   0 : ������" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			AddFolder();
			break;
		case 2:
			DisplayFolder();
			break;
		case 3:
			GotoMotherFolder();
			break;
		case 4:
			GotoSubFolder();
			break;
		case 0:
			return;

		}

			

	}

}

void Application::PlayListModule()
{
	int cmd;
	while (1)
	{
		cout << "\t   1 : ������ �����" << endl;
		cout << "\t   2 : �����Ͽ� �߰��ϱ�" << endl;
		cout << "\t   3 : ������ ����" << endl;
		cout << "\t   0 : ������" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			makePlayList();
			break;
		case 2:
			AddMusicInPL();
			break;
		case 3:
			PrintPL();
			break;
		case 0:
			return;
		}
	}


}
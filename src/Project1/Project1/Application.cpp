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

	cout << "\t   현재 경로 : " << FolderTracker->getFloc() << endl;
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
	cout << "\t   20 : 재생목록 만들기" << endl;
	cout << "\t   21 : 재생목록에 추가하기" << endl;
	cout << "\t   22 : 재생목록 보기" << endl;
	cout << "\t   23 : 최근 재생한 목록 보기" << endl;
	cout << "\t   30 : 재생하기" << endl;
	cout << "\t   40 : 폴더 추가하기" << endl;
	cout << "\t   41 : 폴더 보기" << endl;
	cout << "\t   42 : 상위 폴더로" << endl;
	cout << "\t   43 : 하위 폴더로" << endl;
	cout << "\t   98 : Get from file" << endl;
	cout << "\t   99 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;
	*/
	cout << "\t   1 : 음악 추가" << endl;
	cout << "\t   2 : 음악 삭제" << endl;
	cout << "\t   3 : 음악 정보 변경" << endl;
	cout << "\t   4 : 검색 기능" << endl;
	cout << "\t   5 : 음악 정보 분류별로 보기" << endl;
	cout << "\t   6 : 최근 추가된 목록 보기 " << endl;
	cout << "\t   7 : 재생목록 관련 기능" << endl;
	cout << "\t   8 : 재생하기" << endl;
	cout << "\t   9 : 최근 재생된 목록 보기" << endl;
	cout << "\t   10 : 폴더 관련 기능" << endl;
	cout << "\t   99 : 파일에서 읽어오기" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMusic()
{
	string genre;	//장르를 저장할 임시변수
	string name;	//곡명을 저장할 임시변수
	MusicType item;

	item.SetInfoFromKB();
	m_List.Add(item);		//MusicList에 원소 추가
	RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
	SetMusicIndex();		//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
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
		if (mgitem == mgiter.GetCurrentNode().data)	//ManageType의 특정 원소의 주소값을 받아온다.
		{
			ManageType* mgptr;
			mgptr = mgiter.GetCurrentPtr();
			FolderTracker->AddMusic(mgptr);

		}
		mgiter.Next();
	}
	//최근 추가목록에 추가하기
	/*
	Simpletype.SetRecord(num, name);
	if (!AddRecentlyMusicList.IsFull())		//최근 추가된목록이 가득차지 않았을경우
		AddRecentlyMusicList.EnQueue(Simpletype);			//큐에 하나 추가
	else									//최근 추가된목록이 30개 꽉 찼을경우
	{
		SimplifiedType S_temp;
		AddRecentlyMusicList.DeQueue(S_temp);		//하나를 지우고
		AddRecentlyMusicList.EnQueue(Simpletype);	//방금 추가된 레코드를 집어넣는다
	}
	*/
	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	DoublyIter<MusicType> iter(m_List);
	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	while (iter.NotNull())
	{
		iter.GetCurrentNode().data.DisplayRecordOnScreen();
		iter.Next();

	}

}



//찾을 ID를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::Delete()
{
	DisplayAllMusic();
	cout << "\t지울 : ";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumFromKB();	//사용자에게서 곡 번호를 입력받는다.
	SearchByIndex(data);
	DoublyIter2<ManageType> Mgiter(mg_List);
	ManageType* mgptr;
	while (Mgiter.NotNull())
	{
		if (Mgiter.GetCurrentNode().data.getIndex() == data.GetNum())
		{
			mgptr = Mgiter.GetCurrentPtr();
			//여기서부터 새로 추가된 코드
			MusicType* tempmptr;
			tempmptr = mgptr->getPtr();
			DoublyIter2<ManageType> Mgiter2(RecentlyPlayedList);	
			while (Mgiter2.NotNull())
			{
				MusicType* thismptr = Mgiter2.GetCurrentNode().data.getPtr();
				if (tempmptr == thismptr)
				{
					ManageType* mgtempptr = Mgiter2.GetCurrentPtr();
					mgtempptr->Deleted();		//최근 재생된 목록에서도 지움표시를 해준다.
				}
				Mgiter2.Next();
			}
			//여기까지
			mgptr->Deleted();		//재생목록, 최근 추가목록에서 지움표시를 해준다.
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
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
		RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
		
		
	
		if (m_List.GetLength() != 0)		//길이가 0이면 인덱스를 부여할수 없다.
		{
			SetMusicIndex();//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
		}
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.


}


//찾을 ID를 사용자에게 입력받고 SortedList의 Update함수를 호출한다.
void Application::Update()
{
	DisplayAllMusic();
	cout << "\t변경을 원하는 항목의 ";
	MusicType data;	//Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumFromKB();	//사용자에게서 수정할 항목의 곡 번호를 입력받는다.
	SearchByIndex(data);
	if (!m_List.Get(data))	//사용자가 입력한 항목이 List에 있나 검색
	{
		cout << "\t항목을 찾을 수 없습니다." << endl;		//찾을 수 없을때 메시지를 출력한다.
		return;
	}
	else	//찾을 수 있을때
	{
		
		if (m_List.Delete(data))//기존 항목을 삭제하고
		{
			data.SetNameFromKB(); //사용자에게서 곡명을 입력받는다.
			data.SetSingerFromKB();	//사용자에게서 가수를 입력받는다.
			data.SetAlbumFromKB();	//사용자에게서 앨범을 입력받는다.
			data.SetGenreFromKB();  //사용자에게서 장르를 입력받는다.
			data.SetLyricsFromKB(); // 사용자에게서 가사를 입력받는다.
			data.SetPkey();	//데이터를 변경했으므로 Pkey를 다시 지정해준다.
			m_List.Add(data);
			cout << "\t수정을 완료했습니다." << endl;	//수정을 성공했을 때 메시지를 출력한다.
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


			RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
			if (m_List.GetLength() != 0)		//길이가 0이면 인덱스를 부여할수 없다.
			{
				SetMusicIndex();//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
			}
		}
		else
			cout << "\t수정을 실패했습니다." << endl;	//수정에 실패했을 때 메시지를 출력한다.
	}

}
//사용자에게 찾고자하는 Name을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByName()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetNameFromKB();	//SearchByName함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchByName(temp);	//실질적으로 찾는 동작을 하는 SearchByName함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Name을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
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
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//사용자에게 찾고자하는 Singer을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordBySinger()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetSingerFromKB();	//SearchBySinger함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchBySinger(temp);	//실질적으로 찾는 동작을 하는 SearchBySinger함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Singer을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchBySinger(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
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
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//사용자에게 찾고자하는 Album을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetAlbumFromKB();	//SearchByAlbum함수에 넘겨줄 temp의 Album을 사용자에게 입력받는다.
	SearchByAlbum(temp);	//실질적으로 찾는 동작을 하는 SearchByAlbum함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Album을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByAlbum(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
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
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}
//사용자에게 찾고자하는 Genre을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByGenre()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetGenreFromKB();	//SearchByGenre함수에 넘겨줄 temp의 Genre을 사용자에게 입력받는다.
	SearchByGenre(temp);	//실질적으로 찾는 동작을 하는 SearchByGenre함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Genre을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByGenre(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
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
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{

	MusicType data;	// 읽기용 임시 변수
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

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(fileName))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close
	*/
	SetMusicIndex();
	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{

	m_OutFile.close();	// file close

	return 1;
}

//최근 추가된 30곡 출력
void Application::DIsplayNewMusic()
{

	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
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
		GenreList.MakeEmpty();	//기존의 리스트를 비운다
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			GenreType thisGenre;
			thisGenre.SetGenre(Miter.GetCurrentNode().data.GetGenre());
			GenreList.Add(thisGenre);
			Miter.Next();
		}		//이 반복문이 끝나면 장르리스트에 장르가 정렬되어 들어감
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
		}//여기까지 분류된 genretype의 리스트인리스트에 Musictype*이 추가된다.

	}
	
	RemakeGenreList = false;			//리스트를 다시 만들었으므로 변경이 없으면 다시 만들필요가 없다

	//아래는 출력하는 코드
	DoublyIter<GenreType> Giter(GenreList);

	while (Giter.NotNull())
	{
		Giter.GetCurrentNode().data.PrintAll();
		Giter.Next();
	}
	string str;
	cout << "보고싶은 장르를 입력해주세요" << endl;
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
				cout << "\t 1. 장르리스트 내에서 앨범으로 검색" << endl;
				cout << "\t 2. 장르리스트 내에서 아티스트로 검색" << endl;
				cout << "\t 0. 나가기" << endl;
				
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



//name 과 genre 정보를 받아 Search함수에 넘긴다.
void Application::RetreiveRecordByNameNGenre()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetNameFromKB();
	temp.SetGenreFromKB();	//SearchByGenre함수에 넘겨줄 temp의 Genre을 사용자에게 입력받는다.
	SearchByNameNGenre(temp);	//실질적으로 찾는 동작을 하는 SearchByGenre함수를 호출하고 temp값을 넘겨준다.


}

void Application::SearchByNameNGenre(MusicType& inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
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
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.


}

void Application::DisplayMusicByAlbum()
{

	if (m_List.GetLength() == 0)
		return;
	//쉽게 구현하기
	if (RemakeAlbumList == true)		//앨범 리스트를 다시만들어야 하는가
	{
		AlbumList.MakeEmpty();
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			AlbumType thisAlbum(Miter.GetCurrentNode().data.GetAlbum(), Miter.GetCurrentNode().data.GetSinger());
			AlbumList.Add(thisAlbum);
			Miter.Next();
		}	//이까지 앨범만 정렬되어 들어간다.
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
			}//각 앨범타입에 Musictype의 포인터가 추가된다.
			Miter2.Next();
		}

	}	//앨범이 정렬된다
	RemakeAlbumList = false;		//리스트를 갱신했으므로 다시만들 필요가 없다.
	//여기서부터는 출력코드


	DoublyIter<AlbumType> Abiter(AlbumList);
	while (Abiter.NotNull())
	{
		AlbumType thisAlbum;
		thisAlbum = Abiter.GetCurrentNode().data;
		thisAlbum.Printall();
		Abiter.Next();
	}
	cout << "보고싶은 앨범명 : " << endl;
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
				cout << "\t 1: 장르로 찾기" << endl;
				cout << "\t 0: 나가기" << endl;
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
	if (RemakeArtistList == true)		//아티스트 리스트를 다시 만들어야 하는가
	{
		ArtistList.MakeEmpty();
		AlbumList.MakeEmpty();		//아티스트 리스트와 앨범리스트를 비운다
		DoublyIter<MusicType> Miter(m_List);
		while (Miter.NotNull())
		{
			ArtistType thisArtist;
			thisArtist.SetArtistName(Miter.GetCurrentNode().data.GetSinger());
			ArtistList.Add(thisArtist);
			Miter.Next();
		}//아티스트리스트에 아티스트가 정렬되어 삽입된다.	


		DoublyIter<MusicType> Miter2(m_List);
		while (Miter2.NotNull())
		{
			AlbumType thisAlbum(Miter2.GetCurrentNode().data.GetAlbum(), Miter2.GetCurrentNode().data.GetSinger());
			AlbumList.Add(thisAlbum);
			Miter2.Next();
		}
		//AlbumList에 앨범추가됨
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
			}//각 앨범타입에 Musictype의 포인터가 추가된다.
			Miter2.Next();
		}
		DoublyIter<AlbumType> Abiter(AlbumList);			//앨범을 해당 앨범과 같은 아티스트를 가진 아티스트 타입의 리스트에 추가한다.
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
	RemakeArtistList = false;	//리스트를 갱신했으므로 다시만들 필요가 없다.
	//여기서부턴 출력코드
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
	cout << "\t보고 싶은 아티스트 : ";
	cin >> str;
	while (Atiter2.NotNull())
	{
		if (Atiter2.GetCurrentNode().data.GetArtistName() == str)
		{
			int a = 1;
			while (a)
			{
				cout << "\t 1: 장르로 찾기" << endl;
				cout << "\t 0: 나가기" << endl;
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
	//List의 끝까지 인덱스를 부여한다. 인덱스의 최대값은 MusicList의 길이이다.



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
	cout << "재생목록 이름 :";
	cin >> N;
	PL.setPLname(N);
	PlayLists.Add(PL);
}


void Application::AddMusicInPL()
{
	DoublyIter2<PLType> PLiter(PlayLists);
	while (PLiter.NotNull())
	{
		cout << "재생목록명 : " << PLiter.GetCurrentNode().data.getPLname();
		cout << endl;
		PLiter.Next();
	}
	string N;
	cout << "추가하고자 하는 재생목록 선택 : " << endl;
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
				cout << "추가하고자 하는 곡의 Index를 입력해주세요 0을 입력하면 그만 추가합니다" << endl;
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
		cout << "재생목록명 : " << PLiter.GetCurrentNode().data.getPLname();
		cout << endl;
		PLiter.Next();
	}
	string N;
	cout << "재생목록 선택 : " << endl;
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
				cout << "재생할 곡을 선택해주세요 0을 입력하면 재생목록에서 나갑니다" << endl;
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
	if (RemakeListForPlay == true)		//곡 리스트에 변경이 생겼을 경우 ListForPlay를 다시 만들어준다
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
	cout << "\t재생할 곡의 Index를 입력해주세요. " << endl;
	int cmdIndex;
	cin >> cmdIndex;
	if (cmdIndex < 0)
		return;
	if (cmdIndex > m_List.GetLength())
	{
		cout << "\t잘못된 입력입니다" << endl;
		return;
	}
	ListforPlay[cmdIndex - 1]->cntPlayed();
	ListforPlay[cmdIndex - 1]->DisplayNameOnScreen();
	ListforPlay[cmdIndex - 1]->DisplaySingerOnScreen();
	cout << "\t재생 횟수 : " << ListforPlay[cmdIndex - 1]->DisplayPlayed() << endl;
	AddRecentlyPlayedList(ListforPlay[cmdIndex-1]);
}

void Application::Play(int Index)
{
	if (RemakeListForPlay == true)		//곡 리스트에 변경이 생겼을 경우 ListForPlay를 다시 만들어준다
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
		cout << "\t재생 횟수 : " << ListforPlay[cmdIndex - 1]->DisplayPlayed() << endl;
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
		cout << "폴더 이동 성공!" << endl;
	}
	else
		cout << "상위 폴더가 없습니다!" << endl;
}

void Application::GotoSubFolder()
{
	FolderTracker->DisplayFolders();
	string str;
	cout << "\t이동하고 싶은 폴더를 입력해주세요 : ";
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

		cout << "\t   1: 곡명으로 찾기" << endl;
		cout << "\t   2: 장르로 찾기" << endl;
		cout << "\t   3: 앨범으로 찾기" << endl;
		cout << "\t   4: 아티스트로 찾기" << endl;
		cout << "\t   0: 나가기" << endl;
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
		cout << "\t   1: 장르별로 보기" << endl;
		cout << "\t   2: 앨범별로 보기" << endl;
		cout << "\t   3: 아티스트별로 보기" << endl;

		cout << "\t   0: 나가기" << endl;
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
		cout << "\t   현재 경로 : " << FolderTracker->getFloc() << endl;
		cout << "\t   1 : 폴더 추가하기" << endl;
		cout << "\t   2 : 폴더 보기" << endl;
		cout << "\t   3 : 상위 폴더로" << endl;
		cout << "\t   4 : 하위 폴더로" << endl;
		cout << "\t   0 : 나가기" << endl;
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
		cout << "\t   1 : 재생목록 만들기" << endl;
		cout << "\t   2 : 재생목록에 추가하기" << endl;
		cout << "\t   3 : 재생목록 보기" << endl;
		cout << "\t   0 : 나가기" << endl;
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
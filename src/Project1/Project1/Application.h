﻿
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<cstdlib>
#include<ctime>
using namespace std;


#include "MusicType.h"
#include"SortedLinkedList.h"
#include"GenreType.h"
#include"AlbumType.h"
#include"ArtistType.h"
#include"ManageType.h"
#include"UnSortedLinkedList.h"
#include"PLType.h"
#include"FolderType.h"
#define FILENameSIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		RemakeAlbumList = true;
		RemakeArtistList = true;
		RemakeGenreList = true;
		RemakeListForPlay = true;
		NumofPL = 0;
		Folder.setFname("C");
		Folder.setFloc("C");
		CurrentFolder = &Folder;
	}

	/**
	*	destructor.
	*/
	~Application()
	{
		DoublyIter<ArtistType> Atiter(ArtistList);
		while (Atiter.NotNull())
		{
			ArtistType* Atptr = nullptr; Atptr = Atiter.GetCurrentPtr();
			Atptr->MakeEmptyListinList();
			Atiter.Next();
		}
		m_List.MakeEmpty();
		GenreList.MakeEmpty();
		AlbumList.MakeEmpty();
	};

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();
	/**
*	@brief	음악파일을 추가하는 함수의 오버로딩. 파일에서부터 음악정보를 읽을때 사용함
*	@pre	list should be initialized.
*	@post	new record is added into the list.
*	@return	return 1 if this function works well, otherwise 0.
*/

	int AddMusic(MusicType item);
	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a fileName to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a fileName to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByName함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByName();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByName(MusicType &inData);

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchBySinger함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordBySinger();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchBySinger(MusicType &inData);


	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByAlbum함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByAlbum();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByAlbum(MusicType &inData);
	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByGenre함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByGenre();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByGenre(MusicType &inData);
	/**
	*	@brief	inData의 Index와 같은 Index를 가진 MusicList의 정보를 찾아온다
	*	@pre	inData의 Index가 초기화 되어 있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	Index가 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	
	void SearchByIndex(MusicType &indata);
	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 Musictype이 m_List에서 사라진다.
	*	@return	없다.
	*/
	
	void Delete();

	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 MusicType을 다시 입력받아 갱신한다.
	*	@return	없다.
	*/
	void Update();
	/**
	*	@brief	최근에 추가된 30곡의 자세한 정보를 화면에 출력
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DIsplayNewMusic();
	/**
	*	@brief	Primary key를 이용해 원하는 음악정보가져온다.
	*	@pre	리스트가 초기화되어야함.
	*	@post	inData에 원하는 곡정보가 담김
	*	@return	찾으면 1, 아니면 0
	*	@param key 곡번호를 찾기위한 int형 변수
	*	@inData 원하는 곡의 정보를 받아오기 위한 변수
	*/
	bool Search(int key, MusicType& inData);
	/**
	*	@brief	장르 리스트에 있는 곡들을 장르에 맞춰 출력
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayMusicbyGenre();

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByNameNGenre함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByNameNGenre();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByNameNGenre(MusicType &inData);
	/**
*	@brief	MusicList에 있는 곡을 앨범별로 출력한다.
*	@pre	없다.
*	@post	없다.
*	@return	없다.
*/
	void DisplayMusicByAlbum();
	/**
*	@brief	MusicList에 있는 곡을 아티스트별로 나누고, 각 아티스트별 로 앨범을 분류하여 출력한다.
*	@pre	없다.
*	@post	없다.
*	@return	없다.
*/
	void DisplayMusicByArtist();
	/**
*	@brief	MusicList에 있는 곡을 Primary Key에 따라 정렬된 순서에 따라 Index를 부여한다
*	@pre	MusicList에 최소한 하나이상의 곡이 있어야한다.
*	@post	MusicList의 각 MusicType에 Index가 부여된다
*	@return	없다.
*/
	void SetMusicIndex();
	/**
*	@brief	MusicList의 Music을 분류하는 하위리스트들을 다시 만들기 위한 조건을 충족시킨다.
*	@pre	곡이 추가되거나, 삭제되거나, 변경되어야 한다.
*	@post	Remake~~List 형의 변수의 값이 모두 true가 된다.
*	@return	없다.
*/
	void RemakeSubList()
	{
		RemakeAlbumList = true;
		RemakeArtistList = true;
		RemakeGenreList = true;
		RemakeListForPlay = true;
	};
	/**
*	@brief	재생목록을 만든다.
*	@pre	x
*	@post	PL_List에 새 재생목록이 추가된다.
*	@param	x
*	@return	x
*/
	void makePlayList();
	/**
*	@brief	재생목록안에 음악을 추가한다.
*	@pre	x
*	@post	재생목록안에 ManageType의 포인터가 추가된다.
*	@param	x
*	@return	x
*/
	void AddMusicInPL();
	/**
*	@brief	재생목록을 출력한다. 숫자를 입력받아 Play함수에 넘겨준다
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void PrintPL();
	
	/**
*	@brief	음악을 재생한다. 재생하면 재생횟수가 증가하며 최근재생목록에 음악이 등록된다.
*	@pre	뮤직리스트에 음악이 있어야하며 입력하는 음악의 Index가 MusicList의 Music에 있어야한다.
*	@post	재생한 음악의 재생횟수가 1회 추가되고 최근 재생된 목록에 음악이 추가된다.
*	@param	x
*	@return	x
*/
	void Play();
	/**
*	@brief	음악을 재생한다. 재생하면 재생횟수가 증가하며 최근재생목록에 음악이 등록된다. 재생목록에서 재생하기위한 Play함수의 오버로딩이다.
*	@pre	뮤직리스트에 음악이 있어야하며 입력하는 음악의 Index가 MusicList의 Music에 있어야한다.
*	@post	재생한 음악의 재생횟수가 1회 추가되고 최근 재생된 목록에 음악이 추가된다.
*	@param	Index PrintPL함수에서 받아온 넘버, 재생할 곡의 번호이다.
*	@return	x
*/
	void Play(int Index);
	/**
*	@brief	최근 재생된 목록에 곡을 추가한다.
*	@pre	Play 함수가 호출되어야 한다.
*	@post	RecentlyPlayedList에 ManageType이 추가된다.
*	@param	mptr 추가하고자 하는 MusicList의 특정원소의 주소값
*	@return	x
*/
	void AddRecentlyPlayedList(MusicType* mptr);
	/**
*	@brief	최근 재생된 목록을 출력한다.
*	@pre	x
*	@post	x
*	@param	x	
*	@return	x
*/
	void DisplayRecentlyPlayedMusic();
	/**
*	@brief	현재 폴더에 새 폴더를 추가한다.
*	@pre	x
*	@post	현재 폴더에 새 폴더가 추가된다.
*	@param	x
*	@return	x
*/
	void AddFolder();
	/**
*	@brief	상위 폴더로 간다.
*	@pre	현재 폴더가 최상위 폴더가 아니어야 한다.
*	@post	CurrentFolder가 상위 폴더를 가리키게 된다.
*	@param	x
*	@return	x
*/
	void GotoMotherFolder();
	/**	
*	@brief	폴더안의 모든 내용을 출력한다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayFolder();
	/**
*	@brief	하위 폴더로 간다.
*	@pre	현재 폴더에 하위폴더가 있어야한다. & 입력한 폴더명이 하위폴더에 있어야한다.
*	@post	CurrentFolder가 원하는 하위 폴더를 가리키게 된다.
*	@param	x
*	@return	x
*/
	void GotoSubFolder();
	/**
*	@brief	검색기능을 모아둔 모듈
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void SearchModule();
	/**
*	@brief	분류별 출력기능을 모아둔 모듈
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayModule();
	/**
*	@brief	폴더 기능을 모아둔 모듈
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void FolderModule();
	/**
*	@brief	재생목록 기능을 모아둔 모듈
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void PlayListModule();
	/**
*	@brief	곡을 랜덤으로 재생한다.
*	@pre	x
*	@post	랜덤으로 선택된 곡이 재생된다.
*	@param	x
*	@return	x
*/

	void RandomPlay();
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedLinkedList<MusicType> m_List;		/// 노래 리스트
	UnSortedLinkedList<ManageType> mg_List;		//곡을 관리하기 위한 ManageType의 리스트
	int m_Command;			///< current command number.
	SortedLinkedList<AlbumType> AlbumList;			//앨범을 분류하기 위한 앨범리스트
	SortedLinkedList<ArtistType> ArtistList;		//아티스트를 분류하기 위한 아티스트리스트
	SortedLinkedList <GenreType> GenreList;		//장르를 분류하기 위한 장르 리스트
	UnSortedLinkedList<PLType> PlayLists;	//재생목록들
	UnSortedLinkedList<ManageType> RecentlyPlayedList;		//최근 재생한 목록
	FolderType Folder;		//기본 폴더
	FolderType* CurrentFolder;		//현재 폴더를 나타내기 위한 폴더추적용 변수
	MusicType** ListforPlay;		//재생을 위한 ArrayList
	//아래의 변수들은 각 하위 리스트를 다시만들어야 할지 판별하는 변수이다.
	bool RemakeAlbumList;			
	bool RemakeArtistList;
	bool RemakeGenreList;
	bool RemakeListForPlay;
	//
	int NumofPL;	//재생목록의 수
};



#endif	// _APPLICATION_H



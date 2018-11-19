
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;


#include "MusicType.h"
#include"SortedLinkedList.h"
#include"GenreType.h"
#include"AlbumType.h"
#include"ArtistType.h"
#include"ManageType.h"
#include"UnSortedLinkedList.h"
#include"PLType.h"
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
		NumofPL = 0;

	}

	/**
	*	destructor.
	*/
	~Application()
	{
		DoublyIter<ArtistType> Atiter(ArtistList);
		while (Atiter.NotNull())
		{
			ArtistType* Atptr = Atiter.GetCurrentPtr();
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
	};

	void makePlayList();

	void AddMusicInPL();

	void PrintPL();
	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedLinkedList<MusicType> m_List;		/// 노래 리스트
	UnSortedLinkedList<ManageType> mg_List;
	int m_Command;			///< current command number.
	SortedLinkedList<AlbumType> AlbumList;			//앨범을 분류하기 위한 앨범리스트
	SortedLinkedList<ArtistType> ArtistList;		//아티스트를 분류하기 위한 아티스트리스트
	SortedLinkedList <string> GenreList;		//장르를 분류하기 위한 장르 리스트
	UnSortedLinkedList<PLType> PlayLists;
	//아래의 변수들은 각 하위 리스트를 다시만들어야 할지 판별하는 변수이다.
	bool RemakeAlbumList;			
	bool RemakeArtistList;
	bool RemakeGenreList;
	int NumofPL;
};



#endif	// _APPLICATION_H



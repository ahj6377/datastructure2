
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;




/**
*	item information class.
*/
class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{
		Num = -1;
		Name = "";
		Singer = "";
		Album = "";
		Genre = "";
		Lyrics = "";
		Played = 0;
	}

	/**
	*	destructor.
	*/
	~MusicType() {}
	/**
	*	@brief	Get song Name
	*	@pre	song Name is set.
	*	@post	none.
	*	@return	song Name;
*/
	int GetNum()
	{
		return Num;
	}
	/**
	*	@brief	Get song Name
	*	@pre	song Name is set.
	*	@post	none.
	*	@return	song Name;
	*/
	string GetName()
	{
		return Name;
	}

	/**
	*	@brief	Get Singer Name.
	*	@pre	Singer Name is set.
	*	@post	none.
	*	@return	Singer Name.
	*/
	string GetSinger()
	{
		return Singer;
	}

	/**
	*	@brief	Get Album Name
	*	@pre	Album Name is set.
	*	@post	none.
	*	@return	Album Name.
	*/
	string GetAlbum()
	{
		return Album;
	}
	/**
	*	@brief	Get Genre
	*	@pre	Genre is set.
	*	@post	none.
	*	@return	Genre.
	*/
	string GetGenre()
	{
		return Genre;
	}
	/**
	*	@brief	Get Lyrics
	*	@pre	Lyrics is set.
	*	@post	none.
	*	@return	Lyrics.
	*/
	string GetLyrics()
	{
		return Lyrics;
	}
	/**
	*	@brief	Get Pkey
	*	@pre	Pkey is set.
	*	@post	none.
	*	@return	Pkey
	*/
	string GetPkey()
	{
		return Pkey;
	}
	/**
	*	@brief	Set song Name
	*	@pre	none.
	*	@post	song Name is set.
	*	@param	s_Name song Name
	*/
	void SetName(string s_Name)
	{
		Name = s_Name;
	}
	/**
*	@brief	Set song Name
*	@pre	none.
*	@post	song Name is set.
*	@param	s_Name song Name
*/
	void SetNum(int s_Num)
	{
		Num = s_Num;
	}
	/**
	*	@brief	Set Singer Name
	*	@pre	none.
	*	@post	Singer Name is set.
	*	@param	s_Singer	Singer Name.
	*/
	void SetSinger(string s_Singer)
	{
		Singer = s_Singer;
	}

	/**
	*	@brief	Set Album Name
	*	@pre	none.
	*	@post	Album Name is set.
	*	@param	s_Album	Album Name.
	*/
	void SetAlbum(string s_Album)
	{
		Album = s_Album;
	}
	/**
	*	@brief	Set Genre
	*	@pre	none.
	*	@post	Genre is set.
	*	@param	s_Genre	Genre.
	*/
	void SetGenre(string s_Genre)
	{
		Genre = s_Genre;
	}
	/**
	*	@brief	Set Lyrics
	*	@pre	none.
	*	@post Lyrics is set.
	*	@param	s_Lyrics Lyrics
	*/
	void SetLyrics(string s_Lyrics)
	{
		Lyrics = s_Lyrics;
	}
	/**
	*	@brief	Set Pkey
	*	@pre	none.
	*	@post Pkey is set.
	*/
	void SetPkey()
	{
		Pkey = Name + Singer;
	}
	/**
	*	@brief	Set song information
	*	@pre	none.
	*	@post	song information is set
	*	@param	s_Name song Name
	*	@param	s_Singer Singer Name
	*	@param	s_Album Album Name.
	*	@param  s_Genre Genre
	*	@param	s_Lyrics Lyrics;
	*/
	void SetRecord(string s_Name, string s_Singer, string s_Album, string s_Genre, string s_Lyrics)
	{
		SetName(s_Name);
		SetSinger(s_Singer);
		SetAlbum(s_Album);
		SetGenre(s_Genre);
		SetLyrics(s_Lyrics);
		SetPkey();
	}
	/**
	*	@brief	Display song Name on screen.
	*	@pre	song Name is set.
	*	@post	song Name is on screen.
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tSong Number(Track Number)	: " << Num << endl;
	};
	/**
	*	@brief	Display song Name on screen.
	*	@pre	song Name is set.
	*	@post	song Name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tSong Name   : " << Name << endl;
	};

	/**
	*	@brief	Display Singer Name on screen.
	*	@pre	Singer Name is set.
	*	@post	Singer Name is on screen.
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\tArtist(Singer) : " << Singer << endl;
	};

	/**
	*	@brief	Display Album Name on screen.
	*	@pre	Album Name is set.
	*	@post	Album Name is on screen.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum : " << Album << endl;
	};

	/**
	*	@brief	Display Genre on screen.
	*	@pre	Genre is set.
	*	@post	Genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << Genre << endl;
	};
	/**
*	@brief	Display Lyrics on screen.
*	@pre	Lyrics is set.
*	@post	Lyrics is on screen.
*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << Lyrics << endl;
	};
	/**
	*	@brief	Display an song information on screen.
	*	@pre	song information is set.
	*	@post	song information is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNumOnScreen();
		DisplayNameOnScreen();
		DisplaySingerOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
	};
	/**
	*	@brief	Set song Number from keyboard.
	*	@pre	none.
	*	@post	song Number is set.
	*/
	void SetNumFromKB();
	/**
	*	@brief	Set song Name from keyboard.
	*	@pre	none.
	*	@post	song Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Singer Name from keyboard.
	*	@pre	none.
	*	@post	Singer Name is set.
	*/
	void SetSingerFromKB();

	/**
	*	@brief	Set Album Name from keyboard.
	*	@pre	none.
	*	@post	Album Name is set.
	*/
	void SetAlbumFromKB();
	/**
	*	@brief	Set Genre from keyboard.
	*	@pre	none.
	*	@post	Genre is set.
	*/
	void SetGenreFromKB();
	/**
	*	@brief	Set Lyrics from keyboard.
	*	@pre	none.
	*	@post	Lyrics is set.
	*/
	void SetLyricsFromKB();
	/**
	*	@brief	Set song information from keyboard.
	*	@pre	none.
	*	@post	song information is set.
	*/
	void SetInfoFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
*	@brief	두 MusicType의 Primary key가 같은지 비교함
*	@pre	비교하고자 하는 MusicType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	같을경우 true, 다를경우 false
*/
	bool operator==(MusicType data)
	{
		
		if (this->GetPkey() == data.GetPkey())
			return true;
		else
			return false;
	}
	/**
*	@brief	두 MusicType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 MusicType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	좌변이 클경우 true 작을경우 false

*/
	bool operator>(MusicType data)
	{
		return (this->GetPkey() > data.GetPkey());
	}
	/**
*	@brief	두 MusicType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 MusicType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	우변이 클경우 true 작을경우 false
*/
	bool operator<(MusicType data)
	{
		return (this->GetPkey() < data.GetPkey());

	}
	/**
*	@brief	재생된 횟수를 1 증가시킨다.
*	@pre	x
*	@post	재생횟수가 1 늘어난다
*	@param	x
*	@return	x
*/
	void cntPlayed()
	{
		Played++;
	}
	/**
*	@brief	재생된 횟수를 보여준다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	int DisplayPlayed()
	{
		return Played;
	}
	/**
*	@brief	곡명과 Index(track numbeR)을 출력한다.
*	@pre	곡명과 number가 초기화되어있어야한다.
*	@post	x	
*	@param	x
*	@return	x
*/
	void DisplayNameNIndex()
	{
		cout << "\t곡명 : " << Name << endl;
		cout << "\tTrackNo. : " << Num << endl;
	}
	/**
*	@brief	음악파일의 경로를 지정한다.
*	@pre	x
*	@post	음악파일의 경로가 set된다
*	@param	loc 경로
*	@return	x
*/
	void SetLoc(string loc) {
		Loc = loc;
	}
	/**
*	@brief	음악파일의 경로를 get한다
*	@pre	음악파일의 경로가 초기화되어 있어야한다.
*	@post	x
*	@param	x
*	@return	경로 string
*/
	string GetLoc()
	{
		return Loc;
	}
protected:
	int Num;		//곡의 인덱스
	string Name; //곡명
	string Singer; //가수
	string Album; //앨범
	string Genre; //장르
	string Lyrics; //가사
	string Pkey; //Primary Key
	string Loc;	//음악파일의 경로
	int Played;	//재생된 횟수
};




#endif	// _MusicType_H

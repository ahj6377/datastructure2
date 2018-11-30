
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
*	@brief	�� MusicType�� Primary key�� ������ ����
*	@pre	���ϰ��� �ϴ� MusicType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	������� true, �ٸ���� false
*/
	bool operator==(MusicType data)
	{
		
		if (this->GetPkey() == data.GetPkey())
			return true;
		else
			return false;
	}
	/**
*	@brief	�� MusicType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� MusicType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�º��� Ŭ��� true ������� false

*/
	bool operator>(MusicType data)
	{
		return (this->GetPkey() > data.GetPkey());
	}
	/**
*	@brief	�� MusicType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� MusicType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�캯�� Ŭ��� true ������� false
*/
	bool operator<(MusicType data)
	{
		return (this->GetPkey() < data.GetPkey());

	}
	/**
*	@brief	����� Ƚ���� 1 ������Ų��.
*	@pre	x
*	@post	���Ƚ���� 1 �þ��
*	@param	x
*	@return	x
*/
	void cntPlayed()
	{
		Played++;
	}
	/**
*	@brief	����� Ƚ���� �����ش�.
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
*	@brief	���� Index(track numbeR)�� ����Ѵ�.
*	@pre	���� number�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x	
*	@param	x
*	@return	x
*/
	void DisplayNameNIndex()
	{
		cout << "\t��� : " << Name << endl;
		cout << "\tTrackNo. : " << Num << endl;
	}
	/**
*	@brief	���������� ��θ� �����Ѵ�.
*	@pre	x
*	@post	���������� ��ΰ� set�ȴ�
*	@param	loc ���
*	@return	x
*/
	void SetLoc(string loc) {
		Loc = loc;
	}
	/**
*	@brief	���������� ��θ� get�Ѵ�
*	@pre	���������� ��ΰ� �ʱ�ȭ�Ǿ� �־���Ѵ�.
*	@post	x
*	@param	x
*	@return	��� string
*/
	string GetLoc()
	{
		return Loc;
	}
protected:
	int Num;		//���� �ε���
	string Name; //���
	string Singer; //����
	string Album; //�ٹ�
	string Genre; //�帣
	string Lyrics; //����
	string Pkey; //Primary Key
	string Loc;	//���������� ���
	int Played;	//����� Ƚ��
};




#endif	// _MusicType_H

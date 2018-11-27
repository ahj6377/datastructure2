#pragma once
#include<string>
using namespace std;
#include"SortedLinkedList.h"
#include"MusicType.h"
#include"UnSortedLinkedList.h"
class AlbumType {
public:

	AlbumType()
	{
		AlbumName = "";
		ArtistName = "";
	}		//기본 생성자
	~AlbumType()
	{
		
	}		//기본 소멸자
	/**
*	@brief	AlbumType의 생성자이다.
*	@pre	x
*	@post	AlbumType이 생성된다.
	@param albumname 앨범명
	@param artistname 이 앨범을 낸 아티스트명
*/
	AlbumType(string albumname, string artistname)
	{
		AlbumName = albumname;
		ArtistName = artistname;
	}
	
	AlbumType(const AlbumType& data)
	{
		AlbumName = data.AlbumName;
		ArtistName = data.ArtistName;
		Ab_List = data.Ab_List;
	}
	
	/**
*	@brief AlbumName 을 set한다.
*	@pre	x
*	@post	AlbumName is set
*	@return	x
*/
	void SetAlbumName(string Name)
	{
		AlbumName = Name;
	};
	/**
*	@brief	ArtistName을 set한다.
*	@pre	x
*	@post	ArtistName is set
*	@return	x
*/
	void SetArtistName(string Name)
	{
		ArtistName = Name;
	};
	/**
*	@brief get AlbumName
*	@pre	AlbumName is set
*	@post	x
*	@return	AlbumName
*/
	string GetAlbumName()
	{ 
		return AlbumName;
	};
	/**
*	@brief	getArtistName
*	@pre	ArtistName is set
*	@post	x	
*	@return	ArtistName
*/
	string GetArtistName() 
	{
		return ArtistName; 
	};
	/**
*	@brief	비교 연산자
*	@pre	비교하려는 두 앨범타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 앨범타입
*	@return	좌변이크면 false, 우변이크면 true
*/
	bool operator<(AlbumType data)
	{
		if (AlbumName == data.GetAlbumName())
			return (ArtistName < data.GetArtistName());
		else
			return (AlbumName < data.GetAlbumName());
	};
	/**
*	@brief	비교 연산자
*	@pre	비교하려는 두 앨범타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 앨범타입
*	@return	좌변이크면 true, 우변이크면 false
*/
	bool operator>(AlbumType data)
	{
		if (AlbumName == data.GetAlbumName())
			return (ArtistName > data.GetArtistName());
		else
			return (AlbumName > data.GetAlbumName());
	};
	/**
*	@brief	등위연산자 
*	@pre	비교하려는 두 앨범타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 앨범타입
*	@return	두 항이 같으면 true 아니면 false
*/
	bool operator==(AlbumType data) {
		if (AlbumName == data.GetAlbumName() && ArtistName == data.GetArtistName())
			return true;
		else
			return false;
	};

	AlbumType operator=(const AlbumType& D);

	void AddListinList(MusicType* in);

	void Printall();
	
	void SearchInListbyGenre();
private:
	string AlbumName; //앨범 이름을 저장할 변수
	string ArtistName; //앨범의 아티스트를 저장할 변수
	UnSortedLinkedList<MusicType*> Ab_List;
};

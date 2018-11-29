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
	/**
*	@brief	대입 연산자
*	@pre	D가 초기화되어 있어야한다
*	@post	this에 D의 값이 대입된다. +깊은복사
*	@param	D 대입하고자 하는 데이터
*	@return	this
*/
	AlbumType operator=(const AlbumType& D);
	/**
*	@brief	리스트 안 리스트에 원소를 넣는다.
*	@pre	x
*	@post	Ab_List에 MusicType의 포인터가 삽입된다.
*	@param	in 넣고자하는 MusicType의 포인터
*	@return x
*/
	void AddListinList(MusicType* in);
	/**
*	@brief	리스트인 리스트의 모든 원소를 출력한다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void Printall();
	/**
*	@brief	앨범리스트 안의 원소를 장르별로 검색한다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void SearchInListbyGenre();
	/**
*	@brief	ArtistType의 SearchInListbyGenre 함수에서 장르명을 받아와 이 앨범안에서 장르별로 찾는 함수이다.
*	@pre	x
*	@post	x
*	@param	str 찾고자하는 장르명
*	@return	x
*/

	void FindInListbyGenre(string str);
private:
	string AlbumName; //앨범 이름을 저장할 변수
	string ArtistName; //앨범의 아티스트를 저장할 변수
	UnSortedLinkedList<MusicType*> Ab_List;		//MusicList의 원소들중 이 앨범타입의 앨범명과 아티스트명이 같은 원소들의 주소를 모아둔 리스트
};

#pragma once
#include"AlbumType.h"
#include<iostream>
using namespace std;

class ArtistType {
public:
	ArtistType()
	{
		ArtistName = "";
	}
		;	//기본 생성자
	~ArtistType()
	{
		AlbumList.MakeEmpty();
	}
	;	//기본 소멸자
	ArtistType(const ArtistType& data);
	/**
*	@brief	Get ArtistName
*	@pre	ArtistName is set
*	@post	x
*	@return	ArtistName
*/
	string GetArtistName() 
	{
		return ArtistName;
	};
	/**
*	@brief	set ArtistName
*	@pre	x
*	@post	ArtistName is set
*/
	void SetArtistName(string Name)
	{
		ArtistName = Name;
	};
	/**
*	@brief	비교 연산자
*	@pre	비교하려는 두 아티스트타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 아티스트타입
*	@return	좌변이크면 false, 우변이크면 true
*/
	bool operator<(ArtistType data)
	{
		return (ArtistName < data.GetArtistName());
	};
	/**
*	@brief	비교 연산자
*	@pre	비교하려는 두 아티스트타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 아티스트타입
*	@return	좌변이크면 true, 우변이크면 false
*/
	bool operator>(ArtistType data)
	{
		return (ArtistName > data.GetArtistName());
	};
	/**
*	@brief	등위 연산자
*	@pre	비교하려는 두 아티스트타입이 초기화되어 있어야한다
*	@post	x
*	@param	data 비교하려는 아티스트타입
*	@return	두 항이 같으면 true 아니면 false
*/
	bool operator==(ArtistType data)
	{
		if (ArtistName == data.GetArtistName())
			return true;
		else
			return false;
	};
	/**
*	@brief	대입 연산자
*	@pre	패러미터로 넘어오는 Artisttype이 초기화되어있어야한다.
*	@post	this가 data와 같아진다
*	@param	data 대입하려는 아티스트타입
*	@return	*this
*/
	ArtistType operator=(const ArtistType& data)
	{
		ArtistName = data.ArtistName;
		AlbumList = data.AlbumList;
		return *this;
	};
	/**
*	@brief	리스트안의 리스트에 원소를 추가한다
*	@pre	x
*	@post	AlbumList에 앨범이 추가된다.
*	@param	A 추가하려는 앨범타입
*/
	void AddListinList(AlbumType &A)
	{
		AlbumList.Add(A);
	};
	/**
*	@brief	리스트 안의 리스트의 내용을 출력한다.
*	@pre	앨범리스트가 초기화되어 있어야 한다.
*	@post	x
*/
	void PrintListinList() ;
	/**
*	@brief	리스트인 리스트를 비워준다.
*	@pre	x
*	@post	AlbumList가 비워진다.
*	@param	x
*	@return		x
*/
	void MakeEmptyListinList()
	{
		AlbumList.MakeEmpty();
	}
	/**
*	@brief	이 아티스트 타입 내에서 장르별로 검색한다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void SearchInListbyGenre();
	
private:
	SortedLinkedList<AlbumType> AlbumList;		//한 아티스트가 가지는 앨범 리스트
	string ArtistName;

};

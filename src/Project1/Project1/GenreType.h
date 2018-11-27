#pragma once
#include<iostream>
#include<string>
#include"SortedLinkedList.h"
#include"UnSortedLinkedList.h"
#include"MusicType.h"
using namespace std;
/**
*	@brief	과제 1에서 이 클래스는 쓰이지 않는다.

*/
class GenreType			//현재 이 장르타입은 쓰지 않는다.
{
public:
	GenreType()
	{
		
		G_name = "";
	}	//기본 생성자

	~GenreType()
	{
	
	} //기본 소멸자
	GenreType(const GenreType& data)
	{
		G_name = data.G_name;
		G_List = data.G_List;
	}
	/**
	*	@brief	Get Genre
	*	@pre	Genre is set.
	*	@post	none.
	*	@return	Genre;
*/
	string GetGenre()
	{
		return G_name;
	}

	/**
	*	@brief	set genre
	*	@pre	x
	*	@post	genre is set
	*	@param Genre Genre
*/
	void SetGenre(string Genre)
	{
		G_name = Genre;
	}
	/**
*	@brief	두 SimplifiedType의 Primary key가 같은지 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	같을경우 true, 다를경우 false
*/
	bool operator==(GenreType data)
	{

		if (this->GetGenre() == data.GetGenre())
			return true;
		else
			return false;
	}
	/**
*	@brief	두 SimplifiedType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	좌변이 클경우 true 작을경우 false

*/
	bool operator>(GenreType data)
	{
		if (this->GetGenre() > data.GetGenre())
			return true;
		else
			return false;
	}
	/**
*	@brief	두 SimplifiedType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	우변이 클경우 true 작을경우 false
*/
	bool operator<(GenreType data)
	{
		if (this->GetGenre() < data.GetGenre())
			return true;
		else
			return false;

	}
	/**
*	@brief	GenreList안에 Simplified 타입을 넣는 함수
*	@pre	x
*	@post	현재 GenreList에 Simplified 타입이 추가된다
*	@param	추가하고자 하는 데이터
*/
	void addListinList(MusicType* in)
	{
		G_List.Add(in);
	}
	/**
*	@brief	현 GenreList안의 모든 데이터를 출력하는함수
*	@pre	GenreList안의 원소가 초기화 되어있어야함
*	@post	x
*/
	void PrintAll();

	GenreType operator=(const GenreType& data);


private:

	string G_name; //장르 명
	UnSortedLinkedList<MusicType*> G_List;
};
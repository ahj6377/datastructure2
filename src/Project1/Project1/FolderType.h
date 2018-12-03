#pragma once


#include<iostream>

#include"ManageType.h"
#include"UnSortedLinkedList.h"
class FolderType {
private:
	UnSortedLinkedList<FolderType> Subfolder;
	UnSortedLinkedList<ManageType*> Musics;
	string Foldername;
	string FolderLoc;
	FolderType* Motherfolder;
public:
	FolderType() { Foldername = ""; Motherfolder = NULL; };		//기본 생성자
	~FolderType() {};		//기본 소멸자
	/**
*	@brief	폴더명을 set한다
*	@pre	x
*	@post	폴더명이 set된다.
*	@param	N 폴더명
*	@return	x
*/
	void setFname(string N)
	{
		Foldername = N;
	};
	/**
*	@brief	폴더명을 get한다
*	@pre	폴더명이 초기화되어 있어야한다.
*	@post	x
*	@param	x
*	@return	폴더명
*/
	string getFname()
	{
		return Foldername;
	}
	/**
*	@brief 폴더 경로를 set한다
*	@pre	x
*	@post	폴더경로가 set된다
*	@param	Loc 폴더경로
*	@return	x
*/
	void setFloc(string Loc)
	{
		FolderLoc = Loc;
	}
	/**
*	@brief	폴더 경로를 get한다
*	@pre	폴더 경로가 초기화되어 있어야한다
*	@post	x
*	@param	x
*	@return	폴더 경로
*/
	string getFloc()
	{
		return FolderLoc;
	}
	/**
*	@brief	폴더안에 음악을 추가한다
*	@pre	x
*	@post	폴더안에 ManagaType의 포인터가 추가된다.
*	@param	in 추가하고자하는 ManageType의 포인터(MusicType의 포인터를 가지는 타입의 포인터)
*	@return	x
*/
	void AddMusic(ManageType* in);
	/**
*	@brief	현재 폴더에 하위 폴더를 추가한다
*	@pre	x
*	@post	subfolders에 새 폴더가 추가된다.
*	@param	x
*	@return	x
*/
	void AddFolder();
	/**
*	@brief	폴더안의 모든 내용을 폴더와 음악 별로 출력한다.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayAllinFolder();
	/**
*	@brief	상위 폴더의 경로를 set한다
*	@pre	x
*	@post	상위 폴더의 경로가 Motherfolder에 저장된다.
*	@param	ptr 상위폴더의 주소값
*	@return	x
*/
	void setMfolder(FolderType* ptr)
	{
		Motherfolder = ptr;
	}
	/**
*	@brief	상위폴더의 경로를 get한다
*	@pre	상위폴더가 초기화되어 있어야한다. 상위폴더가 NULL이 아니어야한다.
*	@post	x
*	@param	x
*	@return	상위폴더의 주소값
*/
	FolderType* getMfolder()
	{
		return Motherfolder;
	}
	/**
*	@brief	등위 연산자
*	@pre	data 와 this가 초기화되어있어야한다
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	폴더명이 같고 상위폴더가 같아야 true 그외엔 false
*/
	bool operator==(const FolderType& data)
	{
		if (Foldername == data.Foldername && Motherfolder == data.Motherfolder)
			return true;
		else
			return false;
	}
	/**
*	@brief	폴더안에 있는 폴더만 출력
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayFolders();
	/**
*	@brief	하위 폴더로 가기 위해 원하는 하위폴더의 주소값을 반환하는 함수
*	@pre	하위폴더가 있어야함.
*	@post	x
*	@param	str 이동하고자하는 하위폴더의 이름
*	@return	하위폴더의 주소값
*/
	FolderType* ReturnSubFolder(string str);


};
#pragma once
#include"MusicType.h"


class ManageType {
private:
	MusicType* mptr;
	bool Isdeleted;
public:
	ManageType() {
		bool Isdeleted = false;
		mptr = NULL;
	};		//기본 생성자
	~ManageType() {};
	void setPtr(MusicType* P)
	{
		mptr = P;
	}		//기본 소멸자
	/**
*	@brief	musictype의 포인터를 get한다
*	@pre	mptr이 초기화되어있어야한다.
*	@post	x
*	@param	x
*	@return	이 managetype이 가지고있는 MusicList의 특정원소의 주소값
*/
	MusicType* getPtr()
	{
		return mptr;
	}
	/**
*	@brief	이 ManageType을 지운것처럼 표시하는 함수
*	@pre	x
*	@post	Isdeleted가 true가 되고 mptr은 NULL을 가리키게 된다
*	@param	x
*	@return	x
*/
	void Deleted()
	{
		Isdeleted = true;
		mptr = NULL;
	}
	/**
*	@brief	musictype의 Index를 받아온다.
*	@pre	mptr이 초기화되어있어야한다.
*	@post	x
*	@param	x
*	@return	musictype의 index값
*/
	int getIndex()
	{
		if (Isdeleted == false)
		{
			return (mptr->GetNum());
		}
	}
	/**
*	@brief musictype의 name을 받아온다.
*	@pre	mptr이 초기화되어있어야한다.
*	@post	x
*	@param	x	
*	@return	musictype의 name값
*/
	string getName()
	{	if(Isdeleted == false)
		return mptr->GetName();
	}
	/**
*	@brief	musictype의 primarykey를 받아온다
*	@pre	mptr이 초기화되어있어야한다.
*	@post	x
*	@param	x	
*	@return	x
*/
	string getPkey()
	{	if(Isdeleted == false)
		return mptr->GetPkey();
	}
	/**
*	@brief	musicType의 이름과 index(track number)를 출력한다
*	@pre	mptr이 초기화되어있어야하고 Isdeleted가 false여야한다.
*	@post	x
*	@param	x
*	@return	Isdeleted가 true면 false Isdeleted가 false면 true
*/
	bool PrintNameNIndex();
	/**
*	@brief	등위연산자
*	@pre	data과 this가 초기화되어있어야한다.
*	@post	x
*	@param	data 비교하고자 하는 data
*	@return	두 managatype이 담는 포인터가 같고 삭제되지 않았을경우에만 true
*/
	bool operator==(const ManageType& data)
	{
		if (mptr == data.mptr && Isdeleted == false)
			return true;
		else
			return false;
	}

	bool Getdeleted()
	{
		if (Isdeleted == true)
			return true;
		else
			return false;
	}
};


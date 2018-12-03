#pragma once
#include"ManageType.h"
#include"UnSortedLinkedList.h"
class PLType {
private:

	UnSortedLinkedList<ManageType*> PlayList;
	string PLname;
	int length;
public:
	PLType() { length = 0; PLname = ""; }		//기본 생성자
	~PLType() {}		//기본 소멸자
	/**
*	@brief	복사 생성자
*	@pre	x
*	@post	x
*	@param	data 복사하고자 하는 데이터값
*	@return	x
*/
	PLType(const PLType& data);	
	/**
*	@brief	재생목록의 이름을 set한다
*	@pre	x
*	@post	재생목록의 이름이 set된다
*	@param	N 재생목록의 이름
*	@return	x
*/
	void setPLname(string N)
	{
		PLname = N;
	}
	/**
*	@brief	재생목록의 이름을 받아온다
*	@pre	재생목록의 이름이 초기화되어있어야한다.
*	@post	x
*	@param	x	
*	@return	재생목록이름
*/
	string getPLname()
	{
		return PLname;
	}
	/**
*	@brief	재생목록안에 곡을 추가한다.
*	@pre	x
*	@post	재생목록안데 ManagaType*가 추가된다.
*	@param	data 추가하고자하는 ManageType의 주소값
*	@return	x
*/
	void AddListinList(ManageType* data)
	{
		PlayList.Add(data);
		length++;
	}
	/**
*	@brief	재생목록안의 모든 곡을 출력한다
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void Printall();



};

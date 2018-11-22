#pragma once
#include<iostream>
#include<string>
#include"SortedLinkedList.h"
#include"SimplifiedType.h"
using namespace std;
/**
*	@brief	���� 1���� �� Ŭ������ ������ �ʴ´�.

*/
class GenreType			//���� �� �帣Ÿ���� ���� �ʴ´�.
{
public:
	GenreType()
	{
		G_num = -1;
		G_name = "";
	}	//�⺻ ������

	~GenreType()
	{
	
	} //�⺻ �Ҹ���

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
	*	@brief	Get song Number
	*	@pre	song Name is set.
	*	@post	none.
	*	@return	song number
*/
	int GetNum()
	{
		return G_num;
	}
	/**
	*	@brief	set song number
	*	@pre	x
	*	@post	song number is set
	*	@param num song number
*/
	void SetNum(int num)
	{
		G_num = num;
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
*	@brief	�� SimplifiedType�� Primary key�� ������ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	������� true, �ٸ���� false
*/
	bool operator==(GenreType data)
	{

		if (this->GetNum() == data.GetNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	�� SimplifiedType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�º��� Ŭ��� true ������� false

*/
	bool operator>(GenreType data)
	{
		if (this->GetNum() > data.GetNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	�� SimplifiedType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�캯�� Ŭ��� true ������� false
*/
	bool operator<(GenreType data)
	{
		if (this->GetNum() < data.GetNum())
			return true;
		else
			return false;

	}
	/**
*	@brief	GenreList�ȿ� Simplified Ÿ���� �ִ� �Լ�
*	@pre	x
*	@post	���� GenreList�� Simplified Ÿ���� �߰��ȴ�
*	@param	�߰��ϰ��� �ϴ� ������
*/
	void addListinGenre(SimplifiedType in)
	{
		G_List.Add(in);
	}
	/**
*	@brief	�� GenreList���� ��� �����͸� ����ϴ��Լ�
*	@pre	GenreList���� ���Ұ� �ʱ�ȭ �Ǿ��־����
*	@post	x
*/
	void PrintAll()
	{
		

		
		
	}




private:
	int G_num;	//�帣 �ѹ� = Primary Key
	string G_name; //�帣 ��
	SortedLinkedList<SimplifiedType> G_List;	//�� �帣�� �帣����Ʈ
};
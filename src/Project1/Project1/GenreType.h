#pragma once
#include<iostream>
#include<string>
#include"SortedLinkedList.h"
#include"UnSortedLinkedList.h"
#include"MusicType.h"
using namespace std;
/**
*	@brief	���� 1���� �� Ŭ������ ������ �ʴ´�.

*/
class GenreType			//���� �� �帣Ÿ���� ���� �ʴ´�.
{
public:
	GenreType()
	{
		
		G_name = "";
	}	//�⺻ ������

	~GenreType()
	{
	
	} //�⺻ �Ҹ���
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
*	@brief	�� SimplifiedType�� Primary key�� ������ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	������� true, �ٸ���� false
*/
	bool operator==(GenreType data)
	{

		if (this->GetGenre() == data.GetGenre())
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
		if (this->GetGenre() > data.GetGenre())
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
		if (this->GetGenre() < data.GetGenre())
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
	void addListinList(MusicType* in)
	{
		G_List.Add(in);
	}
	/**
*	@brief	�� GenreList���� ��� �����͸� ����ϴ��Լ�
*	@pre	GenreList���� ���Ұ� �ʱ�ȭ �Ǿ��־����
*	@post	x
*/
	void PrintAll();

	GenreType operator=(const GenreType& data);


private:

	string G_name; //�帣 ��
	UnSortedLinkedList<MusicType*> G_List;
};
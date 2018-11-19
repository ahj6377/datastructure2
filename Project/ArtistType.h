#pragma once
#include"AlbumType.h"
using namespace std;

class ArtistType {
public:
	ArtistType()
	{
		ArtistName = "";
	}
		;	//�⺻ ������
	~ArtistType()
	{
		AlbumList.MakeEmpty();
	}
	;	//�⺻ �Ҹ���
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
*	@brief	�� ������
*	@pre	���Ϸ��� �� ��Ƽ��ƮŸ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� ��Ƽ��ƮŸ��
*	@return	�º���ũ�� false, �캯��ũ�� true
*/
	bool operator<(ArtistType data)
	{
		return (ArtistName < data.GetArtistName());
	};
	/**
*	@brief	�� ������
*	@pre	���Ϸ��� �� ��Ƽ��ƮŸ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� ��Ƽ��ƮŸ��
*	@return	�º���ũ�� true, �캯��ũ�� false
*/
	bool operator>(ArtistType data)
	{
		return (ArtistName > data.GetArtistName());
	};
	/**
*	@brief	���� ������
*	@pre	���Ϸ��� �� ��Ƽ��ƮŸ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� ��Ƽ��ƮŸ��
*	@return	�� ���� ������ true �ƴϸ� false
*/
	bool operator==(ArtistType data)
	{
		if (ArtistName == data.GetArtistName())
			return true;
		else
			return false;
	};
	/**
*	@brief	���� ������
*	@pre	�з����ͷ� �Ѿ���� Artisttype�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	this�� data�� ��������
*	@param	data �����Ϸ��� ��Ƽ��ƮŸ��
*	@return	*this
*/
	ArtistType operator=(const ArtistType& data)
	{
		ArtistName = data.ArtistName;
		AlbumList = data.AlbumList;
		return *this;
	};
	/**
*	@brief	����Ʈ���� ����Ʈ�� ���Ҹ� �߰��Ѵ�
*	@pre	x
*	@post	AlbumList�� �ٹ��� �߰��ȴ�.
*	@param	A �߰��Ϸ��� �ٹ�Ÿ��
*/
	void AddListinList(AlbumType &A)
	{
		AlbumList.Add(A);
	};
	/**
*	@brief	����Ʈ ���� ����Ʈ�� ������ ����Ѵ�.
*	@pre	�ٹ�����Ʈ�� �ʱ�ȭ�Ǿ� �־�� �Ѵ�.
*	@post	x
*/
	void PrintListinList() ;

	void MakeEmptyListinList()
	{
		AlbumList.MakeEmpty();
	}
private:
	SortedLinkedList<AlbumType> AlbumList;		//�� ��Ƽ��Ʈ�� ������ �ٹ� ����Ʈ
	string ArtistName;

};

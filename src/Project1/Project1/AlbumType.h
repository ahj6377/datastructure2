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
	}		//�⺻ ������
	~AlbumType()
	{
		
	}		//�⺻ �Ҹ���
	/**
*	@brief	AlbumType�� �������̴�.
*	@pre	x
*	@post	AlbumType�� �����ȴ�.
	@param albumname �ٹ���
	@param artistname �� �ٹ��� �� ��Ƽ��Ʈ��
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
*	@brief AlbumName �� set�Ѵ�.
*	@pre	x
*	@post	AlbumName is set
*	@return	x
*/
	void SetAlbumName(string Name)
	{
		AlbumName = Name;
	};
	/**
*	@brief	ArtistName�� set�Ѵ�.
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
*	@brief	�� ������
*	@pre	���Ϸ��� �� �ٹ�Ÿ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� �ٹ�Ÿ��
*	@return	�º���ũ�� false, �캯��ũ�� true
*/
	bool operator<(AlbumType data)
	{
		if (AlbumName == data.GetAlbumName())
			return (ArtistName < data.GetArtistName());
		else
			return (AlbumName < data.GetAlbumName());
	};
	/**
*	@brief	�� ������
*	@pre	���Ϸ��� �� �ٹ�Ÿ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� �ٹ�Ÿ��
*	@return	�º���ũ�� true, �캯��ũ�� false
*/
	bool operator>(AlbumType data)
	{
		if (AlbumName == data.GetAlbumName())
			return (ArtistName > data.GetArtistName());
		else
			return (AlbumName > data.GetAlbumName());
	};
	/**
*	@brief	���������� 
*	@pre	���Ϸ��� �� �ٹ�Ÿ���� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	data ���Ϸ��� �ٹ�Ÿ��
*	@return	�� ���� ������ true �ƴϸ� false
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
	string AlbumName; //�ٹ� �̸��� ������ ����
	string ArtistName; //�ٹ��� ��Ƽ��Ʈ�� ������ ����
	UnSortedLinkedList<MusicType*> Ab_List;
};

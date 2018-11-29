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
	/**
*	@brief	���� ������
*	@pre	D�� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	this�� D�� ���� ���Եȴ�. +��������
*	@param	D �����ϰ��� �ϴ� ������
*	@return	this
*/
	AlbumType operator=(const AlbumType& D);
	/**
*	@brief	����Ʈ �� ����Ʈ�� ���Ҹ� �ִ´�.
*	@pre	x
*	@post	Ab_List�� MusicType�� �����Ͱ� ���Եȴ�.
*	@param	in �ְ����ϴ� MusicType�� ������
*	@return x
*/
	void AddListinList(MusicType* in);
	/**
*	@brief	����Ʈ�� ����Ʈ�� ��� ���Ҹ� ����Ѵ�.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void Printall();
	/**
*	@brief	�ٹ�����Ʈ ���� ���Ҹ� �帣���� �˻��Ѵ�.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void SearchInListbyGenre();
	/**
*	@brief	ArtistType�� SearchInListbyGenre �Լ����� �帣���� �޾ƿ� �� �ٹ��ȿ��� �帣���� ã�� �Լ��̴�.
*	@pre	x
*	@post	x
*	@param	str ã�����ϴ� �帣��
*	@return	x
*/

	void FindInListbyGenre(string str);
private:
	string AlbumName; //�ٹ� �̸��� ������ ����
	string ArtistName; //�ٹ��� ��Ƽ��Ʈ�� ������ ����
	UnSortedLinkedList<MusicType*> Ab_List;		//MusicList�� ���ҵ��� �� �ٹ�Ÿ���� �ٹ���� ��Ƽ��Ʈ���� ���� ���ҵ��� �ּҸ� ��Ƶ� ����Ʈ
};

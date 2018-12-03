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
	FolderType() { Foldername = ""; Motherfolder = NULL; };		//�⺻ ������
	~FolderType() {};		//�⺻ �Ҹ���
	/**
*	@brief	�������� set�Ѵ�
*	@pre	x
*	@post	�������� set�ȴ�.
*	@param	N ������
*	@return	x
*/
	void setFname(string N)
	{
		Foldername = N;
	};
	/**
*	@brief	�������� get�Ѵ�
*	@pre	�������� �ʱ�ȭ�Ǿ� �־���Ѵ�.
*	@post	x
*	@param	x
*	@return	������
*/
	string getFname()
	{
		return Foldername;
	}
	/**
*	@brief ���� ��θ� set�Ѵ�
*	@pre	x
*	@post	������ΰ� set�ȴ�
*	@param	Loc �������
*	@return	x
*/
	void setFloc(string Loc)
	{
		FolderLoc = Loc;
	}
	/**
*	@brief	���� ��θ� get�Ѵ�
*	@pre	���� ��ΰ� �ʱ�ȭ�Ǿ� �־���Ѵ�
*	@post	x
*	@param	x
*	@return	���� ���
*/
	string getFloc()
	{
		return FolderLoc;
	}
	/**
*	@brief	�����ȿ� ������ �߰��Ѵ�
*	@pre	x
*	@post	�����ȿ� ManagaType�� �����Ͱ� �߰��ȴ�.
*	@param	in �߰��ϰ����ϴ� ManageType�� ������(MusicType�� �����͸� ������ Ÿ���� ������)
*	@return	x
*/
	void AddMusic(ManageType* in);
	/**
*	@brief	���� ������ ���� ������ �߰��Ѵ�
*	@pre	x
*	@post	subfolders�� �� ������ �߰��ȴ�.
*	@param	x
*	@return	x
*/
	void AddFolder();
	/**
*	@brief	�������� ��� ������ ������ ���� ���� ����Ѵ�.
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayAllinFolder();
	/**
*	@brief	���� ������ ��θ� set�Ѵ�
*	@pre	x
*	@post	���� ������ ��ΰ� Motherfolder�� ����ȴ�.
*	@param	ptr ���������� �ּҰ�
*	@return	x
*/
	void setMfolder(FolderType* ptr)
	{
		Motherfolder = ptr;
	}
	/**
*	@brief	���������� ��θ� get�Ѵ�
*	@pre	���������� �ʱ�ȭ�Ǿ� �־���Ѵ�. ���������� NULL�� �ƴϾ���Ѵ�.
*	@post	x
*	@param	x
*	@return	���������� �ּҰ�
*/
	FolderType* getMfolder()
	{
		return Motherfolder;
	}
	/**
*	@brief	���� ������
*	@pre	data �� this�� �ʱ�ȭ�Ǿ��־���Ѵ�
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�������� ���� ���������� ���ƾ� true �׿ܿ� false
*/
	bool operator==(const FolderType& data)
	{
		if (Foldername == data.Foldername && Motherfolder == data.Motherfolder)
			return true;
		else
			return false;
	}
	/**
*	@brief	�����ȿ� �ִ� ������ ���
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void DisplayFolders();
	/**
*	@brief	���� ������ ���� ���� ���ϴ� ���������� �ּҰ��� ��ȯ�ϴ� �Լ�
*	@pre	���������� �־����.
*	@post	x
*	@param	str �̵��ϰ����ϴ� ���������� �̸�
*	@return	���������� �ּҰ�
*/
	FolderType* ReturnSubFolder(string str);


};
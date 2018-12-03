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
	};		//�⺻ ������
	~ManageType() {};
	void setPtr(MusicType* P)
	{
		mptr = P;
	}		//�⺻ �Ҹ���
	/**
*	@brief	musictype�� �����͸� get�Ѵ�
*	@pre	mptr�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	x
*	@return	�� managetype�� �������ִ� MusicList�� Ư�������� �ּҰ�
*/
	MusicType* getPtr()
	{
		return mptr;
	}
	/**
*	@brief	�� ManageType�� �����ó�� ǥ���ϴ� �Լ�
*	@pre	x
*	@post	Isdeleted�� true�� �ǰ� mptr�� NULL�� ����Ű�� �ȴ�
*	@param	x
*	@return	x
*/
	void Deleted()
	{
		Isdeleted = true;
		mptr = NULL;
	}
	/**
*	@brief	musictype�� Index�� �޾ƿ´�.
*	@pre	mptr�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	x
*	@return	musictype�� index��
*/
	int getIndex()
	{
		if (Isdeleted == false)
		{
			return (mptr->GetNum());
		}
	}
	/**
*	@brief musictype�� name�� �޾ƿ´�.
*	@pre	mptr�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	x	
*	@return	musictype�� name��
*/
	string getName()
	{	if(Isdeleted == false)
		return mptr->GetName();
	}
	/**
*	@brief	musictype�� primarykey�� �޾ƿ´�
*	@pre	mptr�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	x	
*	@return	x
*/
	string getPkey()
	{	if(Isdeleted == false)
		return mptr->GetPkey();
	}
	/**
*	@brief	musicType�� �̸��� index(track number)�� ����Ѵ�
*	@pre	mptr�� �ʱ�ȭ�Ǿ��־���ϰ� Isdeleted�� false�����Ѵ�.
*	@post	x
*	@param	x
*	@return	Isdeleted�� true�� false Isdeleted�� false�� true
*/
	bool PrintNameNIndex();
	/**
*	@brief	����������
*	@pre	data�� this�� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	data ���ϰ��� �ϴ� data
*	@return	�� managatype�� ��� �����Ͱ� ���� �������� �ʾ�����쿡�� true
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


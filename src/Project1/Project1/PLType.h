#pragma once
#include"ManageType.h"
#include"UnSortedLinkedList.h"
class PLType {
private:

	UnSortedLinkedList<ManageType*> PlayList;
	string PLname;
	int length;
public:
	PLType() { length = 0; PLname = ""; }		//�⺻ ������
	~PLType() {}		//�⺻ �Ҹ���
	/**
*	@brief	���� ������
*	@pre	x
*	@post	x
*	@param	data �����ϰ��� �ϴ� �����Ͱ�
*	@return	x
*/
	PLType(const PLType& data);	
	/**
*	@brief	�������� �̸��� set�Ѵ�
*	@pre	x
*	@post	�������� �̸��� set�ȴ�
*	@param	N �������� �̸�
*	@return	x
*/
	void setPLname(string N)
	{
		PLname = N;
	}
	/**
*	@brief	�������� �̸��� �޾ƿ´�
*	@pre	�������� �̸��� �ʱ�ȭ�Ǿ��־���Ѵ�.
*	@post	x
*	@param	x	
*	@return	�������̸�
*/
	string getPLname()
	{
		return PLname;
	}
	/**
*	@brief	�����Ͼȿ� ���� �߰��Ѵ�.
*	@pre	x
*	@post	�����Ͼȵ� ManagaType*�� �߰��ȴ�.
*	@param	data �߰��ϰ����ϴ� ManageType�� �ּҰ�
*	@return	x
*/
	void AddListinList(ManageType* data)
	{
		PlayList.Add(data);
		length++;
	}
	/**
*	@brief	�����Ͼ��� ��� ���� ����Ѵ�
*	@pre	x
*	@post	x
*	@param	x
*	@return	x
*/
	void Printall();



};

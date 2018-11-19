#pragma once
#ifndef _DOUBLY_ITER2_H
#define _DOUBLY_ITER2_H
#include"DoublyIter2.h"

template <typename T>
struct NodeType2 {
	T data; //�� ����� ������
	NodeType2* next;// ����� ������ ����ų ������
	NodeType2* pre;
};
template<typename T>
class DoublyIter2;
/*
*	@bried �� Ŭ������ �����Ƽ�帵ũ�帮��Ʈ
*/
template<typename T>
class UnSortedLinkedList
{
	friend class DoublyIter2<T>;
public:
	/**
*	default constructor.
*/
	UnSortedLinkedList();

	/**
	*	destructor.
	*/
	~UnSortedLinkedList();
	/**
	*	@brief	���� ���縦 ���� UnSortedLinkedList�� ���� ������
	*	@pre	anotherList�� �ʱ�ȭ�Ǿ� �־���Ѵ�.
	*	@post	anotherList�� ���� ������ ���� ����Ʈ�� �����ȴ�
	*	@param	anotherList �����ϰ��� �ϴ� UnSortedLinkedList
	*/
	UnSortedLinkedList(const UnSortedLinkedList<T>& anotherList);
	/**
	*	@brief	��ũ�� ����Ʈ�� ��� ��带 �����Ѵ�.
	*	@pre	None.
	*	@post	����Ʈ�� �������.

	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���� = ������ ���� �� ������
	*	@pre	x
	*	@post	���ϰ��� ����Ʈ�� ���̰� �ȴ�
	*	@return	����Ʈ�� ���� = ������ ����
	*/
	int GetLength()
	{
		return m_nLength;
	}
	/**
	*	@brief	���ο� ����� ���� ���Ͽ� �´� ��ġ�� �߰��Ѵ�
	*	@pre	List is not Full(�޸𸮿� �� ������ �־�� �Ѵ�)
	*	@post	����Ʈ�� �������� �߰��ȴ�.
	*	@return	�߰��Ǹ� 1 �ƴϸ� 0
	*	@param �߰��ϰ��� �ϴ� �����Ͱ�
	*/
	int Add(T& data);
	/**
	*	@brief	�Է��� ������ ���� ������ ���� ����Ʈ�� ���Ҹ� ����Ʈ���� �����Ѵ�
	*	@pre	����Ʈ�� ������� �ʾƾ��Ѵ�.
	*	@post	����Ʈ�� ���Ұ� �����ǰ� ���̰� ª������.
	*	@return	���������� 1 �ƴϸ� 0
	*	@param data �����ϰ��� �ϴ� �����Ͱ�
	*/
	int Delete(T& data);
	/**
	*	@brief	����Ʈ���� ������ �ٲ۴�
	*	@pre	����Ʈ�� �ϳ��̻��� ���Ұ� �־���Ѵ�.
	*	@post	����Ʈ���� ������ ������ �ٲ��
	*	@return	�۵������� 1 �ƴϸ� 0
	*/
	int Replace(T& data);
	/**
	*	@brief	����Ʈ���� Primarykey�� �������� ��ġ�ϴ� ���Ҹ� �޾ƿ´�
	*	@pre	����Ʈ���� ������ �ʱ�ȭ���־�� �Ѵ�
	*	@post	Ű�� �´� ������ ������ �װ��� �޾ƿ´�..
	*	@return	ã�ƿ����� 1, ��ã������ 0
	*/
	int Get(T& item);
	/**
	*	@brief	����Ʈ�� ����ִ����� Ȯ���Ѵ�.
	*	@pre	x
	*	@post	x
	*	@return ������� 1, �ƴϸ� 0
	*/
	bool IsEmpty() const
	{
		if (m_nLength == 0)
			return true;
		else
			return false;
	}

	/**
	*	@brief	���� �����ڸ� �̿��� ���� ������
	*	@pre	anotherList�� ���ǵǾ� �־���Ѵ�.
	*	@post	���� ����� ����Ʈ�� ���Եȴ�.
	*	@return ����� ����Ʈ
	*/
	UnSortedLinkedList<T> operator=(const UnSortedLinkedList<T> &anotherList);

private:
	NodeType2<T> *m_pList;
	NodeType2<T> *m_pLast;
	int m_nLength;
};



//�Լ� ���Ǻ�
template<typename T>
UnSortedLinkedList<T>::UnSortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;


}
template<typename T>
UnSortedLinkedList<T>::~UnSortedLinkedList()
{
	MakeEmpty();//�޸𸮴����� �������� ����� �����͸� ��� �����Ѵ�

}
template<typename T>
void UnSortedLinkedList<T>::MakeEmpty()
{
	NodeType2<T> *tempptr;
	DoublyIter2<T> iter(*this);
	while (iter.NotNull())
	{
		tempptr = iter.CurPointer;
		iter.Next();
		delete tempptr;
	}	//����Ʈ���� ��� ��带 ����
	m_pList = NULL;
	m_pLast = NULL;
	m_nLength = 0;
}

template<typename T>
int UnSortedLinkedList<T>::Add(T &data)
{



	NodeType2<T> *Node = new NodeType2<T>;
	NodeType2<T> *Pre;
	DoublyIter2<T> iter(*this);
	bool Found = false;
	T dummy;


	Node->data = data;
	Node->next = NULL;
	Node->pre = NULL;
	if (IsEmpty())	//������� ���
	{
		m_pList = Node;
		m_pLast = m_pList;
		m_nLength++;	//���������� �߰������Ƿ� ���̸� �÷��ش�
	}
	//list�� ��尡 �������
	else
	{
		while (1)
		{

			//Pre = m_pCurPointer;	//���� ��带 ����Ű�� ������ ����, ù ������ m_pList�� ����Ʈ�� ù�κ��̴�
			Pre = iter.CurPointer;

			

			//Node �����Ͱ� ������ ��带 ����Ű�� �� �ڿ� Node�� �����Ѵ�.
			if (iter.CurPointer->next == NULL)
			{
				iter.CurPointer->next = Node;
				Node->pre = iter.CurPointer;
				m_pLast = Node;
				m_nLength++;
				break;

			}
			iter.Next();


		}




	}


	return 1;
}

template<typename T>
int UnSortedLinkedList<T>::Delete(T& data)
{
	bool MoreToSearch, found;
	NodeType2<T> *Pre = NULL;
	DoublyIter2<T> iter(*this);

	found = false;
	MoreToSearch = iter.NotNull();

	while (MoreToSearch && !found)
	{
		if (data == iter.CurPointer->data) //���� ����Ű�� ���Ұ� �з����ͷ� ���� ���� ������?
		{
			found = true;	//ã�����Ƿ� found = true
			if (Pre == NULL)	//ã�� �׸��� ù��° �����ϰ��
			{
				NodeType2<T>* temp = iter.CurPointer;		//ù��° ������ �������Ҹ� ������ �ӽ� �����ͼ���
				delete m_pList;	//ù���Ҹ� �����Ѵ�.
				temp->pre = NULL;
				m_pList = temp; //ã�� �׸��� ù �׸��ϰ�� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.

			}
			else
			{

				Pre->next = iter.CurPointer->next;
				iter.CurPointer->next->pre = Pre;
				delete iter.CurPointer;
			}



		}
		else
		{
			Pre = iter.CurPointer;
			iter.Next();
			MoreToSearch = (iter.NotNull());

		}	//�� ã����� m_CurPointer�� ���� ���Ҹ� ����Ų��. �� Pre�� ������Ҹ� ����Ų��.	
	}

	if (found) //ã���� ���
	{
		m_nLength--;
		return 1;

	}
	else    //�� ã����	
		return 0;



}

template<typename T>
int UnSortedLinkedList<T>::Replace(T& data)
{
	bool MoreToSearch, found;
	NodeType2<T> *location;

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL);

	while (MoreToSearch && !found) //����Ʈ�� ���� �ƴϸ鼭 ���� ��ã����� �ݺ��Ѵ�
	{
		if (data == location->data) //��ġ�ϴ� ��츦 ã����
		{
			found = true;
			location->data = data;
		}		//ã�����Ƿ� found �� true���ǰ� �ش���ġ�� data���� �ִ´�
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);	//����Ʈ�� ���� �ƴҰ�� ���ã�´�.

		}	//ã�� ������ �� ���� location���� �ű��.

	}

	if (found) //ã���� ���
	{
		return 1;

	}
	else
		return 0;		//�� ã��

}

template<typename T>
int UnSortedLinkedList<T>::Get(T& data)
{
	bool MoreToSearch, found;
	NodeType2<T>* location;

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL);

	while (MoreToSearch && !found)
	{
		if (data == location->data)		//��ġ�ϴ� �׸��� ã����
		{
			found = true;
			data = location->data;
		}
		else
		{

			location = location->next;	//��ã���� ������ġ�� �δ�
			MoreToSearch = (location != NULL); //������ġ�� �������� �ƴҰ�� ��� ã�´�.
		}

	}
	if (found) //ã������
		return 1;
	else //�� ã������
	{
		return 0;
	}



}










template<typename T>
UnSortedLinkedList<T>::UnSortedLinkedList(const UnSortedLinkedList<T>& anotherList)
{
	NodeType2<T> *m_pCurPointer;
	m_pList = NULL;
	m_pCurPointer = NULL;
	if (anotherList.m_pList == NULL)
		return;
	else {
		this->m_nLength = anotherList.m_nLength;

		NodeType2<T> *Node1 = new NodeType2<T>;
		NodeType2<T> *preNode;
		NodeType2<T> *Node2;
		m_pList = Node1;
		Node1->data = anotherList.m_pList->data;
		Node1->pre = NULL;
		Node2 = anotherList.m_pList->next;

		while (Node2 != NULL)
		{
			Node1->next = new NodeType2<T>;
			preNode = Node1;
			Node1 = Node1->next;
			Node1->data = Node2->data;
			Node1->pre = preNode;
			Node2 = Node2->next;


		}
		Node1->next = NULL;

	}


}

template<typename T>
UnSortedLinkedList<T> UnSortedLinkedList<T>::operator=(const UnSortedLinkedList<T> &anotherList)
{
	MakeEmpty();
	UnSortedLinkedList<T> temp(anotherList);

	return temp;

}


#endif // !_SORTED_LINKED_LIST_H
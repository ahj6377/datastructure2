#pragma once
#ifndef _UN_SORTED_LINKED_LIST_H
#define _UN_SORTED_LINKED_LIST_H
#include"UnSortedLinkedList.h"


template<typename T>
class UnSortedLinkedList;

template<typename T>
struct NodeType2;



template<typename T>
class DoublyIter2 {
	friend class UnSortedLinkedList<T>;

private:
	const UnSortedLinkedList<T>& m_List;
	NodeType2<T>* CurPointer;
public:
	DoublyIter2(const UnSortedLinkedList<T>& list) : m_List(list), CurPointer(list.m_pList)
	{}
	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	���� ��� �������� ���� ��尡 null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NextNotNull();
	/**
	*	@brief	���� ��� �������� ���� ��尡 null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool PrevNotNull();
	/**
	*	@brief	Get first data of the list.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the first node.
	*	@return	Return first data of the list.
	*/
	T First();

	/**
	*	@brief	Get next data of the current pointer.
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to the next node.
	*	@return	Return next data of the list.
	*/
	T Next();

	/**
	*	@brief	Get current data of the list and go to the next node. ���� ���. ��ü��ȯ�� return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data of the list.
	*/
	NodeType2<T> GetCurrentNode();
	/**
	*	@brief	���� ����� data�� �ּҰ��� ��ȯ�ϴ� �Լ�
	*	@pre	Iterator has been initialized.
	*	@post	x
	*	@return	Return current data's address
	*/
	T* GetCurrentPtr();
	/**
	*	@brief	������ �������� �����͸� �޴´�.
	*	@pre	Iterator has been initialized.
	*	@post	x
	*	@return	Return last data of the list.
	*/
	T Last();
	/**
	*	@brief	Curpointer�� ���� ���� ����
	*	@pre	Iterator has been initialized.
	*	@post	���� ���� �����Ͱ� �̵��Ѵ�
	*	@return	Return Prev data of the list.
	*/
	T Prev();



};



// ���� ���Ұ� null���� �˻�
template <typename T>
bool DoublyIter2<T>::NotNull() {
	if (CurPointer == NULL) {
		return false;
	}
	else return true;
}

// ���� ���Ұ� null���� �˻�
template <typename T>
bool DoublyIter2<T>::NextNotNull() {
	if (CurPointer->next == NULL) {

		return false;
	}
	else
		return true;
}

template<typename T>
bool DoublyIter2<T>::PrevNotNull()
{
	if (CurPointer->Prev == NULL)
		return false;
	else
		return true;

}
// ù ��° node
template <typename T>
T DoublyIter2<T>::First() {
	if (!m_List.IsEmpty()) {
		CurPointer = m_List.m_pFirst;
		return CurPointer->data;
	}
}

// ���� node�� �̵� �� item�� return.
template <typename T>
T DoublyIter2<T>::Next() {
	T output = CurPointer->data;
	if (NotNull()) {
		CurPointer = CurPointer->next;
	}
	return output;
}
template<typename T>
T DoublyIter2<T>::Last()
{
	if (!m_List.IsEmpty()) {
		CurPointer = m_List.m_pLast;
		return CurPointer->data;
	}


}
template<typename T>
T DoublyIter2<T>::Prev()
{
	T output = CurPointer->data;
	if (NotNull()) {
		CurPointer = CurPointer->pre;
	}
	return output;


}
// ���� node�� return
template <typename T>
NodeType2<T> DoublyIter2<T>::GetCurrentNode() {
	if (CurPointer != NULL) {
		return *CurPointer;
	}
}
template<typename T>
T* DoublyIter2<T>::GetCurrentPtr()
{
	if (CurPointer != NULL)
	{
		return &(CurPointer->data);
	}

}

#endif // !_DOUBLY_ITER2_H
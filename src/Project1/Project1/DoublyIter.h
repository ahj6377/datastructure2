#pragma once
#ifndef _SORTED_LINKED_LIST_H
#define _SORTED_LINKED_LIST_H
#include"SortedLinkedList.h"


template<typename T>
class SortedLinkedList;

template<typename T>
struct NodeType;



template<typename T>
class DoublyIter {
	friend class SortedLinkedList<T>;

private:
	const SortedLinkedList<T>& m_List;
	NodeType<T>* CurPointer;
public:
	DoublyIter(const SortedLinkedList<T>& list) : m_List(list), CurPointer(list.m_pList)
	{}
	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NotNull();

	/**
	*	@brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator has been initialized.
	*	@post	None.
	*	@return	nullptr true, otherwise false.
	*/
	bool NextNotNull();
	/**
	*	@brief	현재 노드 포인터의 이전 노드가 null인지 아닌지 판단하는 메서드.
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
	*	@brief	Get current data of the list and go to the next node. 현재 노드. 객체반환은 return by value
	*	@pre	Iterator has been initialized.
	*	@post	Current pointer is moved to next node.
	*	@return	Return current data of the list.
	*/
	NodeType<T> GetCurrentNode();
	/**
	*	@brief	현재 노드의 data의 주소값을 반환하는 함수
	*	@pre	Iterator has been initialized.
	*	@post	x
	*	@return	Return current data's address
	*/
	T* GetCurrentPtr();
	/**
	*	@brief	마지막 데이터의 포인터를 받는다.
	*	@pre	Iterator has been initialized.
	*	@post	x
	*	@return	Return last data of the list.
	*/
	T Last();
	/**
	*	@brief	Curpointer의 이전 노드로 간다
	*	@pre	Iterator has been initialized.
	*	@post	이전 노드로 포인터가 이동한다
	*	@return	Return Prev data of the list.
	*/
	T Prev();



};



// 현재 원소가 null인지 검사
template <typename T>
bool DoublyIter<T>::NotNull() {
	if (CurPointer == NULL) {
		return false;
	}
	else return true;
}

// 다음 원소가 null인지 검사
template <typename T>
bool DoublyIter<T>::NextNotNull() {
	if (CurPointer->next == NULL) {

		return false;
	}
	else 
		return true;
}

template<typename T>
bool DoublyIter<T>::PrevNotNull()
{
	if (CurPointer->Prev == NULL)
		return false;
	else
		return true;

}
// 첫 번째 node
template <typename T>
T DoublyIter<T>::First() {
	if (!m_List.IsEmpty()) {
		CurPointer = m_List.m_pFirst;
		return CurPointer->data;
	}
}

// 다음 node로 이동 후 item을 return.
template <typename T>
T DoublyIter<T>::Next() {
	T output = CurPointer->data;
	if (NotNull()) {
		CurPointer = CurPointer->next;
	}
	return output;
}
template<typename T>
T DoublyIter<T>::Last()
{
	if (!m_List.IsEmpty()) {
		CurPointer = m_List.m_pLast;
		return CurPointer -> data;
	}


}
template<typename T>
T DoublyIter<T>::Prev()
{
	T output = CurPointer->data;
	if (NotNull()) {
		CurPointer = CurPointer->prev;
	}
	return output;


}
// 현재 node를 return
template <typename T>
NodeType<T> DoublyIter<T>::GetCurrentNode() {
	if (CurPointer != NULL) {
		return *CurPointer;
	}
}
template<typename T>
T* DoublyIter<T>::GetCurrentPtr()
{
	if (CurPointer != NULL)
	{
		return &(CurPointer->data);
	}

}

#endif // !_DOUBLY_ITER_H
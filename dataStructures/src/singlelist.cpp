#include "singlelist.h"


//template<typename T>
//int SingleList<T>::getSize() const
//{
//  return size;
//}
//template<typename T>
//SingleList<T>::SingleList()
//{

//  this->size=0;
//  this->head=nullptr;
//  this->tail=nullptr;

//}
//template<typename T>
//SingleList<T>::SingleList(Node<T>* newNode)
//{


//}

//template<typename T>
//Node<T>*SingleList<T>::front()
//{
//  return this->head;
//}

//template<typename T>
//Node<T>*SingleList<T>::back()
//{
//  return this->tail;
//}

//template<typename T>
//Node<T>*SingleList<T>::begin()
//{
//  return this->head;

//}

//template< typename T>
//void SingleList<T>::push_front(T a)
//{
//    Node<T>* newNode = new Node<T>(a);

//    if(this->size == 0){
//      this->head = newNode;
//      this->size++;
//      this->tail = this->head;

//    }else{

//      Node<T>* tmp;
//      tmp = this->head;
//      head = newNode;
//      head->next = tmp;
//      this->size++;
//    }



//}

//template<typename T>
//bool SingleList<T>::empty() const
//{
//    if(size == 0)
//      return true;
//    else
//      return false;
//}

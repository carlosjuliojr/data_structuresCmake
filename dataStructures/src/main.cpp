
#include "singlelist.h"
#include <iostream>

using namespace std;
int main()
{


 SingleList<int>* myList = new SingleList<int>;

  myList->push_back(50);
  myList->push_front(100);
    myList->push_back(20);

Node<int>* it = myList->begin();
  for(int i = 0 ; i < myList->getSize(); i++){

    cout<< it->data<< " => ";
    it= it->next;
  }



  //nota que retornar si el begin es null para que no de error??

  myList->pop_back();
    myList->pop_back();
  cout<<"size: " << myList->getSize() <<"\nlast element: "<<myList->back();
   myList->pop_back();


   it = myList->begin();
    for(int i = 0 ; i < myList->getSize(); i++){

      cout<< it->data<< " => ";
      it= it->next;
    }


  return 0;
}

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include<iostream>


template< typename T>
struct Node {

    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T a) : data(a), next(nullptr), prev(nullptr) {}
    T getData() const{ return data;}


};


template <typename T>
class DoublyList
{
  private:

    int size;
    Node<T>* head;
    Node<T>* tail;




  public:

    /**
     * @brief DoublyList
     */
    DoublyList() {

      this->size = 0;
      this->head= nullptr;
      this->tail = nullptr;

    }

    /**
     * @brief begin
     * @return
     */
    Node<T>* begin() const
    {
      return this->head;
    }

    /**
     * @brief end
     * @return
     */
    Node<T>* end() const
    {
      return this->tail;
    }

    /**
     * @brief empty
     * @return
     */
    bool empty()const
    {
      return  (this->size == 0) ? true : false;
    }

    /**
      * @brief fron
      * @return
      */
    T front() const
    {
      return this->head->data;
    }

    /**
      * @brief back
      * @return
      */
    T back() const
    {
      return this->tail->data;
    }
    /**
     * @brief push_front
     * @param a
     */
    const void push_front(const T& a)
    {

      Node<T>* newNode = new Node<T>(a);


      if(this->size == 0){

        this->tail = newNode;

      }else{

        Node<T>* tmp = this->head;
        tmp->prev = newNode;
        newNode->next = tmp;

      }

      this->head = newNode;
      this->size++;
    }

    /**
     * @brief push_back
     * @param a
     */
    void push_back(const T &a){

      Node<T>* newNode = new Node<T>(a);


      if(this->size == 0){

        this->head = newNode;

      }else{

        Node<T>* tmp = this->tail;
        tmp->next = newNode;
        newNode->prev = tmp;

      }

      this->tail = newNode;
      this->size++;
    }
    /**
     * @brief print
     */
    void print(){

      Node<T>* it = this->begin();
      while(it != nullptr){

        std::cout<< it->data << " => ";
        it= it->next;
      }

    }


    int getSize() const {

      return this->size;
    }

    /**
      * @brief pop_front
      */
    void pop_front(){


      if(this->size ==1){


        delete this->head;
        this->head= nullptr;
        this->tail= nullptr;

        this->size--;
      }else if (this->size > 1){

        Node<T>* tmp = this->head->next;
        delete this->head;
        this->head = tmp;
        this->head->prev=nullptr;
        this->size--;

      }else
        return;

    }

    /**
      * @brief pop_back
      */
    void pop_back(){

      if(this->size ==1){

        delete this->head;
        this->head= nullptr;
        this->tail= nullptr;
        this->size--;
      }else if (this->size > 1){

        Node<T>* tmp = this->tail->prev;
        delete this->tail;
        this->tail = tmp;
        this->tail->next=nullptr;
        this->size--;

      }else

        return;

    }

    /**
      * @brief erase
      * @param iterator
      * @return
      */

    Node<T>* erase(Node<T>* iterator){

      Node<T>* it = begin();

      Node<T>* tmp = it->next;

      if(iterator == this->head){

        delete head;
        this->head = tmp;
        this->size--;
        return this->head;

      }

      while( it != nullptr){

        if(it == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

        tmp = it->next;
        Node<T>* prev = it->prev;

        if(tmp != nullptr){

          delete it;
          prev->next = tmp;
          tmp->prev = prev;
          this->size--;
          return tmp;
        }else{

          this->tail = it->prev;
          delete it;
          this->tail->next = nullptr;
          this->size--;
          return tail;
        }

      }else{
        return nullptr;
      }

    }

    /**
      * @brief remove
      * @param val
      */
    void remove(T  val){

      Node<T>* it = this->head;

      while(it != nullptr){

        if(it->data == val){

          if(it == this->head){

            if(it->next != nullptr){

              Node<T>* tmp = this->head->next;
              delete head;
              this->head = tmp;
              this->head->prev= nullptr;
              it = it->next;
            }else{

              delete head;
              this->head = nullptr;
              this->tail = nullptr;
              it = this->head;
            }
            this->size--;
          }else{

            Node<T>* prev = it->prev;
            Node<T>* next = it->next;
            if(it->next != nullptr){

              delete it;
              prev->next=next;
              next->prev=prev;
              it=prev;
            }else{

              this->tail = prev;
              tail->next= nullptr;
              delete it;
              it =this->tail;
              std::cout<<it->data;
            }
            this->size--;
            it = it->next;
          }
        }else
          it = it->next;
      }
    }

    /**
     * @brief insert
     * @param node
     * @param val
     */
    void insert(Node<T>* node, T val){


      Node<T>* it = this->begin();
      Node<T>* newNode = new Node<T>(val);
      while(it != node){
        it = it->next;
      }

      if(it == this->head){
        if(it->next == nullptr){
          push_back(val);
        }else{

          Node<T>* next = it->next;
          it->next = newNode;
          newNode->prev=it;
          next->prev= newNode;
          newNode->next=next;
          this->size++;


        }

      }else if( it == this->tail){
        push_back(val);

      }else{
        Node<T>* next = it->next;
        it->next = newNode;
        newNode->prev=it;
        next->prev= newNode;
        newNode->next=next;
        this->size++;
      }
    }

};







#endif // DOUBLYLIST_H

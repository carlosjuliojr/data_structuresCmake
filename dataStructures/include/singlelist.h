#ifndef SINGLELIST_H
#define SINGLELIST_H
#include <iostream>

template<typename T>
struct Node{
    T data;
    Node* next;


    Node(T a) : data(a), next(nullptr) {}
    T getData() const{ return data;}

};


template<typename T>
class SingleList
{
  private:

    Node<T>* iterator;
    int size;
    Node<T>* head;
    Node<T>* tail;

  public:
    /**
    * @brief SingleList
    */
    SingleList()
    {

      this->size=0;
      this->head=nullptr;
      this->tail=nullptr;

    }

    SingleList(Node<T>*);

    /**
    * @brief front
    * @return
    */
    T front() const
    {
      T a;

      if(this->size == 0){
        return a;
      }

      return this->head->data;
    }

    /**
    * @brief back
    * @return
    */
    T back() const
    {

      T a;

      if(this->size == 0){
        return a;
      }

      return this->tail->data;
    }

    /**
    * @brief begin
    * @return
    */
    Node<T>* begin() const
    {
      return this->head;
    }

    Node<T>* end() const
    {
      return this->tail;
    }

    /**
    * @brief push_back
    * @param a
    */
    void push_back(const T a){

      Node<T>* newNode = new Node<T>(a);

      if(this->size == 0){
        this->head = newNode;
        this->size++;
        this->tail = this->head;

      }else{

        Node<T>* tmp;
        tmp = this->tail;
        tmp->next = newNode;
        tail = newNode;
        this->size++;
      };


    }

    /**
    * @brief push_front
    * @param a
    */
    void push_front(const T a)
    {

      Node<T>* newNode = new Node<T>(a);

      if(this->size == 0){
        this->head = newNode;
        this->size++;
        this->tail = this->head;

      }else{

        Node<T>* tmp;
        tmp = this->head;
        head = newNode;
        head->next = tmp;
        this->size++;
      }

    }

    /**
    * @brief empty
    * @return
    */
    bool empty() const
    {
      if(size == 0)
        return true;
      else
        return false;
    };

    /**
    * @brief getSize
    * @return
    */
    int getSize() const{
      return size;
    }

    /**
    * @brief pop_front
    */
    void pop_front(){

      if(this->size == 0){
        return;
      }else if(this->size == 1){

        this->size--;
        delete head;
        this->head= nullptr;
        this->tail= nullptr;


      }else{

        Node<T>* tmp = this->head->next;
        delete head;
        head = tmp;
        this->size--;

      }

    }

    /**
    * @brief pop_front
    */
    void pop_back(){

      if(this->size == 0){
        return;
      }else if(this->size == 1){


        this->size--;
        delete head;


      }else{

        Node<T>* tmp = head;
        while(tmp->next != tail){
          tmp = tmp->next;
        }


        delete tail;
        tail = tmp;
        tail->next =  nullptr;
        this->size--;

      }

    }

    /**
     * @brief insert
     * @param iterator
     * @param n
     * @param val
     */

    void insert(Node<T>* iterator, int n, T val){

      Node<T>* it = begin();

      while( it != nullptr){

        if(it == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

        if(it->next == nullptr){

          for (int var = 0; var < n; ++var) {
            push_back(val);
          }

        }else{
          Node<T>* tmp = it->next;

          for (int var = 0; var < n; ++var) {

            Node<T>* newNode = new Node<T>(val);
            it->next = newNode;
            newNode->next=tmp;
            tmp = it->next;
            this->size++;

          }
        }

      }

    }

    /**
     * @brief insert
     * @param iterator
     * @param val
     */
    void insert(const Node<T>* iterator, T val){

      Node<T>* it = begin();

      while( it != nullptr){

        if(it == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

        if(it->next == nullptr){

          push_back(val);

        }else{
          Node<T>* tmp = it->next;


          Node<T>* newNode = new Node<T>(val);
          it->next = newNode;
          newNode->next=tmp;
          tmp = it->next;
          this->size++;

        }

      }

    }

    /**
     * @brief erase
     * @param it
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

        if(it->next == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

        tmp = it->next->next;

        if(tmp != nullptr){

          delete it->next;
          it->next = tmp;
          this->size--;
          return it;
        }else{

          this->tail = it;
          delete it->next;
          this->size--;
          return it;
        }

      }else{
        return nullptr;
      }

    }

    /**
   * @brief remove
   * @param val
   */
    void remove (const T& val){

      Node<T>* it = begin();
      Node<T>* tmp;
      Node<T>* prev = it;


      while (it != nullptr) {

        if(it->data == val){
          if(it == this->head){
            prev=it;
            tmp = it->next;

            if (it->next != nullptr) {

              delete it;
              this->head = tmp;
              this->size--;

            }else{

              delete it;
              this->head = nullptr;
              this->tail = nullptr;
              this->size--;

            }
            it = tmp;


          }else{

            if(it->next != nullptr){

              tmp = it->next;
              delete it;
              it = tmp;
              prev->next=tmp;



              this->size--;


            }else{

              tail = prev;
              delete it;
              tail->next=nullptr;
              this->size--;
              //                  it = prev;
            }

          }
        }else{
          prev = it;
          it = it->next;
        }
      }
    }

};

#endif // SINGLELIST_H

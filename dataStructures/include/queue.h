#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Node{
    T data;
    Node* next;


    Node(T a) : data(a), next(nullptr) {}
    T getData() const{ return data;}

};

/**
 *
 */
template<typename T>
class Queue
{
  private:

    int size;
    Node<T>* head;
    Node<T>* tail;

  public:
    /**
    * @brief SingleList
    */
    Queue()
    {

      this->size=0;
      this->head=nullptr;
      this->tail=nullptr;

    }
    /**
     * @brief Queue
     */
    Queue(Node<T>*);

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

      return this->head->data;
    }

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

      return this->tail->data;
    }

    /**
    * @brief begin
    * @return
    */
    Node<T>* end() const
    {
      return this->head;
    }

    Node<T>* begin() const
    {
      return this->tail;
    }

    /**
    * @brief push_front
    * @param a
    */
    void push(const T a)
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
    }

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
    void pop(){

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
     * @brief swap
     * @param x
     * @param y
     */
    void  swap(Queue<T>* y){

      int  sizeX = this->getSize();

      while(y->getSize() != 0){

        this->push(y->front());
        y->pop();
      }

      int z = 1 ;


        while (z <= sizeX){

              y->push(this->front());
              this->pop();
            z++;
        }
    }

};




#endif // QUEUE_H

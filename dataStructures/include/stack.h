#ifndef STACK_H
#define STACK_H


template<typename T>
struct Node{

    T data;
    Node* next;

    Node(T a) : data(a), next(nullptr) {}
    T getData() const{ return data;}

};


template<typename T>
class Stack
{

  private:

    int size;
    Node<T>* top;



  public:
    /**
     * @brief Stack
     */
    Stack(): size(0), top(nullptr) {}

    bool empty(){
//      return (this->size == 0 ) ? true : false;

      if(this->size == 0 ){
        return true;
      }else
        return false;
    }

    /**
     * @brief push
     * @param node
     */
    void push(T node){

      Node<T>* newNode = new Node<T>(node);

      if(this->size == 0){

        this->top = newNode;

      }else{

        Node<T>* tmp ;
        tmp = this->top;
        this->top = newNode;
        this->top->next = tmp;

      }
      this->size++;
    }

    /**
     * @brief pop
     */
    void  pop(){

      if(this->size == 0){

        return;

      }else if(this->size == 1){

        delete this->top;
        this->size--;

      }else{
        Node<T>* tmp ;
        tmp = this->top->next;
        delete this->top;
        this->top = tmp;
        this->size--;

      }
    }

    /**
     * @brief top
     * @return
     */
    Node<T>* top_stack() const {
      return this->top;
    }

    /**
     * @brief getSize
     * @return
     */
    int getSize() const
    {
    return this->size;
    }

    /**
     * @brief swap
     * @param x
     * @param y
     */
    void static swap(Stack<T>* x, Stack<T>* y){

      Stack<T>* tmpX = new Stack<T>();
//      Stack<T>* tmpY;

      int  sizeX = x->getSize(), sizeY = y->getSize();

      while(x->getSize() != 0){

        tmpX->push(x->top_stack()->data);
        x->pop();

      }


      while(y->getSize() != 0){

        tmpX->push(y->top_stack()->data);
        y->pop();

      }

      int z = 1 ;


        while (z <= sizeX + sizeY){

            if( z <= sizeY){

              x->push(tmpX->top_stack()->data);
            }else{
              y->push(tmpX->top_stack()->data);
            }

            z++;

        }
        delete tmpX;
    }

};

#endif // STACK_H



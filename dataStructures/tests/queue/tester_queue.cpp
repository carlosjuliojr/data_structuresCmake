#include<gtest/gtest.h>
#include"queue.h"


TEST(test1, test_push_back)
{

  Queue<int>* myQueue = new Queue<int>;

  myQueue->push(10);


  ASSERT_EQ(myQueue->front(),10);
  myQueue->push(20);

  ASSERT_EQ(myQueue->front(),10);
  myQueue->push(0);

  ASSERT_EQ(myQueue->back(),0);

  delete myQueue;
}

TEST(test2, test_pop)
{

  Queue<int>* myQueue = new Queue<int>;

  myQueue->push(10);
  myQueue->push(20);
  myQueue->push(0);

  myQueue->pop();

  ASSERT_EQ(myQueue->front(),20);

  myQueue->pop();
  ASSERT_EQ(myQueue->front(),0);

  myQueue->pop();
  ASSERT_TRUE(myQueue->empty());

  delete myQueue;

}

TEST(test3, test_front)
{

  Queue<int>* myQueue = new Queue<int>;

  myQueue->push(10);
  myQueue->push(20);
  myQueue->push(0);


  ASSERT_EQ(myQueue->front(),10);

  myQueue->pop();
  ASSERT_EQ(myQueue->front(),20);

  myQueue->pop();


  ASSERT_EQ(myQueue->front(),0);

  myQueue->pop();
  ASSERT_TRUE(myQueue->empty());

  delete myQueue;

}

TEST(test4, test_back)
{

  Queue<int>* myQueue = new Queue<int>;

  myQueue->push(10);
  myQueue->push(20);
  myQueue->push(0);


  ASSERT_EQ(myQueue->back(),0);

  myQueue->pop();
  ASSERT_EQ(myQueue->back(),0);

  myQueue->pop();


  ASSERT_EQ(myQueue->front(),0);

  myQueue->pop();
  ASSERT_TRUE(myQueue->empty());

  delete myQueue;

}


TEST(test4, test_swap)
{

  Queue<int>* myQueue = new Queue<int>;
  Queue<int>* myQueue2 = new Queue<int>;

  myQueue->push(0);
  myQueue->push(10);
  myQueue->push(20);


  myQueue2->push(1);
  myQueue2->push(2);
  myQueue2->push(3);
  myQueue2->push(4);
  myQueue2->push(5);
  myQueue2->push(6);


  myQueue->swap(myQueue2);

  ASSERT_EQ(myQueue->getSize(),6);

  myQueue->pop();
  ASSERT_EQ(myQueue2->getSize(),3);

  delete myQueue;
  delete myQueue2;
}



//TEST(test4, test_empty)
//{

//  Stack<int>* myStack = new Stack<int>;

//  myStack->push(1);

//  ASSERT_EQ(myStack->top_stack()->data,1);

//  myStack->push(1);
//  myStack->push(2);
//  myStack->push(3);


//  myStack->pop();
//  myStack->pop();
//  myStack->pop();

//  ASSERT_FALSE(myStack->empty());

//  myStack->pop();

//  ASSERT_TRUE(myStack->empty());



//  delete myStack;
//}


//TEST(test4, test_swap)
//{

//  Stack<int>* myStack = new Stack<int>;
//  Stack<int>* myStack2 = new Stack<int>;

//  myStack->push(1);
//  myStack->push(1);
//  myStack->push(2);
//  myStack->push(3);

//  myStack2->push(2);
//  myStack2->push(3);


//  Stack<int>::swap(myStack,myStack2);

//  ASSERT_EQ(myStack->getSize(),2);
//  ASSERT_EQ(myStack2->getSize(),4);



//  delete myStack;
//  delete myStack2;
//}




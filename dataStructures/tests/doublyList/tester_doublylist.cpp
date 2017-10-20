#include<gtest/gtest.h>
#include"../../include/doublylist.h"


TEST(test1, test_push_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_front(4);


  myList->push_front(3);



  ASSERT_EQ(myList->front(),3);
  ASSERT_EQ(myList->back(),4);

  myList->push_front(2);


  ASSERT_EQ(myList->front(),2);
  ASSERT_EQ(myList->back(),4);

  myList->push_front(1);


  ASSERT_EQ(myList->front(),1);
  ASSERT_EQ(myList->back(),4);

  delete myList;

}


TEST(test2, test_empty)
{

  DoublyList<int>* myList = new DoublyList<int>;


  ASSERT_TRUE(myList->empty());

  myList->push_front(4);

  ASSERT_FALSE(myList->empty());


  delete myList;
}

TEST(test3, test_push_back)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);



  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),3);

  myList->push_back(2);


  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),2);

  myList->push_back(1);


  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),1);


  delete myList;
}


TEST(test4, test_back)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);

  ASSERT_EQ(myList->back(),3);

  myList->push_back(2);

  ASSERT_EQ(myList->back(),2);

  myList->push_back(1);

  ASSERT_EQ(myList->back(),1);


  delete myList;
}


TEST(test5, test_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);

  ASSERT_EQ(myList->front(),4);

  myList->push_front(2);

  ASSERT_EQ(myList->front(),2);

  myList->push_front(1);

  ASSERT_EQ(myList->front(),1);


  delete myList;
}


TEST(test6, test_pop_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);


  myList->pop_front();
  ASSERT_EQ(myList->front(),3);


  myList->push_back(4);


  myList->push_back(3);


  myList->pop_front();


  ASSERT_EQ(myList->front(),4);

  myList->pop_front();
  myList->pop_front();

  ASSERT_TRUE(myList->empty());


  delete myList;
}



TEST(test7, test_pop_back)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);
  myList->push_back(3);


  myList->pop_back();
  ASSERT_EQ(myList->front(),4);


  myList->push_back(1);


  myList->push_back(3);


  myList->pop_back();


  ASSERT_EQ(myList->back(),1);

  myList->pop_back();
  myList->pop_back();

  ASSERT_TRUE(myList->empty());


  delete myList;
}


TEST(test8, test_erase)
{

   DoublyList<int>* myList = new DoublyList<int>;

      myList->push_front(4);
      myList->push_front(3);
      myList->push_front(2);
      myList->push_front(1);

      // 1  => 2  => 3  => 4 => null

      Node<int>* it = myList->begin();

      // 1  => 2  => 3  => 4 => null
      // ^
      Node<int>* itReturn = myList->erase(it);

      // 2  => 3  => 4 => null
      // ^
      ASSERT_EQ(itReturn->data,2);




      itReturn = itReturn->next;

      // 2  => 3  => 4 => null
            // ^

      itReturn = myList->erase(itReturn);

      // 2  => 4 => null
            // ^
      ASSERT_EQ(itReturn->data,4);

      it =myList->end();

      // 2  => 4 => null
            // ^

      itReturn = myList->erase(it);

      // 2  => null
      // ^
      ASSERT_EQ(itReturn->data,2);


      // 2  => null
      // ^

      itReturn = myList->erase(itReturn);


      ASSERT_TRUE(myList->empty());

      delete myList;

}


TEST(test9, test_remove)
{

   DoublyList<int>* myList = new DoublyList<int>;

      myList->push_front(4);
      myList->push_front(3);
      myList->push_front(3);
      myList->push_front(1);

      // 1  => 3  => 3  => 4 => null
      // ^
       myList->remove( 1 );
       ASSERT_EQ(myList->begin()->data,3);

        //  3  => 3  => 4 => null
                     // ^
       myList->remove( 4 );

       ASSERT_EQ(myList->begin()->data,3);


       //  3  => 3  => null
        // ^     ^


       myList->remove( 3 );

       ASSERT_TRUE(myList->empty());

      delete myList;

}


TEST(test10, test_insert)
{

   DoublyList<int>* myList = new DoublyList<int>;

      myList->push_front(4);
      myList->push_front(3);


      // 3 => 4 => null
      myList->insert(myList->begin(),-1);


      // 3  => -1 => 4 => null

      ASSERT_EQ(myList->begin()->next->data,-1);

      myList->pop_back();



//      // 3 => -1 => null
      ASSERT_EQ(myList->back(),-1);

      myList->pop_front();
//       // -1 => null
       ASSERT_EQ(myList->front(),-1);

delete myList;

}





#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

#include <gtest/gtest.h>

// //массив всех тестов, который мы заполняем в функции initTests
// static std::vector<std::function<bool()>> tests;
//
// //тест 1
// bool test1()
// {
//   //пример какого-то теста
//   return 42 == (41 + 1); //passed
// }
//
// //тест 2
// bool test2()
// {
//   //пример какого-то теста
//   return 42 != (41 + 1); //failed
// }
//
// //тест 3
// bool test3()
// {
//   Candle candle{ 0.0, 3.0, 3.0, 3.0 };
//
//   //пример какого-то теста
//   return candle.high == 3.0;
// }
//
// void initTests()
// {
//   tests.push_back(test1);
//   tests.push_back(test2);
//   tests.push_back(test3);
//   //tests.push_back(test4);
//   //tests.push_back(test5);
// }
//
// int launchTests()
// {
//   int total = 0;
//   int passed = 0;
//
//   for (const auto& test : tests)
//   {
//     std::cout << "test #" << (total + 1);
//     if (test())
//     {
//       passed += 1;
//       std::cout << " passed\n";
//     }
//     else
//     {
//       std::cout << " failed\n";
//     }
//     total += 1;
//   }
//
//   std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;
//
//   //0 = success
//   return total - passed;
// }

    TEST(growing,body_contains){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.body_contains(500),1);
        EXPECT_EQ(riba.body_contains(400),1);
        EXPECT_EQ(riba.body_contains(600.1),0);
        EXPECT_EQ(riba.body_contains(599.9),1);

    }

    TEST(neutral,body_contains){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.body_contains(0),1);
        EXPECT_EQ(riba.body_contains(-1),0);
    }

    TEST(falling,body_contains){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.body_contains(400),1);
        EXPECT_EQ(riba.body_contains(200),1);
        EXPECT_EQ(riba.body_contains(300),1);
        EXPECT_EQ(riba.body_contains(501),0);
        EXPECT_EQ(riba.body_contains(99),0);
    }

    TEST(growing,contains){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.contains(500),1);
        EXPECT_EQ(riba.contains(400),1);
        EXPECT_EQ(riba.contains(600.1),0);
        EXPECT_EQ(riba.contains(399.9),0);

    }

    TEST(neutral,contains){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.contains(0),1);
        EXPECT_EQ(riba.contains(-1),0);
    }

    TEST(falling,contains){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.contains(400),1);
        EXPECT_EQ(riba.contains(200),1);
        EXPECT_EQ(riba.contains(300),1);
        EXPECT_EQ(riba.contains(501),0);
        EXPECT_EQ(riba.contains(99),0);
    }

    TEST(growing,full_size){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.full_size(),100);
    }

    TEST(neutral,full_size){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.full_size(),0);
    }

    TEST(falling,full_size){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.full_size(),200);
    }

    TEST(growing,body_size){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.body_size(),300);
    }

    TEST(neutral,body_size){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.body_size(),0);
    }

    TEST(falling,body_size){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.body_size(),400);
    }

    TEST(growing,is_green){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.is_green(),1);
    }

    TEST(neutral,is_green){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.is_green(),0);
    }

    TEST(falling,is_green){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.is_green(),0);
    }

    TEST(growing,is_red){
        Candle riba(300,500,400,600);
        EXPECT_EQ(riba.is_red(),0);
    }

    TEST(neutral,is_red){
        Candle riba(0,0,0,0);
        EXPECT_EQ(riba.is_red(),0);
    }

    TEST(falling,is_red){
        Candle riba(500,400,200,100);
        EXPECT_EQ(riba.is_red(),1);
    }

// int main()
// {
//   initTests();
//
//   return launchTests();
// }

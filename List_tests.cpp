// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub)
{
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_list_int_type)
{
    List<int> list;
    ASSERT_TRUE(list.empty() == true);
    ASSERT_TRUE(list.size() == 0);
    list.push_back(42);
    list.push_back(44);
    list.push_back(54);
    list.push_back(34);
    list.push_back(78);
    ASSERT_TRUE(list.front() == 42);
    ASSERT_TRUE(list.back() == 78);
    list.push_front(45);
    list.push_back(56);
    ASSERT_TRUE(list.front() == 45);
    ASSERT_TRUE(list.back() == 56);
    list.pop_front();
    ASSERT_TRUE(list.front() == 42);
    list.pop_front();
    ASSERT_TRUE(list.front() == 44);
    list.pop_front();
    ASSERT_TRUE(list.front() == 54);
    ASSERT_TRUE(list.empty() == false);
    list.pop_back();
    list.clear();
    ASSERT_TRUE(list.empty() == true);
    List<int> list_copy;
    list_copy.push_front(23);
    list_copy.push_front(45);
    list_copy.push_back(34);
    list_copy.push_back(39);
    list_copy.push_front(90);
    List<int> list_2(list_copy);
    ASSERT_TRUE(list_2.front() == 90);
    ASSERT_TRUE(list_2.back() == 39);
    list_2.pop_front();
    ASSERT_TRUE(list_2.front() == 45);
    list_2.pop_back();
    ASSERT_TRUE(list_2.back() == 34);
}

TEST(test_list_testing)
{
    List<double> list;
    ASSERT_TRUE(list.empty() == true);
    ASSERT_TRUE(list.size() == 0);
    list.push_front(43);
    ASSERT_TRUE(list.front() == 43);
    ASSERT_TRUE(list.back() == 43);
    list.pop_back();
    ASSERT_TRUE(list.empty() == true);
    list.push_back(45.5);
    ASSERT_TRUE(list.front() == 45.5);
    ASSERT_TRUE(list.back() == 45.5);
    list.pop_front();
    list.clear();
}

TEST(copy_all_function_test)
{
    List<double> list;
    ASSERT_TRUE(list.empty() == true);
    ASSERT_TRUE(list.size() == 0);
    List<double> listcopy;
    listcopy.push_back(45.5);
    listcopy.push_back(56.8);
    listcopy.push_back(100);
    listcopy.push_back(590.90);
    listcopy.push_front(45);
    ASSERT_TRUE(listcopy.front() == 45.00);
    ASSERT_TRUE(listcopy.back() == 590.90);
    list = listcopy;
    ASSERT_TRUE(list.front() == 45);
    ASSERT_TRUE(list.back() == 590.90);
    list.pop_back();
    ASSERT_TRUE(list.back() == 100);
    list.pop_front();
    ASSERT_TRUE(list.front() == 45.5);
}

TEST(iterator_operations_testing)
{
    List<double> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_back(45);
    list_copy.push_back(50);
    list_copy.push_back(55);
    list_copy.push_back(60);
    list_copy.push_back(65);
    list_copy.push_back(70);
    List<double>::Iterator  it = list_copy.begin();
    ASSERT_TRUE(*it == 45);
    List<double>::Iterator  it1 = list_copy.begin();
    ASSERT_TRUE(*it == 45);
    ASSERT_TRUE(it == it1)
    ++it;
    ASSERT_TRUE(it != it1);
    ASSERT_TRUE(*it == 50);
    ++it1;
    ASSERT_TRUE(it == it1);
    ASSERT_TRUE(*it1 == 50);
    List<double>::Iterator it_end = list_copy.end();
    List<double>::Iterator it1_end = list_copy.end();
    ASSERT_TRUE(it_end == it1_end);
}

TEST(iterator_erase_function)
{
    List<double> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_back(45);
    list_copy.push_back(50);
    list_copy.push_back(55);
    list_copy.push_back(60);
    list_copy.push_back(65);
    list_copy.push_back(70);
    List<double>::Iterator  it = list_copy.begin();
    list_copy.erase(it);
    ASSERT_TRUE(list_copy.front() == 50);
    List<double>::Iterator it1 = list_copy.begin();
    List<double>::Iterator it1_copy = list_copy.begin();
    ASSERT_TRUE(it1 == it1_copy);
    ASSERT_TRUE(*it1 == 50);
    ++it1;
    ASSERT_FALSE(it1 == it1_copy);
    ASSERT_TRUE(*it1 == 55);
    --it1;
    ASSERT_TRUE(*it1 == 50);
    ++it1;
    ++it1;
    ASSERT_TRUE(*it1 == 60);
    list_copy.erase(it1);
    List<double>::Iterator it2 = list_copy.begin();
    ASSERT_TRUE(list_copy.front() == 50);
    ASSERT_TRUE(*it2 == 50);
    ++it2;
    ASSERT_TRUE(*it2 == 55);
    ++it2;
    ASSERT_TRUE(*it2 == 65);
    ++it2;
    ASSERT_TRUE(*it2 == 70);
    list_copy.erase(it2);
    ASSERT_TRUE(list_copy.back() == 65);
    ASSERT_TRUE(list_copy.size() == 3);
}

TEST(iterator_insert_function)
{
    List<int> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_back(3);
    list_copy.push_back(6);
    list_copy.push_back(9);
    list_copy.push_back(12);
    list_copy.push_back(-89);
    list_copy.push_back(90);
    ASSERT_TRUE(list_copy.size() == 6);
    ASSERT_TRUE(list_copy.front() == 3);
    ASSERT_TRUE(list_copy.back() == 90);
    List<int>::Iterator it = list_copy.begin();
    list_copy.insert(it, 43);
    ASSERT_TRUE(list_copy.size() == 7);
    ASSERT_TRUE(list_copy.front() == 43);
    List<int>::Iterator it1 = list_copy.end();
    list_copy.insert(it1, 50);
    ASSERT_TRUE(list_copy.size() == 8);
    ASSERT_TRUE(list_copy.back() == 50);
    List<int>::Iterator it2 = list_copy.begin();
    ASSERT_TRUE(list_copy.size() == 8);
    ASSERT_TRUE(list_copy.front() == 43);
    ASSERT_TRUE(list_copy.back() == 50);
    ASSERT_TRUE(*it2 == 43);
    ++it2;
    ASSERT_TRUE(*it2 == 3);
    ++it2;
    ASSERT_TRUE(*it2 == 6);
    list_copy.insert(it2, 67);
    ASSERT_TRUE(list_copy.size() == 9);
    List<int>::Iterator it3 = list_copy.begin();
    ASSERT_TRUE(*it3 == 43);
    ++it3;
    ASSERT_TRUE(*it3 == 3);
    ++it3;
    ASSERT_TRUE(*it3 == 67);
    ++it3;
    ASSERT_TRUE(*it3 == 6);
    ++it3;
    ASSERT_TRUE(*it3 == 9);
    ++it3;
    ASSERT_TRUE(*it3 == 12);
    ++it3;
    ASSERT_TRUE(*it3 == -89);
    ++it3;
    ASSERT_TRUE(*it3 == 90);
    ++it3;
    ASSERT_TRUE(*it3 == 50);
}

TEST(iterator_push_front_test)
{
    List<double> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_front(3);
    list_copy.push_front(6);
    list_copy.push_front(9);
    list_copy.push_front(12);
    list_copy.push_front(-89);
    list_copy.push_front(90);
    ASSERT_TRUE(list_copy.size() == 6);
    ASSERT_TRUE(list_copy.front() == 90);
    ASSERT_TRUE(list_copy.back() == 3);
    List<double>::Iterator it = list_copy.begin();
    list_copy.insert(it, 43);
    ASSERT_TRUE(list_copy.size() == 7);
    ASSERT_TRUE(list_copy.front() == 43);
    List<double>::Iterator it1 = list_copy.end();
    list_copy.insert(it1, 50);
    ASSERT_TRUE(list_copy.size() == 8);
    ASSERT_TRUE(list_copy.back() == 50);
    List<double>::Iterator it2 = list_copy.begin();
    ASSERT_TRUE(list_copy.size() == 8);
    ASSERT_TRUE(list_copy.front() == 43);
    ASSERT_TRUE(list_copy.back() == 50);
    ASSERT_TRUE(*it2 == 43);
    ++it2;
    ASSERT_TRUE(*it2 == 90);
    ++it2;
    ASSERT_TRUE(*it2 == -89);
    list_copy.insert(it2, 67);
    ASSERT_TRUE(list_copy.size() == 9);
    List<double>::Iterator it3 = list_copy.begin();
    ASSERT_TRUE(*it3 == 43);
    ++it3;
    ASSERT_TRUE(*it3 == 90);
    ++it3;
    ASSERT_TRUE(*it3 == 67);
    ++it3;
    ASSERT_TRUE(*it3 == -89);
    ++it3;
    ASSERT_TRUE(*it3 == 12);
    ++it3;
    ASSERT_TRUE(*it3 == 9);
    ++it3;
    ASSERT_TRUE(*it3 == 6);
    ++it3;
    ASSERT_TRUE(*it3 == 3);
    ++it3;
    ASSERT_TRUE(*it3 == 50);
}

TEST(iterator_insert_edge_case)
{
    List<int> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_front(3);
    List<int>::Iterator it = list_copy.begin();
    list_copy.insert(it, 5);
    ASSERT_TRUE(list_copy.size() == 2);
    List<int>::Iterator it1 = list_copy.begin();
    ASSERT_TRUE(*it1 == 5);
    ++it1;
    ASSERT_TRUE(*it1 == 3);
    
}

TEST(iterator_earse_edge_case)
{
    List<double> list_copy;
    ASSERT_TRUE(list_copy.empty() == true);
    ASSERT_TRUE(list_copy.size() == 0);
    list_copy.push_back(45);
    List<double>::Iterator it = list_copy.begin();
    list_copy.erase(it);
    ASSERT_TRUE(list_copy.empty() == true);
}

TEST(pop_back_edge_case)
{
    List<int> list_copy;
    list_copy.push_back(45);
    list_copy.pop_back();
    ASSERT_TRUE(list_copy.empty() == true);
}

TEST(pop_front_edge_case)
{
    List<double> list_copy;
    list_copy.push_back(45);
    list_copy.pop_front();
    ASSERT_TRUE(list_copy.empty() == true);
}
TEST_MAIN()

#include "gtest/gtest.h" // GoogleTest ���������� ��� ����-������
#include "lab5_var6.h"
using namespace std;

TEST(lab5_var6, EmptyArray) // ���� � ���������� ���-��� ����� � �������� � ��������� �������
{
    const int rows = 0;
    const int cols = 0;
    auto arr = new int[0];
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, -1); // ������ ������� -1 (�������� �� ���� �������)
}

TEST(lab5_var6, EqualSizeOfRowsAndCols) // ���� � ���������� ���-��� ����� � �������� � ��������� �������
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols] = {
        {0,0,-5},
        {-2,-1,4},
        {1,5,0}
    };
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, 4); // ������ ������� 4 (2 ������, 3 ��������)
}

TEST(lab5_var6, DifferentSizeOfRowsAndCols) // ���� � ������ ���-�� ����� � �������� � ��������� �������
{
    const int rows = 5;
    const int cols = 3;
    int arr[rows][cols] = {
        {0,0,0},
        {-2,-1,-1},
        {-10,0,0},
        {10,0,-1},
        {1,0,12}
    };
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, 10); // ������ ������� 10 (4 ������, 1 ��������)
}

TEST(lab5_var6, AllNegative) // ���� ��� �������������� �������� � ��������� �������
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols] = {
        {0,-2,-2},
        {-2,-1,-2},
        {-5,0,0}
    };
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, -1); // ������ ������� -1 (�������� �� ���� �������)
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
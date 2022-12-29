#include "gtest/gtest.h" // GoogleTest библиотека для юнит-тестов
#include "lab5_var6.h"
using namespace std;

TEST(lab5_var6, EmptyArray) // тест с одинаковым кол-вом строк и столбцов в двумерном массиве
{
    const int rows = 0;
    const int cols = 0;
    auto arr = new int[0];
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, -1); // должен вернуть -1 (значение не было найдено)
}

TEST(lab5_var6, EqualSizeOfRowsAndCols) // тест с одинаковым кол-вом строк и столбцов в двумерном массиве
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols] = {
        {0,0,-5},
        {-2,-1,4},
        {1,5,0}
    };
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, 4); // должен вернуть 4 (2 строка, 3 значение)
}

TEST(lab5_var6, DifferentSizeOfRowsAndCols) // тест с разным кол-во строк и столбцов в двумерном массиве
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
    EXPECT_EQ(actual, 10); // должен вернуть 10 (4 строка, 1 значение)
}

TEST(lab5_var6, AllNegative) // тест без положительного элемента в двумерном массиве
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols] = {
        {0,-2,-2},
        {-2,-1,-2},
        {-5,0,0}
    };
    int actual = findstr(reinterpret_cast<int *>(arr), rows,cols);
    EXPECT_EQ(actual, -1); // должен вернуть -1 (значение не было найдено)
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
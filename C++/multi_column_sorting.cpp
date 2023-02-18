#include <iostream>

class Sorting
{
public:
    void sort(int number[][4], int length, char order)
    {
        if (order == 'A' || order == 'a')
        {
            for (int i = 0; i < length; i++)  
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (number[i][1] > number[j][1] || (number[i][1] == number[j][1] && number[i][2] > number[j][2]) || (number[i][1] == number[j][1] && number[i][2] == number[j][2] && number[i][3] > number[j][3]))
                    {
                        int temp[4];
                        for (int k = 0; k < 4; k++)
                        {
                            temp[k] = number[i][k];
                            number[i][k] = number[j][k];
                            number[j][k] = temp[k];
                        }
                    }
                }
            }
        }
        else if (order == 'B' || order == 'b')
        {
            for (int i = 0; i < length; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (number[i][2] > number[j][2] || (number[i][2] == number[j][2] && number[i][3] > number[j][3]) || (number[i][2] == number[j][2] && number[i][3] == number[j][3] && number[i][1] > number[j][1]))
                    {
                        int temp[4];
                        for (int k = 0; k < 4; k++)
                        {
                            temp[k] = number[i][k];
                            number[i][k] = number[j][k];
                            number[j][k] = temp[k];
                        }
                    }
                }
            }
        }
        else if (order == 'C' || order == 'c')
        {
            for (int i = 0; i < length; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (number[i][3] > number[j][3] || (number[i][3] == number[j][3] && number[i][1] > number[j][1]) || (number[i][3] == number[j][3] && number[i][1] == number[j][1] && number[i][2] > number[j][2]))
                    {
                        int temp[4];
                        for (int k = 0; k < 4; k++)
                        {
                            temp[k] = number[i][k];
                            number[i][k] = number[j][k];
                            number[j][k] = temp[k];
                        }
                    }
                }
            }
        }
        else
        {
            std::cout << "Invalid sorting order" << std::endl;
        }
    }
};

int main()
{
    Sorting sorting;
    int number[14][4] = {
        {1, 1, 1, 4},
        {2, 3, 1, 1},
        {3, 4, 4, 4},
        {4, 2, 4, 4},
        {5, 3, 5, 3},
        {6, 4, 3, 3},
        {7, 1, 3, 3},
        {8, 2, 4, 3},
        {9, 3, 3, 5},
        {10, 1, 5, 3},
        {11, 1, 1, 4},
        {12, 4, 1, 1},
        {13, 5, 2, 3},
        {14, 3, 5, 2} };
    int length = 14;

    char order;
    std::cout << "Enter sorting order (A, B, C): ";
    std::cin >> order;
    sorting.sort(number, length, order);

    std::cout << "Sorted by " << order << " :" << "   No" << "\t A" << "\t B" << "\t C" << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << " \t\t " << number[i][0] << " \t " << number[i][1] << " \t " << number[i][2] << " \t " << number[i][3] << " \t " << std::endl;
    }
    return 0;
}
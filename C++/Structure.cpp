#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;


struct Students
{
    char name[50];
    int score;
};

double MaxStudent(Students students[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].score > max)
        {
            max = students[i].score;
        }
    }
    return max;
}

double MinStudent(Students students[], int size)
{
    int min = 100;
    for (int i = 0; i < size; i++)
    {
        if (students[i].score < min)
        {
            min = students[i].score;
        }
    }
    return min;
}

double AverageStudent(Students students[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += students[i].score;
    }

    double AV = sum / size;
    return AV;
}

double ModeScore(Students students[], int size)
{
    int count = 0;
    int max = 0;
    int mode = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (students[i].score == students[j].score)
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            mode = students[i].score;
        }
        count = 0;
    }
    return mode;
}

double MedianScore(Students students[], int size)
{
    if (size % 2 == 0)
    {
        return (students[size / 2].score + students[(size / 2) - 1].score) / 2;
    }
    else
    {
        return students[size / 2].score;
    }
}

double SDScore(Students students[], int size)
{
    double sum = 0;
    double AV = AverageStudent(students, size);
    for (int i = 0; i < size; i++)
    {
        sum += pow(students[i].score - AV, 2);
    }

    double SD = sqrt(sum / size);
    return SD;
}

void GradeScore(Students students[], int size)
{
    double AV = AverageStudent(students, size);
    double SD = SDScore(students, size);
    for (int i = 0; i < size; i++)
    {
        if (students[i].score > AV + (2 * SD))
        {
            std::cout << students[i].name << " Grade = A " << std::endl;
        }
        else if (students[i].score < AV + (2 * SD) && students[i].score > AV + SD)
        {
            std::cout << students[i].name << " Grade = B " << std::endl;
        }
        else if (students[i].score < AV + SD && students[i].score > AV)
        {
            std::cout << students[i].name << " Grade = C " << std::endl;
        }
        else if (students[i].score < AV && students[i].score > AV - SD)
        {
            std::cout << students[i].name << " Grade = D " << std::endl;
        }
        else
        {
            std::cout << students[i].name << " Grade = F" << std::endl;
        }
    }

}

int main()
{
    Students students[10];
    students[0] = {"MJ", 58};
    students[1] = {"MK", 60};
    students[2] = {"MV", 62};
    students[3] = {"MG", 66};
    students[4] = {"PJ", 66};
    students[5] = {"PD", 72};
    students[6] = {"PC", 73};
    students[7] = {"PK", 79};
    students[8] = {"AR", 86};
    students[9] = {"AK", 94};
    int size = 10;

    cout << "Max: " << MaxStudent(students, 10) << endl;
    cout << "Min: " << MinStudent(students, 10) << endl;
    cout << "Average: " << AverageStudent(students, 10) << endl;
    cout << "Mode: " << ModeScore(students, 10) << endl;
    cout << "Median: " << MedianScore(students, 10) << endl;
    cout << "SD: " << SDScore(students, 10) << endl;
    GradeScore(students, 10);
    return 0;
}
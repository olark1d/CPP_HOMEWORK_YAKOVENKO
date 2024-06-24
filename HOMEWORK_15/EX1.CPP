#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define Marks 4

struct Student
{
    std::string name;
    int marks[Marks];
    float averageMark;
};

void print(const Student* students, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "Name: " << students[i].name << ", Marks: ";
        for(int j = 0; j < Marks; j++)
        {
            std::cout << students[i].marks[j] << ", ";
        }
        std::cout << "Average mark: " << students[i].averageMark << std::endl;
    }
}

float calculateAverageMark(const Student& student)
{
    float average = 0;
    for(int i = 0; i < Marks; i++)
    {
        average += student.marks[i];
    }
    return average / Marks;
}

bool compare(const Student& student1, const Student& student2)
{
    return student1.averageMark > student2.averageMark;
}

void sortStudents(Student* students, int size)
{
    std::sort(students, students + size, compare);
}

Student* mostSuccessfulStudents(Student* students, int size)
{
    Student* mostSuccessful = &students[0];
    for(int i = 1; i < size; i++)
    {
        if(students[i].averageMark > mostSuccessful->averageMark)
        {
            mostSuccessful = &students[i];
        }
    }
    return mostSuccessful;
}

int moreThanMark(const Student* students, int size, float mark)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(students[i].averageMark > mark)
        {
            count++;
        }
    }
    return count;
}

void getBestStudents(const Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent)
{
    if (percent > 100)
    {
        std::cerr << "Percent cannot be more than 100.\n";
        return;
    }

    std::vector<Student> sortedStudents(inStudents, inStudents + inSize);
    std::sort(sortedStudents.begin(), sortedStudents.end(), compare);

    outSize = (inSize * percent) / 100;
    if (outSize > inSize)
    {
        outSize = inSize;
    }

    for (unsigned i = 0; i < outSize; i++)
    {
        outStudents[i] = sortedStudents[i];
    }
}

int main()
{
    unsigned studentsNumber = 7;
    std::string studentNames[studentsNumber] = {"Oleh", "Viktoria", "Dima", "Alex", "Olena", "Nick", "Michael"};
    Student students[studentsNumber] = 
    {
        {studentNames[0], {4, 4, 3, 5}},
        {studentNames[1], {5, 5, 5, 5}},
        {studentNames[2], {3, 4, 3, 3}},
        {studentNames[3], {3, 3, 3, 3}},
        {studentNames[4], {4, 4, 3, 3}},
        {studentNames[5], {3, 4, 3, 3}},
        {studentNames[6], {4, 4, 3, 4}}
    };

    for(int i = 0; i < studentsNumber; i++)
    {
        students[i].averageMark = calculateAverageMark(students[i]);
    }

    while(true)
    {
        int task;
        std::cout << std::endl
                  << "0 - Average mark by name of student\n"
                  << "1 - Sorting students by an average mark\n"
                  << "2 - Link to the most successful student\n"
                  << "3 - The number of students whose average grade is greater than N\n"
                  << "4 - The most successful students\n"
                  << "-1 - to exit\n\n"
                  << "Choose a task: ";
        std::cin >> task;

        if(task == -1)
        {
            break;
        }
        switch(task)
        {
            case 0:
            {
                std::string name;
                std::cout << "Enter a name of student('exit' to exit): ";
                std::cin.ignore();
                std::getline(std::cin, name);

                bool found = false;
                for (int i = 0; i < studentsNumber; i++)
                {
                    if (students[i].name == name)
                    {
                        std::cout << "Average mark: " << students[i].averageMark << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found && name != "exit")
                {
                    std::cout << "Invalid name!\n";
                }
                break;
            }
            case 1:
            {
                std::cout << std::endl << "Students before sorting: \n";
                print(students, studentsNumber);

                sortStudents(students, studentsNumber);
                std::cout << std::endl << "Students after sorting by average mark: \n";
                print(students, studentsNumber);
                break;
            }
            case 2:
            {
                Student* mostSuccessfulStudent = mostSuccessfulStudents(students, studentsNumber); 
                std::cout<<"The most successful student: "<<mostSuccessfulStudent<<std::endl<<std::endl;
                break;
            }
            case 3:
            {
                float mark;
                std::cout << "Enter a mark: ";
                std::cin >> mark;

                int count = moreThanMark(students, studentsNumber, mark);
                std::cout << "A number of students with average mark more than " << mark << " is " << count << std::endl;
                break;
            }
            case 4:
            {
                unsigned outSize;
                Student bestStudents[studentsNumber];

                unsigned percent;
                std::cout << "Enter a percent: ";
                std::cin >> percent;
                getBestStudents(students, studentsNumber, bestStudents, outSize, percent);

                std::cout << "Best " << percent << "% students:\n\n";
                print(bestStudents, outSize);
                break;
            }
            default:
            {
                std::cout << "Invalid input!\n";
            }
        }
    }

    return 0;
}

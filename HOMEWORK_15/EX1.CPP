#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int marks[4];

    float averageMark;
};

void print(Student* students, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout<<"Name: "<<students[i].name<<", Marks: ";
        for(int j = 0; j < 4; j++)
        {
            std::cout<<students[i].marks[j]<<", ";
        }
        std::cout<<"Average mark: "<<students[i].averageMark<<std::endl;
    }
}

float averageMark(Student* students, int number)
{
    float average = 0;
    for(int i = 0; i < 4; i++)
    {
        average += students[number].marks[i];
    }
    average = average/4;
    return average;
}

bool compare(const Student& student1, const Student student2)
{
    return student1.averageMark > student2.averageMark;
}

void sort(Student* students, int size)
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

int moreThanMark(Student* students, int size, float mark)
{
    int count;
    for(int i = 0; i < size; i++)
    {
        if(students[i].averageMark > mark)
        {
            count++;
        }
    }
    return count;
}

bool compareStudents(const Student& student1, const Student& student2) {
    return student1.averageMark > student2.averageMark;
}

void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent) {
    if (percent > 100) {
        std::cerr << "Percent cannot be more than 100.\n";
        return;
    }

    std::vector<Student> sortedStudents(inStudents, inStudents + inSize);
    std::sort(sortedStudents.begin(), sortedStudents.end(), compareStudents);

    outSize = (inSize * percent) / 100;
    if (outSize > inSize) {
        outSize = inSize;
    }

    for (unsigned i = 0; i < outSize; i++) {
        outStudents[i] = sortedStudents[i];
    }
}

int main()
{
    unsigned studentsNumber = 7;

    std::string studentName[studentsNumber] = {"Oleh", "Viktoria", "Dima", "Alex", "Olena", "Nick", "Michael"};
    Student students[studentsNumber] = 
    {
        {studentName[0], {4, 4, 3, 5}},
        {studentName[1], {5, 5, 5, 5}},
        {studentName[2], {3, 4, 3, 3}},
        {studentName[3], {3, 3, 3, 3}},
        {studentName[4], {4, 4, 3, 3}},
        {studentName[5], {3, 4, 3, 3}},
        {studentName[6], {4, 4, 3, 4}}
    };

    
    float average[studentsNumber];
    for(int i = 0; i < studentsNumber; i++)
    {
        students[i].averageMark = averageMark(students, i);
    }

    while(true)
    {
        int task;
        std::cout<<std::endl
        <<"0 - Average mark by name of student\n"
        <<"1 - Sorting students by an average mark\n"
        <<"2 - Link to the most successful student\n"
        <<"3 - the number of students whose average grade is greater than N\n"
        <<"4 - The most successful students\n"
        <<"-1 - to exit\n\n"
        <<"Choose a task: ";
        std::cin>>task;

        if(task == -1)
        {
        break;
        }
        switch(task)
        {
            case 0:
            {
                int exit = 0;
                while(exit != -1)
                {
                    std::string name;
                    int number;
                    bool validate;
                    std::cout<<"Enter a name of student('exit' to exit): ";
                    std::getline(std::cin, name);

                    if(studentName[0] == name)
                    {
                    std::cout<<"Average mark: "<<students[0].averageMark<<std::endl;;
                    }
                    else if(studentName[1] == name )
                    {
                    std::cout<<"Average mark: "<<students[1].averageMark<<std::endl;;
                    }
                    else if(studentName[2] == name )
                    {
                    std::cout<<"Average mark: "<<students[2].averageMark<<std::endl;;
                    }
                    else if(studentName[3] == name )
                    {
                    std::cout<<"Average mark: "<<students[3].averageMark<<std::endl;;
                    }
                    else if(studentName[4] == name )
                    {
                    std::cout<<"Average mark: "<<students[4].averageMark<<std::endl;;
                    }
                    else if(studentName[5] == name )
                    {
                    std::cout<<"Average mark: "<<students[5].averageMark<<std::endl;;
                    }
                    else if(studentName[6] == name )
                    {
                    std::cout<<"Average mark: "<<students[6].averageMark<<std::endl;;
                    }
                    else if(name == "exit")
                    {
                        exit = -1;
                    }
                    else
                    {
                    std::cout<<"Invalid name!\n";
                    }
                }
            break;
            }

            case 1:
            {
                std::cout<<std::endl<<"Students before sorting: \n";
                print(students, studentsNumber);

                sort(students, studentsNumber);
                std::cout<<std::endl<<"Students after sorting by average mark: \n";
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
                std::cout<<"Enter a mark: ";
                std::cin>>mark;

                int count = moreThanMark(students, studentsNumber, mark);
                std::cout<<"A number of students with average mark more than "<<mark<<" is "<<count<<std::endl;
                break;
            }

            case 4:
            {
                unsigned outSize;
                Student bestStudents[studentsNumber];

                unsigned percent;
                std::cout<<"Enter a percent: ";
                std::cin>>percent;
                getBestStudents(students, studentsNumber, bestStudents, outSize, percent);

                std::cout<<"Best "<<percent<<"% students:\n\n";
                print(bestStudents, outSize);
                break;
            }
            default:
            {
                std::cout<<"Invalid input!\n";
            }

        }
    }
}
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Grade
{
    char item;
    char gender;
    char school;
    int grade;
};


int main()
{
    int i, j, num = 0;
    struct Grade stu[1000];
    char item, gender, school;
    int grade;
    char str[20];

    // read input data
    while(fgets(str, 60, stdin)){

        Grade *student = new Grade();
        sscanf(str, "%c %c %c %d", &item, &gender, &school, &grade);
        student->item = item;
        student->gender = gender;
        student->school = school;
        student->grade = grade;
        stu[num] = *student;
        num++;
        delete student;
    }

    char schoolName[5] = {'A', 'B', 'C', 'D', 'E'};
    int boyGrade[5], girlGrade[5], groupGrade[5];
    memset(boyGrade, 0, 5 * sizeof(int));
    memset(girlGrade, 0, 5 * sizeof(int));
    memset(groupGrade, 0, 5 * sizeof(int));

    // calculate grades
    for (j = 0; j < num; j++){
        for (i = 0; i < 5; i++){
            if (stu[j].school == schoolName[i]){

                groupGrade[i] += stu[j].grade;

                if (stu[j].gender == 'F') 
                {
                    girlGrade[i] += stu[j].grade;
                }
                else if (stu[j].gender == 'M')
                {
                    boyGrade[i] += stu[j].grade;
                }
                
            }
        }
    }


    // print formatted grades
    for (i = 0; i < 5; i++){
        if (groupGrade[i] > 0){
            if (boyGrade[i] > 0)
            {
                cout << schoolName[i] << " " << 'M' << " " << boyGrade[i];
                cout << endl;
            }
            if (girlGrade[i] > 0)
            {
                cout << schoolName[i] << " " << 'F' << " " << girlGrade[i];
                cout << endl;
            }
            cout << schoolName[i] << " " << groupGrade[i];
            cout << endl;
        }
        
        
    }
    
}
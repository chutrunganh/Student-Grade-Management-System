#include <stdio.h>
#include <string.h>
#include "Grade.h"

//Part e
//Hàm nhập các thông tin (trừ thông tin về ID, sinh viên, học phần) cho 1 bản ghi trong danh sách Grades[]
void getGradeInfo(Grade_detail *AnewGrade) {
    puts("Enter attendance grade: ");
    scanf("%f", &AnewGrade->attendance);
    puts("Enter midterm  grade: ");
    scanf("%f", &AnewGrade->midTerm);
    puts("Enter homework grade: ");
    scanf("%f", &AnewGrade->homework);
    puts("Enter finalterm grade: ");
    scanf("%f", &AnewGrade->finalTerm);

    AnewGrade->finalGrade = 0;  //mặc định 2 mục này chưa có gì
    AnewGrade->rating[0] = '\0';
}

//hàm check xem Học sinh đi cùng với bản ghi đó đã từng tồn tại trong bản ghi nào trước đó chưa
//Bằng cách so sánh ID nhập vào và tìm thử ID đó trong Grades[] xem đã có chưa
int checkExsit(Grade_detail Grades[], int number_of_grades, char student_ID_to_find[], char module_ID_to_find[]) {
    for (int i = 0; i < number_of_grades; i++) {
        if (strcmp(Grades[i].AnewStudent.student_ID, student_ID_to_find) == 0 &&
            strcmp(Grades[i].AnewModule.module_ID, module_ID_to_find) == 0) {
            return -1;   //sinh viên cùng mã học phần này đã tồn tại
        }
    }
    return 1;
}

//Part f
void finalGradeAndRating(Grade_detail Grades[], int number_of_grades) {
    for (int i = 0; i < number_of_grades; i++) {
        //tính toán điểm tổng kết cuối cùng cho từng bản ghi
        Grades[i].finalGrade = Grades[i].attendance * 0.1 + Grades[i].midTerm * 0.2 + Grades[i].homework * 0.3 +
                               Grades[i].finalTerm * 0.4;

        //Phân loại điểm
        //chú ý không thể dùng được kiểu Grades[i].rating = "F" vì .rating là con trỏ luôn trỏ đến vị trí đầu của mảng
        //nên không thể thay đổi được giá trị. Điều này khác với Python
        if (Grades[i].finalGrade < 4.0) {
            strcpy(Grades[i].rating, "F");
        } else if (Grades[i].finalGrade < 5.0) {
            strcpy(Grades[i].rating, "D");
        } else if (Grades[i].finalGrade < 6.0) {
            strcpy(Grades[i].rating, "C");
        } else if (Grades[i].finalGrade < 7.0) {
            strcpy(Grades[i].rating, "C+");
        } else if (Grades[i].finalGrade < 8.0) {
            strcpy(Grades[i].rating, "B");
        } else if (Grades[i].finalGrade < 8.5) {
            strcpy(Grades[i].rating, "B+");
        } else if (Grades[i].finalGrade < 9.0) {
            strcpy(Grades[i].rating, "A");
        } else {
            strcpy(Grades[i].rating, "A+");
        }
    }
}


//Part g
void showGradeInfo(Grade_detail Grades[], int n) {
    puts("List of grades");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",
           "ID", "Student ID", "Student name", "Module ID", "Module name", "Attendance", "Midterm", "Homework",
           "Finalterm", "FinalGrade", "Rating");
    puts("---------------------------------------------------------------------------------------------------------------"
         "-------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("%-20s%-20s%-20s%-20s%-20s%-20.2f%-20.2f%-20.2f%-20.2f%-20.2f%-20s\n",
               Grades[i].grade_ID, Grades[i].AnewStudent.student_ID, Grades[i].AnewStudent.student_name,
               Grades[i].AnewModule.module_ID, Grades[i].AnewModule.module_name,
               Grades[i].attendance, Grades[i].midTerm, Grades[i].homework, Grades[i].finalTerm,
               Grades[i].finalGrade, Grades[i].rating);
    }
}


//Part h
//sắp xếp theo điểm tổng kết
void swap(Grade_detail *a, Grade_detail *b) {
    Grade_detail temp = *a;
    *a = *b;
    *b = temp;
}

void sort(Grade_detail Grades[], int n) {

    for (int i = 0; i < n - 1; i++) { //sắp xếp tối đa n – 1 lần
        for (int j = 0; j < n - i - 1; j++) {
            if (Grades[j].finalGrade < Grades[j + 1].finalGrade) {
                swap(&Grades[j], &Grades[j + 1]);
            }
        }
    }
}

//Part i
void finalGradeEqualX(Grade_detail Grades[], int n, float x) {
    printf("Students with final grade equal to %.2f\n", x);
    printf("%-20s%-20s%-20s%-20s\n", "ID", "Name", "Address", "Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {   //tìm đc final grade trùng khớp thì in ra học sinh đó
        if (Grades[i].finalGrade == x) {
            printf("%-20s%-20s%-20s%-20s\n", Grades[i].AnewStudent.student_ID, Grades[i].AnewStudent.student_name,
                   Grades[i].AnewStudent.student_address, Grades[i].AnewStudent.student_major);
        }
    }
}

//Part j
void RatingEqualY(Grade_detail Grades[], int n, char y[2]) {
    printf("Students with rating equal to %s\n", y);
    printf("%-20s%-20s%-20s%-20s\n", "ID", "Name", "Address", "Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {   //tìm đc final grade trùng khớp thì in ra học sinh đó
        if (strcmp(Grades[i].rating, y) == 0) {
            printf("%-20s%-20s%-20s%-20s\n", Grades[i].AnewStudent.student_ID, Grades[i].AnewStudent.student_name,
                   Grades[i].AnewStudent.student_address, Grades[i].AnewStudent.student_major);
        }
    }
}

//Part k
void updateGrade(Grade_detail Grades[], int n, char ID_to_update[]) {
    float newAttendance, newMidterm, newHomework, newFinalterm;
    puts("Enter new attendance grade: ");
    scanf("%f", &newAttendance);
    puts("Enter  new midterm  grade: ");
    scanf("%f", &newMidterm);
    puts("Enter  new homework grade: ");
    scanf("%f", &newHomework);
    puts("Enter  new finalterm grade: ");
    scanf("%f", &newFinalterm);
    for (int i = 0; i < n; i++) {
        if (strcmp(Grades[i].grade_ID, ID_to_update) == 0) {
            Grades[i].attendance = newAttendance;
            Grades[i].midTerm = newMidterm;
            Grades[i].homework = newHomework;
            Grades[i].finalTerm = newFinalterm;
        }
    }

}

//Part l  //Ctrl + S
void writeGradeFile(char file_name[], Grade_detail Grades[], int n) {
    FILE *fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0; i < n; i++) {
        fwrite(&Grades[i], sizeof(Grade_detail), 1, fp);
    }
    puts("Write grades data successfully !");
    fclose(fp);
}

//Part m
void readGradeFile(char file_name[], Grade_detail Grades[], int *n) {
    FILE *fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", file_name);
        return;
    }

    int i = 0;
    while (!feof(fp)) {
        fread(&Grades[i], sizeof(Grade_detail), 1, fp);
        if (feof(fp)) {
            break;
        }
        i++;
    }

    *n = i;

    fclose(fp);
}

   
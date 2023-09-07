#include <stdio.h>
#include <string.h> // sử dụng cho hàm strcmp
#include "Student.h"

//Part c
void getStudentInfo(Student_detail *AnewStudent) {
    puts("Enter student ID: ");
    scanf("%*c%19s", AnewStudent->student_ID);
    puts("Enter student name: ");
    scanf("%*c%19[^\n]", AnewStudent->student_name);  //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    puts("Enter student address: ");
    scanf("%*c%19[^\n]", AnewStudent->student_address);
    puts("Enter student major: ");
    scanf("%*c%19[^\n]", AnewStudent->student_major);
}

//Part d
void showStudentInfo(Student_detail Students[], int n) { //In từ mảng Students
    puts("List of students");
    printf("%-20s%-20s%-20s%-20s\n", "ID", "Name", "Address", "Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("%-20s%-20s%-20s%-20s\n", Students[i].student_ID, Students[i].student_name, Students[i].student_address,
               Students[i].student_major);
    }
}

//Part e
//hàm tìm vị trí của một học sinh trong danh sách Students[] theo mã ID học sinh
int indexFromStudentID(Student_detail Students[], int number_of_students, char ID_to_find[]) {
    for (int i = 0; i < number_of_students; i++) {
        int match = strcmp(ID_to_find, Students[i].student_ID);
        if (match == 0) {
            return i;
        }
    }
}

//Part l  //Ctrl + S
void writeStudentFile(char file_name[], Student_detail Students[], int n) {
    FILE *fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0; i < n; i++) {
        fwrite(&Students[i], sizeof(Student_detail), 1, fp);
    }
    puts("Write students data successfully !");
    fclose(fp);
}

//Part m
void readStudentFile(char file_name[], Student_detail Students[], int *n) {
    FILE *fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", file_name);
        return;
    }

    int i = 0;
    while (!feof(fp)) {
        fread(&Students[i], sizeof(Student_detail), 1, fp);
        if (feof(fp)) {
            break;
        }
        i++;
    }

    *n = i;

    fclose(fp);
}
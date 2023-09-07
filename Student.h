#pragma once

// cấu trúc sinh viên
typedef struct {
    char student_ID[20];
    char student_name[20];
    char student_address[20];
    char student_major[20];

} Student_detail;

//Part c
void getStudentInfo(Student_detail *AnewStudent);

//Part d
void showStudentInfo(Student_detail Students[], int n);

//Part e
int indexFromStudentID(Student_detail Students[], int number_of_students, char ID_to_find[]);

//Part l
void writeStudentFile(char file_name[], Student_detail Students[], int n);

//Part m
void readStudentFile(char file_name[], Student_detail Students[], int *n);

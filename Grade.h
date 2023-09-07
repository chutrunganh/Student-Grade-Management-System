#pragma once

#include "Student.h"
#include "Module.h"

typedef struct {
    char grade_ID[10];
    Student_detail AnewStudent;
    Module_detail AnewModule;
    float attendance; //điểm chuyên cần
    float midTerm;
    float homework;  //điểm bài tập lớn
    float finalTerm;
    float finalGrade;
    char rating[2];
} Grade_detail;

//Part e
void getGradeInfo(Grade_detail *AnewGrade);

int checkExsit(Grade_detail Grades[], int number_of_grades, char student_ID_to_find[], char module_ID_to_find[]);

//Part g
void showGradeInfo(Grade_detail Grades[], int n);

//Part f
void finalGradeAndRating(Grade_detail Grades[], int number_of_grades);

//Part h
void swap(Grade_detail *a, Grade_detail *b);

void sort(Grade_detail Grades[], int n);

//Part i
void finalGradeEqualX(Grade_detail Grades[], int n, float x);

//Part j
void RatingEqualY(Grade_detail Grades[], int n, char y[2]);

//Part k
void updateGrade(Grade_detail Grades[], int n, char ID_to_update[]);

//Part l
void writeGradeFile(char file_name[], Grade_detail Grades[], int n);

//Part m
void readGradeFile(char file_name[], Grade_detail Grades[], int *n);



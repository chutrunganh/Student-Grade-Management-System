#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"
#include "Module.h"
#include "Grade.h"


int main() {

    char module_file_name[] = "Module.TXT";
    char student_file_name[] = "Student.TXT";
    char grade_file_name[] = "Grade.TXT";


    Module_detail Modules[10]; //cho phép tối đa 10 môn học
    int number_of_modules = 0; // biến number_of_modules để theo dõi số môn học hiện có trong danh sách

    Student_detail Students[10];
    int number_of_students = 0;

    //bảng điểm cho tối đa 10 sinh viên với 10 học phần tương ứng (Mỗi bản 
    //ghi trong Grades[] gồm 1 sinh viên đi cùng với 1 mã học phần và các đầu điểm)
    Grade_detail Grades[10];
    int number_of_grades = 0;

    //đọc dữ liệu mỗi lần khởi chạy
    readStudentFile(student_file_name, Students, &number_of_students);
    readModuleFile(module_file_name, Modules, &number_of_modules);
    readGradeFile(grade_file_name, Grades, &number_of_grades);

    int choice;
    do {


        puts("============ QUAN LY TAI KHOAN ============");
        puts("1. Add a new module ");
        puts("2. Show list of module");
        puts("3. Add a new student");
        puts("4. Show list of students");
        puts("5. Add a grade for students with their modules");
        puts("6. Show list of grade");
        puts("7. Calculate final grade and rating");
        puts("8. Sort by final grade");
        puts("9. Find student with final grade equal to x");
        puts("10. Find student with rating equal to y");
        puts("11. Update grade");
        puts("12. Write all data to file ( Ctrl+S)");
        puts("0. Exit");
        puts("Please choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                system("cls");
                puts("==========================================");
                puts("===> Thank you for using our service! <===");
                puts("==========================================");
                break;
            case 1: {
                //system("cls");
                Module_detail AnewModule; //tạo một module mới
                getModuleInfo(&AnewModule);
                Modules[number_of_modules++] = AnewModule;
                //thêm module mới vào danh sách, number_of_modules là số module thực tế hiện tại
                //nên mỗi lần thêm module phải tăng number_of_modules thêm 1
                break;
            }
            case 2: {
                //system("cls");
                showModuleInfo(Modules, number_of_modules);
                break;
            }
            case 3: {
                //system("cls");
                Student_detail AnewStudent; //tạo một module mới
                getStudentInfo(&AnewStudent);
                Students[number_of_students++] = AnewStudent;
                //thêm học sinh mới vào danh sách, number_of_students là số học sinh thực tế hiện tại
                //nên mỗi lần thêm học sinh phải tăng number_of_students thêm 1
                break;
            }
            case 4: {
                //system("cls");
                showStudentInfo(Students, number_of_students);
                break;
            }
            case 5: {
                //system("cls");


                //ID của 1 bản ghi trong bảng điểm
                puts("Enter grade ID: ");
                scanf("%*c%9s", Grades[number_of_grades].grade_ID);

                //ID của học sinh và module
                char student_ID_to_find[10];
                char module_ID_to_find[10];
                puts("Enter module ID to find");
                scanf("%*c%9s", module_ID_to_find);
                puts("Enter student ID to find");
                scanf("%*c%9s", student_ID_to_find);

                //xem học sinh và mã học phần đó đã tồn tại chưa
                if (checkExsit(Grades, number_of_grades, student_ID_to_find, module_ID_to_find) == -1) {
                    puts("Student with this module exsited");
                } else {  //nếu chưa tồn tại thì đọc vào

                    // Thông tin về Học sinh và học phần trong bản ghi đó
                    int studentIndex = indexFromStudentID(Students, number_of_students, student_ID_to_find);
                    int moduleIndex = indexFromModuleID(Modules, number_of_modules, module_ID_to_find);
                    Grades[number_of_grades].AnewStudent = Students[studentIndex];
                    Grades[number_of_grades].AnewModule = Modules[moduleIndex];
                    //ghi nốt các thông tin còn lại
                    getGradeInfo(&Grades[number_of_grades]);
                    number_of_grades++; //tăng thêm 1 bản ghi
                }

                break;
            }
            case 6: {
                //system("cls");
                showGradeInfo(Grades, number_of_grades);
                break;
            }
            case 7: {
                //system("cls");
                finalGradeAndRating(Grades, number_of_grades);
                puts("Calculate final grade and rating successfully !");
                break;
            }
            case 8: {
                //system("cls");
                sort(Grades, number_of_grades);
                puts("Sort successfully!");
                break;

            }
            case 9: {
                //system("cls");
                float x;
                puts("Enter x: ");
                scanf("%f", &x);
                finalGradeEqualX(Grades, number_of_grades, x);
                break;
            }
            case 10 : {
                //system("cls");
                char y[2];
                puts("Enter y: ");
                scanf("%*c%2s", y);
                RatingEqualY(Grades, number_of_grades, y);
                break;
            }
            case 11: {
                //system("cls");
                char ID_to_upadte[10];
                puts("Enter ID that need to update: ");
                scanf("%*c%9s", ID_to_upadte);
                updateGrade(Grades, number_of_grades, ID_to_upadte);
                puts("Update successfully!");
                break;
            }
            case 12: {
                //system("cls");
                writeStudentFile(student_file_name, Students, number_of_students);
                writeModuleFile(module_file_name, Modules, number_of_modules);
                writeGradeFile(grade_file_name, Grades, number_of_grades);
                break;
            }
        }
    } while (choice != 0);

}



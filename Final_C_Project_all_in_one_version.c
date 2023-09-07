#include <stdio.h>
#include <stdlib.h>

//Khởi tạo các cấu trúc
typedef struct {
    char module_ID[10];
    char module_name[20];
    int module_credit;

} Module_detail;

typedef struct {
    char student_ID[20];
    char student_name[20];
    char student_address[20];
    char student_major[20];

} Student_detail;

typedef struct {
    char grade_ID[10];
    Student_detail AnewStudent ;
    Module_detail AnewModule;
    float attendance; //điểm chuyên cần
    float midTerm;
    float homework;  //điểm bài tập lớn
    float finalTerm;
    float finalGrade;
    char rating[2];
} Grade_detail;

//Các hàm nnguyeen mẫu
//Part a
void getModuleInfo(Module_detail * AnewModule);
//Part b
void showModuleInfo(Module_detail Modules[], int n);
//Part c
void getStudentInfo(Student_detail * AnewStudent);
//Part d
void showStudentInfo(Student_detail Students[], int n);
//Part e
int indexFromStudentID (Student_detail Students[],int number_of_students, char ID_to_find[]);
int indexFromModuleID( Module_detail Modules[], int number_of_modules, char ID_to_find[]);
void getGradeInfo(Grade_detail * AnewGrade);
int checkExsit(Grade_detail Grades[], int number_of_grades, char student_ID_to_find[], char module_ID_to_find[]);
//Part g
void showGradeInfo(Grade_detail  Grades[], int n);
//Part f
void finalGradeAndRating(Grade_detail Grades[], int number_of_grades);
//Part h
void swap(Grade_detail * a, Grade_detail * b);
void sort(Grade_detail Grades[],int n);
//Part i
void finalGradeEqualX(Grade_detail Grades[], int n, float x);
//Part j
void RatingEqualY(Grade_detail Grades[], int n, char y[2]);
//Part k
void updateGrade(Grade_detail Grades[], int n, char ID_to_update[]);
//Part l
void writeStudentFile(char file_name[], Student_detail Students[], int n);
void writeModuleFile(char file_name[], Module_detail Modules[], int n);
void writeGradeFile(char file_name[], Grade_detail Grades[], int n);
//Part m
void readStudentFile(char file_name[], Student_detail Students[], int *n);
void readModuleFile(char file_name[], Module_detail Modules[], int *n);
void readGradeFile(char file_name[], Grade_detail Grades[], int *n);



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

        switch (choice)  
        {
        case 0:
            system("cls");
            puts("==========================================");
            puts("===> Thank you for using our service! <===");
            puts("==========================================");
            break ; 
        case 1:
        {
            //system("cls");
            Module_detail AnewModule; //tạo một module mới
            getModuleInfo(&AnewModule);
            Modules[number_of_modules++] = AnewModule;
            //thêm module mới vào danh sách, number_of_modules là số module thực tế hiện tại
            //nên mỗi lần thêm module phải tăng number_of_modules thêm 1
            break;
        }
        case 2:
        {
            //system("cls");
            showModuleInfo(Modules,number_of_modules);
            break;
        }
        case 3:
        {
            //system("cls");
            Student_detail AnewStudent; //tạo một module mới
            getStudentInfo(&AnewStudent);
            Students[number_of_students++] = AnewStudent;
            //thêm học sinh mới vào danh sách, number_of_students là số học sinh thực tế hiện tại
            //nên mỗi lần thêm học sinh phải tăng number_of_students thêm 1
            break;
        }
        case 4:
        {
            //system("cls");
            showStudentInfo(Students,number_of_students);
            break;
        }
        case 5:
        {
            //system("cls");

            
            //ID của 1 bản ghi trong bảng điểm
            puts("Enter grade ID: ");
            scanf("%*c%9s",Grades[number_of_grades].grade_ID);

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
            }
            else {  //nếu chưa tồn tại thì đọc vào

                // Thông tin về Học sinh và học phần trong bản ghi đó
                int studentIndex = indexFromStudentID(Students, number_of_students,student_ID_to_find);
                int moduleIndex = indexFromModuleID(Modules, number_of_modules, module_ID_to_find);
                Grades[number_of_grades].AnewStudent = Students[studentIndex];
                Grades[number_of_grades].AnewModule = Modules[moduleIndex];
                //ghi nốt các thông tin còn lại
                getGradeInfo(&Grades[number_of_grades]);
                number_of_grades++ ; //tăng thêm 1 bản ghi
            }

            break;
        }
        case 6:
        {
            //system("cls");
            showGradeInfo(Grades, number_of_grades);
            break;
        }
        case 7: 
        {
             //system("cls");
            finalGradeAndRating(Grades, number_of_grades);
            puts("Calculate final grade and rating successfully !");
            break;
        }
        case 8:
        {
            //system("cls");
            sort(Grades, number_of_grades);
            puts("Sort successfully!");
            break;
            
        }
        case 9:
        {
            //system("cls");
            float x;
            puts("Enter x: ");
            scanf("%f", &x);
            finalGradeEqualX(Grades, number_of_grades, x);
            break;
        }
        case 10 :
        {
            //system("cls");
            char y[2];
            puts("Enter y: ");
            scanf("%*c%2s", y);
            RatingEqualY(Grades, number_of_grades, y);
            break;
        }
        case 11:
        {
            //system("cls");
            char ID_to_upadte[10];
            puts("Enter ID that need to update: ");
            scanf("%*c%9s",ID_to_upadte);
            updateGrade(Grades,number_of_grades, ID_to_upadte);
            puts("Update successfully!");
            break;
        }
        case 12:
        {
            //system("cls");
            writeStudentFile(student_file_name,Students, number_of_students);
            writeModuleFile(module_file_name, Modules, number_of_modules);
            writeGradeFile(grade_file_name, Grades, number_of_grades);
            break;
        }   
        }
    } while (choice != 0);

}


//Part a
void getModuleInfo(Module_detail * AnewModule){ //cần thay đổi AnewModule nên phải truyền tham chiếu
    puts("Enter module ID: ");
    scanf("%*c%9s", AnewModule -> module_ID);
    puts("Enter module name: ");
    scanf("%*c%19s", AnewModule -> module_name);
    puts("Enter module credit: ");
    scanf("%d", &AnewModule -> module_credit);
}

//Part b
void showModuleInfo(Module_detail Modules[], int n) {   //In từ mảng Modules
    puts("List of modules");
    printf("%-10s%-20s%-10s\n","ID","Name","Credit");
    puts("-------------------------------------------");
    for (int i = 0; i < n; i++) {
         printf("%-10s%-20s%-10d\n", Modules[i].module_ID, Modules[i].module_name, Modules[i].module_credit);
    }
}

//Part c
void getStudentInfo(Student_detail * AnewStudent) {
    puts("Enter student ID: ");
    scanf("%*c%19s", AnewStudent -> student_ID);
    puts("Enter student name: ");
    scanf("%*c%19[^\n]", AnewStudent -> student_name);  //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    puts("Enter student address: ");
    scanf("%*c%19[^\n]", AnewStudent -> student_address);
    puts("Enter student major: ");
    scanf("%*c%19[^\n]", AnewStudent -> student_major);
}

//Part d
void showStudentInfo(Student_detail Students[], int n) { //In từ mảng Students
    puts("List of students");
    printf("%-20s%-20s%-20s%-20s\n","ID","Name","Address","Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
         printf("%-20s%-20s%-20s%-20s\n", Students[i].student_ID, Students[i].student_name, Students[i].student_address, Students[i].student_major);
    }
}

//Part e
#include <string.h> // sử dụng cho hàm strcmp

//hàm tìm vị trí của một học sinh trong danh sách Students[] theo mã ID học sinh
int indexFromStudentID (Student_detail Students[],int number_of_students, char ID_to_find[]) {
    for (int i = 0; i < number_of_students; i++) {
        int match = strcmp(ID_to_find, Students[i].student_ID);
        if (match == 0) {
            return i;
        }
    }
}

//hàm tìm vị trí của một học phần trong danh sách Moules[] theo mã ID học phần
int indexFromModuleID( Module_detail Modules[], int number_of_modules, char ID_to_find[]) {
    for (int i = 0; i < number_of_modules ; i++) {
        int match = strcmp(ID_to_find, Modules[i].module_ID);
        if (match == 0) {
            return i;
        }
    }
}

//Hàm nhập các thông tin (trừ thông tin về ID, sinh viên, học phần) cho 1 bản ghi trong danh sách Grades[]
void getGradeInfo(Grade_detail * AnewGrade) {
    puts("Enter attendance grade: ");
    scanf("%f", &AnewGrade ->attendance);
    puts("Enter midterm  grade: ");
    scanf("%f", &AnewGrade -> midTerm);
    puts("Enter homework grade: ");
    scanf("%f", &AnewGrade -> homework);
    puts("Enter finalterm grade: ");
    scanf("%f", &AnewGrade -> finalTerm);

    AnewGrade -> finalGrade = 0;  //mặc định 2 mục này chưa có gì
    AnewGrade -> rating[0] = '\0';
}

//hàm check xem Học sinh đi cùng với bản ghi đó đã từng tồn tại trong bản ghi nào trước đó chưa
//Bằng cách so sánh ID nhập vào và tìm thử ID đó trong Grades[] xem đã có chưa
int checkExsit(Grade_detail Grades[], int number_of_grades, char student_ID_to_find[], char module_ID_to_find[]) {
    for (int i = 0; i < number_of_grades; i++) 
    {
        if (strcmp(Grades[i].AnewStudent.student_ID, student_ID_to_find) == 0 && 
            strcmp(Grades[i].AnewModule.module_ID, module_ID_to_find) == 0)
            {
                return -1;   //sinh viên cùng mã học phần này đã tồn tại   
            }
    }
    return 1;
}
//Part f
void finalGradeAndRating(Grade_detail Grades[], int number_of_grades) {
        for (int i = 0; i < number_of_grades; i++) {
            //tính toán điểm tổng kết cuối cùng cho từng bản ghi
            Grades[i].finalGrade = Grades[i].attendance * 0.1 + Grades[i].midTerm * 0.2  + Grades[i].homework * 0.3 + Grades[i].finalTerm * 0.4;
            
            //Phân loại điểm
            //chú ý không thể dùng được kiểu Grades[i].rating = "F" vì .rating là con trỏ luôn trỏ đến vị trí đầu của mảng 
            //nên không thể thay đổi được giá trị. Điều này khác với Python
            if (Grades[i].finalGrade < 4.0 ) {
              strcpy(Grades[i].rating, "F");
            }
            else if (Grades[i].finalGrade < 5.0 ) {
              strcpy(Grades[i].rating, "D");
            }
            else if (Grades[i].finalGrade < 6.0 ) {
              strcpy(Grades[i].rating, "C");
            }
            else if (Grades[i].finalGrade < 7.0 ) {
              strcpy(Grades[i].rating, "C+");
            }
            else if (Grades[i].finalGrade < 8.0 ) {
              strcpy(Grades[i].rating, "B");
            }
            else if (Grades[i].finalGrade < 8.5 ) {
              strcpy(Grades[i].rating, "B+");
            }
            else if (Grades[i].finalGrade < 9.0 ) {
              strcpy(Grades[i].rating, "A");
            }
            else {
              strcpy(Grades[i].rating, "A+");
            }
        }
}



//Part g
void showGradeInfo(Grade_detail  Grades[], int n) {
    puts("List of grades");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",
    "ID","Student ID","Student name","Module ID","Module name","Attendance","Midterm","Homework","Finalterm","FinalGrade","Rating" );
    puts("---------------------------------------------------------------------------------------------------------------"
        "-------------------------------------------------------");
    for (int i = 0; i < n; i++) {
         printf("%-20s%-20s%-20s%-20s%-20s%-20.2f%-20.2f%-20.2f%-20.2f%-20.2f%-20s\n",
         Grades[i].grade_ID,Grades[i].AnewStudent.student_ID,Grades[i].AnewStudent.student_name,
         Grades[i].AnewModule.module_ID, Grades[i].AnewModule.module_name,
         Grades[i].attendance, Grades[i].midTerm, Grades[i].homework, Grades[i].finalTerm,
         Grades[i].finalGrade, Grades[i].rating);
    }
}


//Part h
//sắp xếp theo điểm tổng kết
void swap(Grade_detail * a, Grade_detail * b) {
    Grade_detail temp = *a;
    *a = *b;
    *b = temp;
}
void sort(Grade_detail Grades[],int n) {

    for (int i = 0; i < n - 1; i++) { //sắp xếp tối đa n – 1 lần
        for (int j = 0; j < n - i - 1;j++) {             
		if (Grades[j].finalGrade < Grades[j + 1].finalGrade) { 
                	swap(&Grades[j], &Grades[j + 1]);
            }
        }
    }
}
//Part i
void finalGradeEqualX(Grade_detail Grades[], int n, float x) {
    printf("Students with final grade equal to %.2f\n", x);
    printf("%-20s%-20s%-20s%-20s\n","ID","Name","Address","Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i  = 0; i < n; i ++) {   //tìm đc final grade trùng khớp thì in ra học sinh đó
        if (Grades[i].finalGrade == x ) {
             printf("%-20s%-20s%-20s%-20s\n", Grades[i].AnewStudent.student_ID, Grades[i].AnewStudent.student_name, Grades[i].AnewStudent.student_address, Grades[i].AnewStudent.student_major);
        } 
    }
}
//Part j
void RatingEqualY(Grade_detail Grades[], int n, char y[2]) {
    printf("Students with rating equal to %s\n", y);
    printf("%-20s%-20s%-20s%-20s\n","ID","Name","Address","Major");
    puts("--------------------------------------------------------------------------------------");
    for (int i  = 0; i < n; i ++) {   //tìm đc final grade trùng khớp thì in ra học sinh đó
        if (strcmp(Grades[i].rating, y) == 0 ) {
             printf("%-20s%-20s%-20s%-20s\n", Grades[i].AnewStudent.student_ID, Grades[i].AnewStudent.student_name, Grades[i].AnewStudent.student_address, Grades[i].AnewStudent.student_major);
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
    for ( int i = 0; i < n; i ++) {
        if (strcmp(Grades[i].grade_ID, ID_to_update) == 0) {
            Grades[i].attendance = newAttendance;
            Grades[i].midTerm = newMidterm;
            Grades[i].homework = newHomework;
            Grades[i].finalTerm = newFinalterm;
        }
    }
    
}
//Part l  //Ctrl + S

void writeStudentFile(char file_name[], Student_detail Students[], int n) {
    FILE * fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0 ; i < n; i++) {
        fwrite(&Students[i], sizeof(Student_detail),1, fp);
    }
    puts("Write students data successfully !");
    fclose(fp);
}

void writeModuleFile(char file_name[], Module_detail Modules[], int n) {
    FILE * fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0 ; i < n; i++) {
        fwrite(&Modules[i], sizeof(Module_detail),1, fp);
    }
    puts("Write modules data successfully !");
    fclose(fp);
}

void writeGradeFile(char file_name[], Grade_detail Grades[], int n) {
    FILE * fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0 ; i < n; i++) {
        fwrite(&Grades[i], sizeof(Grade_detail),1, fp);
    }
    puts("Write grades data successfully !");
    fclose(fp);
}
//Part m

void readStudentFile(char file_name[], Student_detail Students[], int *n) {
    FILE * fp;
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
void readModuleFile(char file_name[], Module_detail Modules[], int *n) {
    FILE * fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", file_name);
        return;
    }

    int i = 0;
    while (!feof(fp)) {
        fread(&Modules[i], sizeof(Module_detail), 1, fp);
        if (feof(fp)) {
            break;
        }
        i++;
    }
    
    *n = i;

    fclose(fp);
}
void readGradeFile(char file_name[], Grade_detail Grades[], int *n) {
    FILE * fp;
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

   


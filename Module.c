#include <stdio.h>
#include <string.h>
#include "Module.h"

//Part a
void getModuleInfo(Module_detail *AnewModule) { //cần thay đổi AnewModule nên phải truyền tham chiếu
    puts("Enter module ID: ");
    scanf("%*c%9s", AnewModule->module_ID);
    puts("Enter module name: ");
    scanf("%*c%19s", AnewModule->module_name);
    puts("Enter module credit: ");
    scanf("%d", &AnewModule->module_credit);
}

//Part b
void showModuleInfo(Module_detail Modules[], int n) {   //In từ mảng Modules
    puts("List of modules");
    printf("%-10s%-20s%-10s\n", "ID", "Name", "Credit");
    puts("-------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("%-10s%-20s%-10d\n", Modules[i].module_ID, Modules[i].module_name, Modules[i].module_credit);
    }
}

//Part e
//hàm tìm vị trí của một học phần trong danh sách Moules[] theo mã ID học phần
int indexFromModuleID(Module_detail Modules[], int number_of_modules, char ID_to_find[]) {
    for (int i = 0; i < number_of_modules; i++) {
        int match = strcmp(ID_to_find, Modules[i].module_ID);
        if (match == 0) {
            return i;
        }
    }
}

//Part l  //Ctrl + S
void writeModuleFile(char file_name[], Module_detail Modules[], int n) {
    FILE *fp;
    fp = fopen(file_name, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách học sinh

    for (int i = 0; i < n; i++) {
        fwrite(&Modules[i], sizeof(Module_detail), 1, fp);
    }
    puts("Write modules data successfully !");
    fclose(fp);
}

//Part m
void readModuleFile(char file_name[], Module_detail Modules[], int *n) {
    FILE *fp;
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

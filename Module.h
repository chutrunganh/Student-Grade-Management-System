#pragma once

typedef struct {
    char module_ID[10];
    char module_name[20];
    int module_credit;

} Module_detail;

//Part a
void getModuleInfo(Module_detail *AnewModule);

//Part b
void showModuleInfo(Module_detail Modules[], int n);

//Part e
int indexFromModuleID(Module_detail Modules[], int number_of_modules, char ID_to_find[]);

//Part l
void writeModuleFile(char file_name[], Module_detail Modules[], int n);

//Part m
void readModuleFile(char file_name[], Module_detail Modules[], int *n);

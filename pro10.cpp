#include<windows.h>
#include<stdio.h>
#include<stdlib.h>


int main() {
    int times;
    printf("�аݭn�I�X�U�G");
    scanf("%d", &times);
    system("pause");
    for (int x = 0;x < times;x++) {
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        printf("�I����%3d �U\n", x);
        Sleep(1); 
    }
    system("pause");
}
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>


int main() {
    int times;
    printf("請問要點幾下：");
    scanf("%d", &times);
    system("pause");
    for (int x = 0;x < times;x++) {
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        printf("點擊第%3d 下\n", x);
        Sleep(1); 
    }
    system("pause");
}
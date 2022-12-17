//
// Created by 50838 on 2022/12/2.
//
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include "windows.h"
using namespace std;


int trap(vector<int>& height) {
    int n = height.size();
    // left[i]表示i左边的最大值，right[i]表示i右边的最大值
    vector<int> left(n), right(n);
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], height[i + 1]);
    }
    int water = 0;
    for (int i = 0; i < n; i++) {
        int level = min(left[i], right[i]);
        water += max(0, level - height[i]);
    }
    return water;
}

int main(){

    vector<int> list = {6,1,0,5,4,7,0,1,8};
    printf("%d %c",trap(list),list.data());
/*
    HANDLE ConsoleWin;
    INPUT_RECORD eventMsg;
    DWORD Pointer ;


    ConsoleWin = GetStdHandle(STD_INPUT_HANDLE);//Get the console window

    while(1){
        ReadConsoleInput(ConsoleWin, &eventMsg, 1, &Pointer);//Read input msg
        if (eventMsg.EventType == MOUSE_EVENT && eventMsg.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
            printf("Right button clicked.\n");
        }
        if (eventMsg.EventType == MOUSE_EVENT && eventMsg.Event.MouseEvent.dwEventFlags == RIGHTMOST_BUTTON_PRESSED) {
            printf("Left button double clicked.\n");
        }
    }*/
    return 0;
}
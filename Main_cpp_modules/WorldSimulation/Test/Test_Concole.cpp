//
// Created by 20106 on 2022/11/4.
//
//#include "stdafx.h"
#include <windows.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

using namespace std;

HHOOK keyboardHook = 0;        // 钩子句柄

static bool type = true;

LRESULT CALLBACK LowLevelKeyboardProc(
        _In_ int nCode,        // 规定钩子如何处理消息，小于 0 则直接 CallNextHookEx
        _In_ WPARAM wParam,    // 消息类型
        _In_ LPARAM lParam    // 指向某个结构体的指针，这里是 KBDLLHOOKSTRUCT（低级键盘输入事件）
) {
    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT *) lParam;        // 包含低级键盘输入事件信息
    /*
    typedef struct tagKBDLLHOOKSTRUCT {
        DWORD     vkCode;		// 按键代号
        DWORD     scanCode;		// 硬件扫描代号，同 vkCode 也可以作为按键的代号。
        DWORD     flags;		// 事件类型，一般按键按下为 0 抬起为 128。
        DWORD     time;			// 消息时间戳
        ULONG_PTR dwExtraInfo;	// 消息附加信息，一般为 0。
    }KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
    */
    if (ks->flags == 128 || ks->flags == 129) {
        // 监控键盘
        switch (ks->vkCode) {
            /*case 0x30: case 0x60:
                cout << "检测到按键：" << "0" << endl;
                break;
            case 0x31: case 0x61:
                cout << "检测到按键：" << "1" << endl;
                break;
            case 0x32: case 0x62:
                cout << "检测到按键：" << "2" << endl;
                break;
            case 0x33: case 0x63:
                cout << "检测到按键：" << "3" << endl;
                break;
            case 0x34: case 0x64:
                cout << "检测到按键：" << "4" << endl;
                break;
            case 0x35: case 0x65:
                cout << "检测到按键：" << "5" << endl;
                break;
            case 0x36: case 0x66:
                cout << "检测到按键：" << "6" << endl;
                break;
            case 0x37: case 0x67:
                cout << "检测到按键：" << "7" << endl;
                break;
            case 0x38: case 0x68:
                cout << "检测到按键：" << "8" << endl;
                break;
            case 0x39: case 0x69:
                cout << "检测到按键：" << "9" << endl;
                break;*/
            case 0x41:
                cout << "检测到按键：" << "A" << endl;
                break;
                /*case 0x42:
                    cout << "检测到按键：" << "B" << endl;
                    break;
                case 0x43:
                    cout << "检测到按键：" << "C" << endl;
                    break;*/
            case 0x44:
                cout << "检测到按键：" << "D" << endl;
                break;
                /* case 0x45:
                     cout << "检测到按键：" << "E" << endl;
                     break;
                 case 0x46:
                     cout << "检测到按键：" << "F" << endl;
                     break;
                 case 0x47:
                     cout << "检测到按键：" << "G" << endl;
                     break;
                 case 0x48:
                     cout << "检测到按键：" << "H" << endl;
                     break;
                 case 0x49:
                     cout << "检测到按键：" << "I" << endl;
                     break;
                 case 0x4A:
                     cout << "检测到按键：" << "J" << endl;
                     break;
                 case 0x4B:
                     cout << "检测到按键：" << "K" << endl;
                     break;
                 case 0x4C:
                     cout << "检测到按键：" << "L" << endl;
                     break;
                 case 0x4D:
                     cout << "检测到按键：" << "M" << endl;
                     break;
                 case 0x4E:
                     cout << "检测到按键：" << "N" << endl;
                     break;
                 case 0x4F:
                     cout << "检测到按键：" << "O" << endl;
                     break;
                 case 0x50:
                     cout << "检测到按键：" << "P" << endl;
                     break;
                 case 0x51:
                     cout << "检测到按键：" << "Q" << endl;
                     break;
                 case 0x52:
                     cout << "检测到按键：" << "R" << endl;
                     break;*/
            case 0x53:
                cout << "检测到按键：" << "S" << endl;
                break;
                /* case 0x54:
                     cout << "检测到按键：" << "T" << endl;
                     break;
                 case 0x55:
                     cout << "检测到按键：" << "U" << endl;
                     break;
                 case 0x56:
                     cout << "检测到按键：" << "V" << endl;
                     break;*/
            case 0x57:
                cout << "检测到按键：" << "W" << endl;
                break;
                /*case 0x58:
                    cout << "检测到按键：" << "X" << endl;
                    break;
                case 0x59:
                    cout << "检测到按键：" << "Y" << endl;
                    break;
                case 0x5A:
                    cout << "检测到按键：" << "Z" << endl;
                    break;
                case 0x6A:
                    cout << "检测到按键：" << "*" << endl;
                    break;
                case 0x6B:
                    cout << "检测到按键：" << "+" << endl;
                    break;
                case 0x6D:
                    cout << "检测到按键：" << "-" << endl;
                    break;
                case 0x6E:
                    cout << "检测到按键：" << "." << endl;
                    break;
                case 0x6F:
                    cout << "检测到按键：" << "/" << endl;
                    break;
                case 0x0D:
                    cout << "检测到按键：" << "Enter" << endl;
                    break;
                case 0xA0: case 0xA1:
                    cout << "检测到按键：" << "Shift" << endl;
                    break;*/
            case 0x08:
                cout << "检测到按键：" << "Backspace" << endl;
                type = false;
                break;
            case 0x20:
                cout << "检测到按键：" << "Space" << endl;
                break;
        }

        //return 1;		// 使按键失效
    }

    // 将消息传递给钩子链中的下一个钩子
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int MonitorKeyboard() {
    system("chcp 65001");
    // 安装钩子
    keyboardHook = SetWindowsHookEx(
            WH_KEYBOARD_LL,            // 钩子类型，WH_KEYBOARD_LL 为键盘钩子
            LowLevelKeyboardProc,    // 指向钩子函数的指针
            GetModuleHandleA(NULL),    // Dll 句柄
            NULL
    );
    if (keyboardHook == 0) {
        cout << "挂钩键盘失败" << endl;
        return -1;
    }

    //不可漏掉消息处理，不然程序会卡死
    MSG msg;
    while (type) {
        // 如果消息队列中有消息
        if (PeekMessageA(
                &msg,        // MSG 接收这个消息
                NULL,        // 检测消息的窗口句柄，NULL：检索当前线程所有窗口消息
                NULL,        // 检查消息范围中第一个消息的值，NULL：检查所有消息（必须和下面的同时为NULL）
                NULL,        // 检查消息范围中最后一个消息的值，NULL：检查所有消息（必须和上面的同时为NULL）
                PM_REMOVE    // 处理消息的方式，PM_REMOVE：处理后将消息从队列中删除
        )) {
            // 把按键消息传递给字符消息
            TranslateMessage(&msg);
            printf("%c\n", msg);
            // 将消息分派给窗口程序
            DispatchMessageW(&msg);
        } else
            Sleep(0);    //避免CPU全负载运行
    }
    // 删除钩子
    UnhookWindowsHookEx(keyboardHook);
}

//int _tmain(int argc, _TCHAR *argv[]) {
//    MonitorKeyboard();
//
//    return 0;
//}
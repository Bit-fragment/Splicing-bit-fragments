//
// Created by 50838 on 2022/12/20.
//
#include <vector>
#include <iostream>

using namespace std;

/*
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 输入: nums = [0,1,0,3,12] 输出: [1,3,12,0,0]
 * */
void outVector(vector<int> &list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    void moveZeroes(vector<int> &nums) {

    }

    void move(vector<int> &pi) {
        outVector(pi);
        for (int i = 0; i < pi.size(); i++) {
            int var = pi[i];
            pi[i] = pi[pi.size() - 1 - i];
            pi[pi.size() - 1 - i] = var;
        }
        outVector(pi);
    }
};

int main() {
    vector<int> list = {1, 9, 0, 6, 2};
    Solution solution;
//    outVector(list);
    solution.move(list);
//    outVector(list);
    return 0;
}

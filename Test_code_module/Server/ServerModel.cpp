#include <iostream>
#include "Service/ServiceObject.h"
#include <valarray>

using namespace std;

int main() {
    DataGenerator dg;
    valarray<int> list = dg.getRandomNumberArray(10);
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
    }
    return 0;
}
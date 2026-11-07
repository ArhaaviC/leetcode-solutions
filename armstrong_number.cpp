//check whether a number is armstrong or not

#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    if (n < 0) return false;

    int original = n;
    int numOfDigits = 0;

    // count digits (on a copy, so original n isn't destroyed)
    int temp = n;
    while (temp > 0) {
        numOfDigits++;
        temp /= 10;
    }

    int sum = 0;
    temp = n;
    while (temp > 0) {
        int lastDigit = temp % 10;

        int power = 1;                       // compute lastDigit^numOfDigits
        for (int i = 0; i < numOfDigits; i++)
            power *= lastDigit;

        sum += power;
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cin >> n;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong");
    return 0;
}
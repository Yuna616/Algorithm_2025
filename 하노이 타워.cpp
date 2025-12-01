#include <iostream>
using namespace std;

int countH = 0;

void move(int from, int to)
{
    countH++;
    cout << countH << ": ";
    if (countH == 17) {
        printf("%d -> %d Special!!\n", from, to);
    }
    else {
        printf("%d -> %d\n", from, to);
    }
}

void Hanoi(int n, int from, int usingK, int to)
{
    if (n == 1) {
        move(from, to);
    }
    else {

        Hanoi(n - 1, from, to, usingK); 

        move(from, to);

        Hanoi(n - 1, usingK, from, to); 
    }
}

int main(void)
{
    int numDisks = 6;
    printf("Number of disks to move: %d\n", numDisks);
    Hanoi(numDisks, 1, 2, 3);
}

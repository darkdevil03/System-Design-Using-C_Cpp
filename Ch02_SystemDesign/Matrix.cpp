#include <iostream>

using namespace std;

int main() {

    int mat_arr[2][2]= {{2,2},{2,2}};

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout << mat_arr[i][j];
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}
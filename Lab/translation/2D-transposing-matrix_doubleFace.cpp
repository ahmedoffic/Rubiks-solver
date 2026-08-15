#include <iostream>
using namespace std;

void tranRot(int baseMat[3][3]){
    int matLength = 3;
    int newMat[3][3];
    int finMat[3][3];

    //Copy baseMat to newMat
    for(int r=0;r<matLength;r++){
        for(int c=0;c<matLength;c++){
                newMat[r][c] = baseMat[c][r];
        }
    }

    //Print Out finale mat
    for(int r=0;r<matLength;r++){
            cout << "{";
        for(int c=0;c<matLength;c++){
                if(c==2){
                    cout << " "<<newMat[r][c] << "}";
                }else{cout << " "<<newMat[r][c] << ",";}
        }
        cout << endl;
    }
}

int matrix_transpose()
{
    int mat_A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    tranRot(mat_A);
    return 0;
}

/*
Mat A

1 2 3
4 5 6
7 8 9
rotated
1 4 7
2 5 8
3 6 9

r1c1 r1c2 r1c3
r2c1 r2c2 r2c3
r3c1 r3c2 r3c3

after translation

r,c
temp_r = r
temp_c = c
#after translation
temp_r = c
temp_c = r

iteration inside the matrix
baseMat


r c
c c
*/

#include <iostream>

using namespace std;

void MatTranspose(int base_matrix[3][3],int dir, int rep){
    int len=3; //Length of the Matrix
    int resMat[3][3]; //Resulted Matrix
    for(int i=0;i<rep;i++){ //repeating
        if(dir<0){ //Transposing CW
            for(int r=0;r<len;r++){ //row
                for(int c=0;c<len;c++){ //column
                    resMat[c][len-r-1] = base_matrix[r][c];
                }
            }
        }
        if(dir>0){//Transposing Anti-CW
            for(int c=0; c<len;c++){
                for(int r=0; r<len; r++){
                    resMat[c][r] = base_matrix[r][len-c-1];
                }
            }
        }
        //re-assign value of temp_matrix to base_matrix
        for(int r=0;r<len;r++){for(int c=0;c<len;c++){base_matrix[r][c] = resMat[r][c];}}
    }
    //Print Result
    for(int r=0;r<len;r++){
        cout << "{";
        for(int c=0;c<len;c++){if(c==2){cout << base_matrix[r][c];}else{cout << base_matrix[r][c]<<",";}}
        cout << "}\n";
    }
}

int main(){
    int matA[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    MatTranspose(matA,1,1);
    return 0;
}


/*

mat A
1 2 3
4 5 6
7 8 9

inverse transpose
dir: 1 rep: 1
7 4 1
8 5 2
9 6 3

dir rep
'+ve & -ve' '0<n'

dir>0
      3-1=2
len-1 012

Core:
    len-r:
        subtract col then make row equal col
        -> mat[c][r]
        3-r-1
        3-0-1 = 2col
        [0:0, 0:1, 0:2]
        [1:0, 1:1, 1:2]
        [2:0, 2:1, 2:2]

        3-2-1 = 3-2-1 = 0
        [2:0, 1:0, 0:0]
        [2:1, 1:1, 0:1]
        [2:2, 1:2, 0:2]

        [2:2, 2:1, 2:0]
        [1:2, 1:1, 1:0]
        [0:2, 0:1, 0:0]

1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3

9 8 7
6 5 4
3 2 1
*/

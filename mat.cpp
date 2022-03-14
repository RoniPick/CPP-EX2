#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace ariel{
    //x1 = row, x2 = col
    string mat (int x1, int x2, char char1, char char2){
        vector <vector<char>> mat(x2, vector<char>(x1));

        if(x1<=0 || x2<=0){
            throw invalid_argument("Error, please enter positive numbers");
        }

        if(x1%2 == 0 || x2%2 == 0){
            throw invalid_argument("Error, please enter odd numbers");
        }

        // magic numbers
        const int max = 126;
        const int min = 33;

        if(char1<min || char1>max || char2<min || char2>max){
            throw invalid_argument("Error, wrong char input");
        }

        //filling all the matrix in the second char in order to fill the first char in the current places
        for(int i=0; i<x2; i++){
            for(int j=0; j<x1; j++){
                mat[i][j] = char2;
            }
        }

        int indexL=0; // left index
        int indexU=0; // up index
        int indexR=x2-1;
        int indexD=x1-1;

         //up <= down ans left<=right
        while(indexU<=indexD && indexL<=indexR){
            //row filling
            for(int i=indexL; i<=indexR; i++){
                mat[i][indexU] = char1;
                mat[i][indexD] = char1;
            }
            //col filling
            for(int i=indexU; i<=indexD; i++){
                mat[indexL][i] = char1;
                mat[indexR][i] = char1;
            }

            indexU+=2;
            indexD-=2;
            indexL+=2;
            indexR-=2;
        }

        /* in order to print the matrix I created a main string and a temporary string,
         * each row I entered the row to the temp string, adding the char '\n' at the end, and adding the
         * temp string to the main string that I return as answer
         */
        string out;
        for(int i=0; i<x2; i++){
            string temp;
            for(int j=0; j<x1; j++){
                temp += mat[i][j] ;
            }
            temp += "\n";
            out += temp;
        }
        return out;
    }
}
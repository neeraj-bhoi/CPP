/*
matrix manipulation program
*/

#include<bits/stdc++.h>
using namespace std;

class matrix {
    int rows, columns;
    int** arr_matrix;

    public :
        matrix(){}
        matrix(int rows, int columns) {
            this -> rows = rows;
            this -> columns = columns;
            cout<<"rows "<<rows<<" columns "<<columns<<endl;

            //dyanamic memory allocation
            arr_matrix = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                arr_matrix[i] = new int[columns];
            }
        }

        //taking matrix input
        void setter() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    cin>>this -> arr_matrix[i][j];              //insertion
                }
            }
        }

        //display function
        void display() {
            cout<<"\n\nrows "<<rows<<" columns "<<columns<<endl;
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    cout<<arr_matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        //operator overloading for addition
        matrix operator +(matrix &m) {
            matrix temp(m.rows, m.columns);

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    temp.arr_matrix[i][j] = this -> arr_matrix[i][j] + m.arr_matrix[i][j];
                }
            }

            return temp;
        }

        //subtraction operater overloaded
        matrix operator -(matrix &m) {
            matrix temp(m.rows, m.columns);

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    temp.arr_matrix[i][j] = this -> arr_matrix[i][j] - m.arr_matrix[i][j];
                }
            }

            return temp;
        }

        ~matrix() {
            cout<<"destructor called"<<endl;
            // delete *arr_matrix;
            for (int i = 0; i < rows; ++i) 
                delete[] arr_matrix;
            delete[] arr_matrix;
        }
};

int main() {
    cout<<"\n\n";
    matrix m1(2,2);
    m1.setter();
    cout<<endl;

    matrix m2(2,2);
    m2.setter();
    cout<<endl;

    //addition
    matrix m3;
    m3 = m1+m2;
    m3.display();

    //subtraction
    m3 = m1-m2;
    m3.display();
}
#include<bits/stdc++.h>
using namespace std;

class marksheet {
    int physics;
    int chemistry;
    int maths;
    float percentage;
    string grade;

    public :
        void setter(int physics, int chemistry, int maths) {
            this -> physics = physics;
            this -> chemistry = chemistry;
            this -> maths = maths;
            percentage = (physics + chemistry + maths) / 3;
        }

        float get_percentage() {
            return percentage;
        }

        string get_grade() {
            if(percentage >= 90) {
                return "A+";
            } else if(percentage >= 80 && percentage < 90) {
                return "A";
            } else if(percentage >= 60 && percentage < 80) {
                return "B";
            } else if(percentage >= 50 && percentage < 60) {
                return "c";
            } else if(percentage >= 33 && percentage < 50) {
                return "D";
            } else {
                return "F";
            }
            return "Z";
        }

        ~marksheet() {
            cout<<"\nmarksheet destroyed";
        }
};

class student {
    string name;
    int class_name;
    marksheet m;
    static int student_count;

    public :
        student(string name, int class_name, int physics, int chemistry, int maths) {
            this -> name = name;
            this -> class_name = class_name;
            m.setter(physics, chemistry, maths);
            student_count++;
        }

        void display() {
            cout<<"\n\n name = "<<this -> name;
            cout<<"\n class = "<<this -> class_name;
            cout<<"\n percentage = "<<m.get_percentage()<<"%";
            cout<<"\n grade = "<<m.get_grade();
            // cout<<"\n student count = "<<student_count<<endl;
        }

        ~student (){
            cout<<"\nstudent finished";
        }
};

int student :: student_count = 0;

int main() {

    student s1("neeraj", 12, 99, 99, 99);
    student s2("akash", 12, 85, 85, 85);
    student s3("amit", 12, 65, 65, 65);
    student s4("akhil", 12, 30, 30, 30);
    s1.display();
    s2.display();
    s3.display();
    s4.display();


    // cout<<"student count "<<student::student_count;
    cout<<"\n\n------main ended--------";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class student {
    int marks;
    string name;

    public :

        student () {};
        student (string name = "", int marks = 0) {
            this -> name = name;
            this -> marks = marks;
        }

        void update_marks(student &s) {
            marks += s.marks;
            cout<<"\nstudent mark incremented ";
        }

        void display() {
            cout<<"\n"<<name<<"    "<<marks;
        }
};

void display(student &s) {
    s.display();
}

int main() {
    
    student s1("neeraj", 90);
    student s2("akash", 50);
    s1.update_marks(s2);
    student s3 = s2;

    s1.display();
    s2.display();
    s3.display();

    cout<<"\n\n";

    display(s1);

    cout<<endl;
    return 0;
}
#ifndef STUDENT_HPP
#define STUDENT_HPP

    //Header Files
    #include<bits/stdc++.h>
    using namespace std;

    class marksheet {
        int physics;
        int chemistry;
        int maths;
        float percentage;
        string grade;

        public :
        void setter(int physics, int chemistry, int maths);
        float get_percentage();
        string get_grade();
        //destructor  
        ~marksheet();      
    };

    class student{
        string name;
        int class_name;
        marksheet m;
        static int student_count;

        public:
            //constructor
            student();
            //parameterized constructor
            student(string name, int class_name, int physics, int chemistry, int maths);
            void display();
            //destructor
            ~student();
    };

#endif
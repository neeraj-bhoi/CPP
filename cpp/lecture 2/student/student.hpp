    //header files
#ifndef STUDENT_HPP
#define STUDENT_HPP
    //declerations
    #include<string>
    using namespace std;

class communication_details {

};

class date {
    unsigned short int day, month, year;

    public:
        date(int day, int month, int year) {

        }

        //setter

        //getter

        void display() {

        }
};

class student {
    int rollno;
    string name;
    unsigned short int study_year;
    string branch;
    communication_details com_details;
    date dob;
    
    static string collage_name;

    public:
        //constructrors

        //getters

        //setters
};


#endif  //STUDENT_HPP

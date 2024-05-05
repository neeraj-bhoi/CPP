#include<bits/stdc++.h>
using namespace std;

class myexception {
    char message[100];
    int num;
    public :
        myexception() {
            message[0] = '\0';
            num = 0;
        }
        myexception(const char *msg, int n) {
            strcpy(message, msg);
            num = n;
        }

        char *get_message() {
            return message;
        }

        void set_message(const char * msg) {
            strcpy(message, msg);
        }

        int get_num() {
            return num;
        }
};

class anotherexception : public myexception {
    private :
        int code;
    public :
        anotherexception() :myexception(){
            code = 0;
        }

        anotherexception(int code) {
            this -> code = code;
        }

        anotherexception(int code, const char * msg, int num) :myexception(msg, num) {
            this -> code = code;
        }

        int get_code() {
            return code;
        }
};

int main() {
    cout<<"main started....\n\n";

    int x;
    try {
        cout<<"enter the number : ";
        cin>>x;

        if(x < 0) {
            throw myexception("number is less than 0. ", x);
        } else if(x > 0 && x < 18){
            throw x;
        } else if(x > 100) {
            throw anotherexception(404, "out of range value. ", x);
        } 

        cout<<"Entered num is in range(18 - 100) ."<<endl;
        // throw 2.22;    // default catch will be called here

    }  catch (anotherexception e) {
        cout<<" catch block..."<<e.get_code()<<" "<<e.get_message()<<" "<<e.get_num()<<endl;
    }  catch(myexception e) {
        cout<<" catch block..."<<e.get_message()<<" "<<e.get_num()<<endl;
    } catch (int x) {
        cout<<" catch block..."<<"the number in range 0 - 18"<<endl;
    } catch(...) {                      // default catch
        cout<<" all exceptions caught here...."<<endl;
    }
    

    cout<<"\nmain ended..........";
    return 0;
}
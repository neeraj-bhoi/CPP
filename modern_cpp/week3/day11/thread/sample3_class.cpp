/*
    producer consumer problem!

    2 worker in your program
        1 _may
*/


/*
    2 threads (2 workers)
     -main thread (producer) : take input and maek "make value available"
     -operation (T1)[CONSUMER]: oNCE A SIGNAL IS RECIVED FROM  MAIN TO INDICATE "INPUT RECIEVED", CALCULATE THE SQUARE

     A) PROGRAMMER CALCULTES HOW MANY WORKERS ARE REQUIRED AND TRIGGERS THEM AT A TIME [THREAD POOLING!]

     B) T1 MAY WANT TO DO SOME OTHRE WORK EVEN BEFORE DATA INPUT
*/

/*
    PROCESS / THREAD : CONCREATE DIFFERENCE YA ABSTRACT
*/

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

int value = 0;
bool flag = false;
std::mutex mt;
std::condition_variable cv;

void Operaation()
{
    int *ans  = (int* ) malloc(4); // 4 bytes for an integer
    std::unique_lock<std::mutex> ul(mt);    //if false -> 
    cv.wait(ul, [&](){return flag;});
    *ans  = value * value;
    std::cout << "Square of " << value << "is: " << *ans;
    free(ans);
}

void takeinput()
{
std::lock_guard<std::mutex> lg(mt);

    //TAKE INPUT FROM USER INTO GLOBAL VARIABLE

    std::cin>>value;
}
 
int main()
{
    //step 1 : thread instantiated.
    //a new thread is now VilBLE TO SCHEDULED . (AS GOOD AS ALEARDY STARTED)

    std::thread t1 (& Operaation);

    //APPLY LOCK ON MUTEX. LOCK WILL APPLIED TILL END OF MAIN
    //NO THER THTREAD CAN APPLY LOCK ON THE SAME MUTEX BEFORE MAIN

    takeinput();

    flag = true;
    //SEND A SIGNAL
    cv.notify_one();

    //WAIT FOR OPERQTION TO FINIAH VEFORE
    t1.join();
}


/*
    main starts ---------------->[takeInput]------[lock_guard]---take input----

        -create thread t1.------>[malloc]----[unique_lock]--condition_check[false]----wait state..
*/
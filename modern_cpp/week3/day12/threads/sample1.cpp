/*
    Threads : 
        1)  std::thread : they can by used for parallel/concurrent tasks.
                they need to be joined or detached.
                they do not catch the return values.

        2)  std::condition_variables : in situations where one thread has to wait for an event
                to happen because of some other thread before completiion
                due to other operations, such threads may do some work before the event,
                hense are launched simultaneously.

        3)  Container of std::threads : To manage multiple instances of thread efficiently.
                eg. map to functions, join ets.

        4)  std::mutex vs std::lock_guard vs std::unique_lock
                - std::mutex can be locked and unlocked manually only. (not preferable)
                - std::lock_guard : (better version of mutex).. ,
                    scope-based,
                    RAII principle following mutes,
                    no manual lock/unlock
                - unique-lock : scope-based as well as manual lock/unlock.

        //synchronization primitives

        5)  real-life

            - mercedes : Navigation / Music

            --->unlock()--->start the accessories / electronics

                --->load surrounding/favourites/emergency actions--------> input[location]----
            --->
                --->Music


        5.1) std::future , std::async , std::promise
*/
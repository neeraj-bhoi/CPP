/*
    object : represent "state" of "something"!
*/

class ID{
    /*
        _country : IN
        _year : 24
        _month : 01
        _track_level : LEVEL
        _batch :01
        _location : optional
        _track_name : Track
    */
};

class TrainingBatch{
    /*
        _id : ID
        _strength : unsigned int
        _trainer : Trainer------------------------  EMPLOYEE
        _pmt_coordinator : Coordinator------------  EMPLOYEE
        _schedule : Schedule
        _talents : Container<Talent>
    */
};

class TrainingSession {
    private:
    /*
        duration (in hours) : int
        student_count : unsigned int
        trainername : string
        session_topic : string
        date : DateTime
    */
    
    public:
        TrainingSession();
        ~TrainingSession();

};  //represent state
//one instance represents one state of training session

/*

    pointer ka state representation
            --> Smart pointers
    reference ka state representation
            -->referende_wrapper
    Thread (set of instructions)
            --> std::async
    Semaphore ka state
            -->lock_guard
            -->unique_lock
    union ka state representation
            -->std::variant

*/
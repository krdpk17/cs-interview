schedular (queue task, dequeue task, cancel_task)
/*
Schedule the task

APIs
    Enqueue
        Input: Task Object, priority
        Output: Task ID
    Dequeue
        Input : None
        Output: Top of the queue
    Cancel
        Input: Task ID
        Output: Boolean
    
    
    QueueSize: //Not now
        Current Queue

Parallelism
    Single threaded/multi thread
        API should be thread safe

Design pattern
    Singleton object

*/

struct TaskObject{
    
};

class TaskManager{
public:
    static TaskManager * getInstance();
    int enqueueTask(TaskObject *p_tObj, int priority){
        //sanity check for priority range (0... N)
        //no duplicate..every time it will be separate task
        
        //start mutex
        static int id = 0;
        priority_queue[priority].push_back(p_tObj);
        ++id;
        //end mutex
        
        return id;
        
    }
    
    TaskObject* dequeueTask(){
        
    }
    
    bool cancelTask(int task_id){
        
    }

private:
    vector<vector<TaskObject *>> priority_queue;
};

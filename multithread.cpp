#include<pthread.h>
#include<iostream>
#include<unistd.h>
/*
g++ -lpthread multithread.cpp
*/
/*
TODO:
1. Fix starvation issue - done
2. Make single entry function 
*/

using namespace std;
int snumEven=2;
int snumOdd=1;
int maxVal = 10;//maximum value to print
int jump = 2;
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t my_cond_odd_t = PTHREAD_COND_INITIALIZER; 
pthread_cond_t my_cond_even_t = PTHREAD_COND_INITIALIZER; 
int done = 1;
int ready = 0;
struct timespec timeout;

/*
Thread to print even values
*/
void * even_thread_entry(void *data){
    int startval = *((int *)data);
    int currVal = startval;
    while(1){
        pthread_mutex_lock(&my_mutex);
        // Set a timeout of 5 seconds
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 3;
        pthread_cond_timedwait(&my_cond_even_t, &my_mutex, &timeout);
        if(done == 2){//my turn
            cout<<currVal<<" ";
            done = 1;
            currVal+=2;
        }
        pthread_cond_signal(&my_cond_odd_t); // give turn to odd printing thread
        pthread_mutex_unlock (&my_mutex);
        if(currVal > maxVal){
            return nullptr;
        }
    }
}

/*
Thread to print odd values
*/
void * odd_thread_entry(void *data){
    int startval = *((int *)data);
    int currVal = startval;
    while(1){
        pthread_mutex_lock(&my_mutex);
        ready = 1;
        // Set a timeout of 5 seconds
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 5;
        pthread_cond_timedwait(&my_cond_odd_t, &my_mutex, &timeout);
        if(done == 1){//my turn
            cout<<currVal<<" ";
            done = 2;
            currVal+=2;
        }
        pthread_cond_signal(&my_cond_even_t); // give turn to even printing thread
        pthread_mutex_unlock (&my_mutex);
        
        if(currVal > maxVal){
            return nullptr;
        }
    }
}

int main(){
    pthread_t thread1, thread2;
    int t1, t2;
    void *status = nullptr;
    t1 = pthread_create(&thread1, nullptr, odd_thread_entry, &snumOdd);
    t2 = pthread_create(&thread2, nullptr, even_thread_entry, &snumEven);

    while(!ready){//thread is not ready
        sleep(1);
    }
    sleep(1);// give time to thread for waiting on cond variable
    pthread_cond_signal(&my_cond_odd_t);
    cout<<endl;
    pthread_join(thread1, &status);
    pthread_join(thread2, &status);
}
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
int maxVal = 10;
int jump = 2;
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t my_cond_odd_t = PTHREAD_COND_INITIALIZER; 
pthread_cond_t my_cond_even_t = PTHREAD_COND_INITIALIZER; 
int done = 1;
int ready = 0;
struct timespec timeout;


void * even_thread_entry(void *data){
    int startval = *((int *)data);
    int currVal = startval;
    while(1){
        pthread_mutex_lock(&my_mutex);
        // Set a timeout of 5 seconds
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 3;
        pthread_cond_timedwait(&my_cond_even_t, &my_mutex, &timeout);
        if(done == 2){
            cout<<currVal<<" ";
            done = 1;
            currVal+=2;
        }
        pthread_cond_signal(&my_cond_odd_t);
        pthread_mutex_unlock (&my_mutex);
        if(currVal > maxVal){
            return nullptr;
        }
    }
}

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
        if(done == 1){
            cout<<currVal<<" ";
            done = 2;
            currVal+=2;
        }
        pthread_cond_signal(&my_cond_even_t);
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

    while(!ready){
        pthread_cond_signal(&my_cond_odd_t);
    }
    sleep(1);// give time to thread for waiting on cond variable
    pthread_cond_signal(&my_cond_odd_t);
    cout<<endl;
    pthread_join(thread1, &status);
    pthread_join(thread2, &status);
}
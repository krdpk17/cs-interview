#include<pthread.h>
#include<iostream>
#include<unistd.h>
/*
g++ -lpthread multithread.cpp
*/
using namespace std;
int snumEven=2;
int snumOdd=1;
int maxVal = 10;
int jump = 2;
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t my_cond = PTHREAD_COND_INITIALIZER; 
int done = 1;



void * even_thread_entry(void *data){
    int startval = *((int *)data);
    int currVal = startval;
    while(1){
        pthread_mutex_lock (&my_mutex);
        if(done == 2){
            cout<<currVal<<endl;
            done = 1;
            currVal+=2;
        }
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
        pthread_mutex_lock (&my_mutex);
        if(done == 1){
            cout<<currVal<<endl;
            done = 2;
            currVal+=2;
        }
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
    pthread_join(thread1, &status);
    pthread_join(thread2, &status);
}
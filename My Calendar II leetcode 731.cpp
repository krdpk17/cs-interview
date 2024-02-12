#include<list>

struct BookingTwo{
    int start;
    int end;
    struct BookingTwo *next;
    BookingTwo(int start, int end){
        this->start = start;
        this->end = end;
        this->next = NULL;
    }
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        head = NULL;
    }

    BookingTwo* count_intersect(int start, int end, BookingTwo* currNode, int& count){
        BookingTwo *intersectionNode = NULL;
        if(end <= currNode->start || start >= currNode->end){//new interval is fully in left or fully in right
            //cout<<"["<<start<<","<<end<<"] "<<" curr start = ["<<currNode->start<<","<<currNode->end<<"] "<<"TRUE"<<endl;
            return NULL;
        }else if(start < currNode->start && end < currNode->end){// left intersecting
            intersectionNode = new BookingTwo(currNode->start, end);
            ++count;
        }else if((start >= currNode->start) && (end > currNode->end)){//right intersecting
            intersectionNode = new BookingTwo(start, currNode->end);
            ++count;
        }else if((start <= currNode->start) && (end < currNode->end)){//new interval is subset
            //cout<<"["<<start<<","<<end<<"] "<<"FALSE";
            ++count;
            intersectionNode = new BookingTwo(start, end);
        }else if((start <= currNode->start) && (end >= currNode->end)){//new interval is superset
            ++count;
            intersectionNode = new BookingTwo(currNode->start, currNode->end);
        }

        return intersectionNode;
    }

    bool findIntersectingNode(list<BookingTwo*>& intersectingNodesList){
        BookingTwo* currNode = NULL;
        int count = 0;
        for(list<BookingTwo*>::iterator it = intersectingNodesList.begin();
                it != intersectingNodesList.end(); ++it){
            currNode = *it;
            list<BookingTwo*>::iterator it2 = it;
            ++it2;
            count = 0;
            for(;it2 != intersectingNodesList.end(); ++it2){
                    count_intersect(currNode->start, currNode->end, *it2, count);
                    if(count){
                        return true;
                    }
            }

        }
        return false;
    }

    bool book(int start, int end) {
        BookingTwo* currNode = head;
        BookingTwo* prev = NULL;
        BookingTwo* intersectingNode = NULL;
        list<BookingTwo*> intersectingNodesList;
        //bool found = false;
        /*find the place. 
        If found, insert the interval
        If not, return false*/
        int intersectionCount = 0;
        while(currNode){
            intersectingNode = count_intersect(start, end, currNode, intersectionCount);
            if(intersectingNode){
                intersectingNodesList.push_back(intersectingNode);
            }
            
            prev = currNode;
            currNode = currNode->next;
        }

        if(intersectionCount >= 2){
            if(findIntersectingNode(intersectingNodesList)){//found triple booking
                return false;
            }
        }

        cout<<"["<<start<<","<<end<<"]"<<"count = "<<intersectionCount<<" "<<endl;
        // insert the node at the end
        BookingTwo* newNode = new BookingTwo(start, end);
        if(!prev){//insert at the head
            head = newNode;
        }else{
            //cout<<"["<<start<<","<<end<<"] "<<" prev start = ["<<prev->start<<","<<prev->end<<"] "<<"TRUE"<<endl;
            prev->next = newNode;
        }

        return true;
    }
   BookingTwo* head;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
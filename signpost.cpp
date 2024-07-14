#include <iostream>
#include<list>
#include<vector>
#include<map>

using namespace std;
/*Enum to maintain the signpost*/
enum SIGN_POST{
    DEFAULT = 0,
    CITY,
    ENDCITY,
    SCHOOL,
    ENDSCHOOL,
    CONSTRUCTION,
    ENDCONSTRUCTION
};

/*
Maintains sign post and corresponding speed 
*/
struct travelSignpostInfo{
    int signpost;
    int speed;
    travelSignpostInfo(int signpost, int speed){
        this->signpost = signpost;
        this->speed = speed;
    }
};

class SelfCarDriving{

public:
    SelfCarDriving(vector<int> signposts){
        m_signposts = signposts;
        //fill up the speed values
        signpost_speed[DEFAULT] = 55;
        signpost_speed[CITY] = 45;
        signpost_speed[SCHOOL] = 25;
        
    }

    /*this function helps to change the implementation approach
    Current approach -> Start index is preceding to end
    */
    int get_start_signpost(int end_sign_post){
        return end_sign_post - 1;
    }

    /* Remove entry from travel list*/
    void remove_start_entry_from_travel_list(int end_sign_post){
        int start_sign_post = get_start_signpost(end_sign_post);
        list<travelSignpostInfo>::iterator it;
        for(it = travel_list.begin(); it !=travel_list.end(); ++it){
            travelSignpostInfo entry = *it;
            if(entry.signpost == start_sign_post){
                travel_list.erase(it);
                return;
            }
        }
    }

    /*to get current max speed*/
    int get_curr_max_speed(int currentLocation){
        //check boundary case
        int sign_post = m_signposts[currentLocation];
        int new_speed = -1;
        //int last_sign_post;
        if(sign_post == ENDCITY || sign_post == ENDSCHOOL ||  sign_post == ENDCONSTRUCTION){
            //remove the corresponding start entry from the list
            remove_start_entry_from_travel_list(sign_post);
            //get the new speed
            if(travel_list.empty()){
                new_speed = signpost_speed[DEFAULT];
            }else{
                travelSignpostInfo last_sign_post_entry = travel_list.back();
                new_speed = last_sign_post_entry.speed;
            }
        }else{//signpost is start
            if(sign_post == CONSTRUCTION){//calculate new speed
                travelSignpostInfo last_sign_post_entry = travel_list.back();
                new_speed = last_sign_post_entry.speed / 2;
            }else{
                new_speed = signpost_speed[sign_post];
            }
            //add to the travel list
            travelSignpostInfo new_sign_post_entry(sign_post, new_speed);
            travel_list.push_back(new_sign_post_entry);
        }
        return new_speed;
    }


private:
    list<travelSignpostInfo> travel_list;//maintain travel list
    vector<int> m_signposts; //maintains the signposts list
    map<int, int> signpost_speed; //maintains mapping between sign post and speed (except CONSTRUCTION)
};



int main() {
    vector<int> signpost_list;
    signpost_list.push_back(DEFAULT);
    signpost_list.push_back(CITY);
    signpost_list.push_back(SCHOOL);
    signpost_list.push_back(CONSTRUCTION);
    signpost_list.push_back(ENDCITY);
    signpost_list.push_back(ENDCONSTRUCTION);
    signpost_list.push_back(ENDSCHOOL);

    SelfCarDriving selfCarDriving(signpost_list);
    //std::cout << "current speed " << selfCarDriving.getCurrMaxSpeed(0)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(1)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(2)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(3)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(4)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(5)<< std::endl;
    std::cout << "current speed " << selfCarDriving.get_curr_max_speed(6)<< std::endl;
    return 0;
}

/**
 * Given the array of rectangle shape, perform compression
 * Each quadrent should be compressed
 * Ensure to output in such a way that it can be decompressed
 * 
*/

//compression criteria
// it should be square
#include <iostream>

struct compressed_list_node{
    int compressed_val;
    int start_row_index;
    int start_col_index;
    int quadrent_size;
    struct compressed_list_node *next;
    compressed_list_node(int val){
        this->compressed_val = val;
        this->next = NULL;
    }
};

int input[8][8] = { {2,2,3,3,2,2,3,3},  
{2,2,3,3,2,2,3,3},  
{1,2,5,5,5,5,5,5}, 
{1,1,1,1,1,5,5,5}, 
{1,1,1,1,1,7,4,4}, 
{1,1,1,1,1,7,4,4},  
{1,1,1,1,1,5,5,5}, 
{1,1,1,1,1,5,5,5}
};
i = 0, 
j = 0, 1

i = 1
j = 0

struct compressed_list_node * output_list_head = NULL;

bool add_output_to_list(int val, int ){
    compressed_list_node *new_node = new compressed_list_node(val);
    if(!output_list_head){
        output_list_head =  new_node;
    }
}

int ** compress(){
    //find the quadrent
    int i = 0;
    int j = 0;
    int curr_val = input[0][0];
    int col_max = -1;
    int curr_col_max = -1;
    int row_max = -1;
    //int curr_row_max = -1;
    //get the rectangle
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){//find max extent/col in specific row
            if(input[i][j] != curr_val){
                curr_col_max = j-1;
                if(col_max == -1){//first row
                    col_max = curr_col_max;
                }else if(curr_col_max < col_max){// we need to get rectangle
                    col_max = curr_col_max;
                }
                break;
            }
        }
        //outer loop check
        if(input[i+1][0] != curr_val){// check array overflow
            row_max = i;
            break;               
        }

    }

    //extract quadrent out of it
    int starter = 1;
    while((starter < col_max) && (starter < row_max)){
        starter *= 2;
    }
    // add curr_val in output list
    add_output_to_list(curr_val, 0, 0, starter);

    // erase currently found quadrent from the input list

    
}

int main() {
    // you can write to stdout for debugging purposes, e.g.
    std::cout << "This is a debug message" << std::endl;

    return 0;
}


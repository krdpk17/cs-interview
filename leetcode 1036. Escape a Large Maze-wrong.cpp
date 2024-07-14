class Solution {
public:
    void pushNeighbourNodes(vector<int>& node, list<vector<int>>& bfs_list, vector<int>& target, list<vector<int>>& traversed){
        if(node[0] > target[0]){//left node
            vector<int> leftNode;
            leftNode.push_back(node[0]-1);
            leftNode.push_back(node[1]);
            if(std::find(traversed.begin(), traversed.end(), leftNode) == traversed.end()){
                bfs_list.push_back(leftNode);
            }else{
                node = leftNode;
                cout<<" "<<node[0]<<" "<<node[1]<<endl;
            }
            
        }
        
        if(node[0] < target[0]){//right node
            vector<int> rightNode;
            rightNode.push_back(node[0]+1);
            rightNode.push_back(node[1]);
            if(std::find(traversed.begin(), traversed.end(), rightNode) == traversed.end()){
                bfs_list.push_back(rightNode);
            }else{
                node = rightNode;
                cout<<" "<<node[0]<<" "<<node[1]<<endl;
            }
        }

        if(node[1] < target[1]){//up node
            vector<int> upNode;
            upNode.push_back(node[0]);
            upNode.push_back(node[1] + 1);
            if(std::find(traversed.begin(), traversed.end(), upNode) == traversed.end()){
                bfs_list.push_back(upNode);
            }else{
                node = upNode;
                cout<<" "<<node[0]<<" "<<node[1]<<endl;
            }
        }

        if(node[1] > target[1]){//Down node
            vector<int> downNode;
            downNode.push_back(node[0]);
            downNode.push_back(node[1] - 1);
            if(std::find(traversed.begin(), traversed.end(), downNode) == traversed.end()){
                bfs_list.push_back(downNode);
            }else{
                node = downNode;
                cout<<" "<<node[0]<<" "<<node[1]<<endl;
            }
        }
        return;

    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()){// if no grid blocked, then always possible to get path
            return true;
        }

        list<vector<int>> bfs_list;
        list<vector<int>> traversed;
        bfs_list.push_back(source);
        while(!bfs_list.empty()){
            vector<int> node = bfs_list.front();
            //cout<<" "<<node[0]<<" "<<node[1]<<endl;
            bfs_list.pop_front();
            traversed.push_back(node);
            cout<<traversed.size()<<endl;
            if(node == target){//found the path
                return true;
            }
            if(std::find(blocked.begin(), blocked.end(), node) != blocked.end()){//node in blocked list
                continue;
            }
            pushNeighbourNodes(node, bfs_list, target, traversed);

        }
        return false;

    }
};
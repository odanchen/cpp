    struct Node
    {
        vector<Node*> neigbors;
        int num;
    };
    void bfs(Node *cur, set<Node*> &visited)
    {
        visited.insert(cur);

        for (Node* neighbor : cur->neigbors)
        {
            if (visited.find(neighbor) == visited.end()) bfs(neighbor, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<Node*> roomNodes(rooms.size());
        set<Node*> visited;
        for (int i = 0; i < roomNodes.size(); i++) 
        {
            roomNodes[i] = new Node;
            roomNodes[i]->num = i;
        }
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int room : rooms[i])
            {
                roomNodes[i]->neigbors.push_back(roomNodes[room]);
            }
        }
        bfs(roomNodes[0], visited);
        return visited.size() == rooms.size();
    }

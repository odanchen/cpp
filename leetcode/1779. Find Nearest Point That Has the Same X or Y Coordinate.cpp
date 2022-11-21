    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int manhattanDist = -1;
        int curAns = -1;

        for (int i = 0; i < points.size(); i++)
        {
            if(x == points[i][0] || y == points[i][1])
            {
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dist == 0) return i;
                if (dist < manhattanDist || manhattanDist == -1)
                {
                    manhattanDist = dist;
                    curAns = i;
                }
                else if(curAns == -1) curAns = i;
            }

        }
        return curAns;
    }

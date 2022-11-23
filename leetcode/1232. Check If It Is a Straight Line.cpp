    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates[0][0] == coordinates[1][0])
        {
            int staticX = coordinates[0][0];
            for(auto pair : coordinates) if (pair[0] != staticX) return false;
            return true;
        }

        double k = (coordinates[0][1] - coordinates[1][1]) / (double)(coordinates[0][0] - coordinates[1][0]);
        int b = coordinates[0][1] - coordinates[0][0] * k;

        for (auto pair : coordinates)
        {
            if (pair[1] != k * pair[0] + b) return false;
        }
        return true;
    }

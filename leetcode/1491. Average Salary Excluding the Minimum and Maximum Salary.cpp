    double average(vector<int>& salary) {
        int minSal = salary[0], maxSal = salary[0], sum = 0;
        for(int curSal : salary)
        {
            if (curSal > maxSal) maxSal = curSal;
            if (curSal < minSal) minSal = curSal;
            sum += curSal;
        }
        return (sum - minSal - maxSal) / (double) (salary.size() - 2);
    }

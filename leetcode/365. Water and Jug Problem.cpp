    typedef pair<int, int> permutation;
    bool isAns(permutation cur, int target)
    {
        return (cur.first == target || cur.second == target || (cur.first + cur.second == target));
    }
    bool addPermutation(permutation toAdd, set<permutation> &visited, queue<permutation> &toProcess, int target)
    {
        if (visited.find(toAdd) == visited.end())
        {
            if (isAns(toAdd, target)) return true;
            visited.insert(toAdd);
            toProcess.push(toAdd);
        }
        return false;
    }
    bool addPermutations(permutation cur,set<permutation>&visited,int cap1,int cap2,queue<permutation>&toProcess,int target)
    {
        if (addPermutation(permutation(cur.first, 0), visited, toProcess, target)) return true;
        if (addPermutation(permutation(0, cur.second), visited, toProcess, target)) return true;
        if (addPermutation(permutation(cur.first, cap2), visited, toProcess, target)) return true;
        if (addPermutation(permutation(cap1, cur.second), visited, toProcess, target)) return true;

        int sum = cur.first + cur.second;
        permutation curPerm = (sum >= cap1) ? permutation(cap1, sum - cap1) : permutation(sum, 0);
        if (addPermutation(curPerm, visited, toProcess, target)) return true;
        curPerm = (sum >= cap2) ? permutation(sum - cap2, cap2) : permutation(0, sum);
        if (addPermutation(curPerm, visited, toProcess, target)) return true;
        return false;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        set<permutation> visited;
        queue<permutation> toProcess;
        if (addPermutations(permutation(0, 0), visited, jug1Capacity, jug2Capacity, toProcess, targetCapacity)) return true;

        while(not(toProcess.empty()))
        {
            permutation cur = toProcess.front();
            toProcess.pop();
            if(addPermutations(cur, visited, jug1Capacity, jug2Capacity, toProcess, targetCapacity)) return true;
        }
        return false;
    }

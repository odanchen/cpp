class Solution {
public:
    struct course
    {
        bool completion = false;
        int courseNum;
        vector<course*> requirements;
        course(int num) : courseNum(num) {}
    };
    bool isReachable(course *cur)
    {
        if (cur->requirements.empty()) return true;

        for (course* prerequisite : cur->requirements)
        {
            if (prerequisite->completion == false) return false;
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<course*> courses(numCourses);
        vector<course*> incompleteCourses(numCourses);
        vector<int> ans;
        for (int i = 0; i < courses.size(); i++) courses[i] = new course(i);
        for (int i = 0; i < courses.size(); i++) incompleteCourses[i] = courses[i];
        for (vector<int> pair : prerequisites)
        {
            courses[pair[0]]->requirements.push_back(courses[pair[1]]);
        }

        bool isMoving = true;
        while(not(incompleteCourses.empty()) && isMoving)
        {
            isMoving = false;
            for (int i = 0; i < incompleteCourses.size(); i++)
            {
                if (isReachable(incompleteCourses[i]))
                {
                    isMoving = true;
                    incompleteCourses[i]->completion = true;
                    ans.push_back(incompleteCourses[i]->courseNum);
                    incompleteCourses.erase(incompleteCourses.begin() + i);
                    i--;
                }
            }
        }

        if (incompleteCourses.empty()) return ans;
        return vector<int>({});   
    }
};

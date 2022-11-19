        Point pn = points.back();        
        if (orientation(p0, points[1], pn) != 0) {
            int idx = n-1;
            while (orientation(p0, points[idx], pn) == 0) {
                idx--;
            }
            reverse(points.begin() + idx + 1, points.end());
        }
 
        // Create an empty stack and push first three points to it.
        vector<Point> vertices;
        vertices.push_back(points[0]);
        vertices.push_back(points[1]);
        vertices.push_back(points[2]);
        // Process remaining n-3 points
        for (int i = 3; i < n; i++) {
            // Keep removing top while the angle formed by
            // points next-to-top, top, and points[i] makes a right (in clockwise) turn
            while (orientation(vertices[vertices.size() - 2], vertices.back(), points[i]) == 1) {
                vertices.pop_back();
            }
            vertices.push_back(points[i]);
        }
        return vertices;
    }
};
/*
//https://leetcode.com/problems/erect-the-fence/discuss/2828910/PythonC%2B%2BRust-upper-and-lower-convex-hulls-%2B-BONUS-scipynumpy-(explained)
// 210 ms
class Solution 
{
public:
    
    using tree = vector<int>;
    
    vector<tree> outerTrees(vector<tree>& trees) 
    {
        auto cross = [](tree& B, tree& A, tree& T) -> int
        {
            return (T[1]-B[1])*(B[0]-A[0]) - (B[1]-A[1])*(T[0]-B[0]);
        };
        
        sort(trees.begin(), trees.end());
        
        deque<tree> F;
        
        for (tree T : trees)
        {
            while (F.size() >= 2 and cross(F[F.size()-1],F[F.size()-2],T) < 0)
                F.pop_back();
            F.push_back(T);
​
            while (F.size() >= 2 and cross(F[0],F[1],T) > 0)
                F.pop_front();
            F.push_front(T);
        }
        
        set<tree> unique(F.begin(), F.end());
        return vector<tree>(unique.begin(), unique.end());
    }
};
*/

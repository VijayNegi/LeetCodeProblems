//https://leetcode.com/problems/erect-the-fence/discuss/103307/c%2B%2B-Graham-ScanMonotone-Chain-dealing-with-collinear-cases
// 83 ms
class Solution {
public:
    using Point = vector<int>;
    static int distSq(const Point& p1, const Point& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
 
    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are colinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    static int orientation(const Point& p, const Point& q, const Point& r) {
        int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) {
            return 0;  // colinear
        }
        return (val > 0) ? 1 : 2; // clock or counterclock wise
    }
    
    // Prints convex hull of a set of n points.
    vector<Point> outerTrees(vector<Point> points) {
        int n = points.size();
        if (n <= 3) {
            return points;
        }
        // Find the bottommost point
        int ymin = points[0][1], min = 0;
        for (int i = 1; i < n; i++) {
            int y = points[i][1];
            // Pick the bottom-most or chose the left most point in case of tie
            if ((y < ymin) || (ymin == y && points[i][0] < points[min][0])) {
                ymin = points[i][1], min = i;
            }
        }
 
        // Place the bottom-most point at first position
        swap(points[0],points[min]);
        // Point temp = points[0];
        // points[0] = points[min];
        // points[min] = temp;
        
        // Sort n-1 points with respect to the first point.
        // A point p1 comes before p2 in sorted ouput 
        // if p2 has larger polar angle (in counterclockwise direction) than p1
        // In the tied case, the one has smaller distance from p0 comes first
        Point p0 = points[0];
        sort(points.begin(), points.end(), [&](const Point& p1, const Point& p2) {
 
            // Find orientation
            int o = orientation(p0, p1, p2);
            if (o == 0) {
                return distSq(p0, p2) >= distSq(p0, p1);
            }
            return o == 2;
        });
        //As we need to output all the vertices instead of extreme points
        //We need to sort the points with the same largest polar angle w.r.p. p0 in another way to break tie
        //Closer one comes last
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

            while (F.size() >= 2 and cross(F[0],F[1],T) > 0)
                F.pop_front();
            F.push_front(T);
        }
        
        set<tree> unique(F.begin(), F.end());
        return vector<tree>(unique.begin(), unique.end());
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool cmp(const Point &a, const Point &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int visiblePoints(vector<Point> &points, int angle, Point location) {
    int same = 0;
    vector<double> polarDegrees;

    for (Point point : points) {
        if (point.x == location.x && point.y == location.y) {
            same++;
            continue;
        }

        double dx = point.x - location.x;
        double dy = point.y - location.y;
        double polarDegree = atan2(dy, dx) * 180 / M_PI;

        if (polarDegree < 0) {
            polarDegree += 360;
        }

        polarDegrees.push_back(polarDegree);
    }

    sort(polarDegrees.begin(), polarDegrees.end());

    int maxVisible = same;
    int left = 0;
    int right = 0;

    while (right < polarDegrees.size()) {
        while (right < polarDegrees.size() && polarDegrees[right] - polarDegrees[left] <= angle) {
            right++;
        }

        maxVisible = max(maxVisible, right - left + same);
        left++;
    }

    return maxVisible;
}

int main() {
    vector<Point> points = {{60, 61}, {58, 47}, {17, 26}, {87, 97}, {63, 63}, {26, 50}, {70, 21}, {3, 89}, {51, 24}, {55, 14}, {6, 51}, {64, 21}, {66, 33}, {54, 35}, {87, 38}, {30, 0}, {37, 92}, {92, 12}, {60, 73}, {75, 98}, {1, 11}, {88, 24}, {82, 92}};
    int angle = 44;
    Point location = {15, 50};

    cout << visiblePoints(points, angle, location) << endl;

    return 0;
}

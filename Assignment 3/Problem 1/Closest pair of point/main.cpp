#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Point{
public:
    int x, y;
};

int compareX(const void* a, const void* b){
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b){
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

/// compute line length by coordinates
float distance(Point p1, Point p2){
    return sqrt( pow( (p1.x - p2.x) , 2) + pow( (p1.y - p2.y) , 2) );
}
/// Compute by normal method when the size of the array is small
float normalCompute(Point P[], int n){
    float minimum = 1000000;
    for (int i = 0; i < n-1 ; ++i)
        for (int j = i+1; j < n; ++j)
            if (distance(P[i], P[j]) < minimum)
                minimum = distance(P[i], P[j]);
    return minimum;
}

float colsestVerticalPoints(Point cvPoints[], int n, float d){
    float minimum = d;

    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n && (cvPoints[j].y - cvPoints[i].y) < minimum ; ++j)
            if (distance(cvPoints[i] , cvPoints[j]) < minimum)
            {
                minimum = distance(cvPoints[i], cvPoints[j]);
            }

    return minimum;
}

float divide(Point P[], int n){
    if (n <= 3) return normalCompute(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    float dl = divide(P, mid);
    float dr = divide(P + mid, n-mid);

    float d = min(dl, dr);

    return d;
}

float closest(Point P[], int n){
    /// Sort by X coordinates
    qsort(P, n, sizeof(Point), compareX);
    /// Get the smallest value in the two side
    float d = divide(P , n);

    /// Get the nearest points to the vertical line
    Point cvPoints[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x - P[n/2].x) < d)
        {
            cvPoints[index] = P[i];
            index++;
        }
    }
    for (int i = 0; i < index ; i++) cout << cvPoints[i].x << " , " << cvPoints[i].y << " "<< endl;

    /// Sort the closest vertical points by Y
    qsort(cvPoints, index, sizeof(Point), compareY);
    /// Check if there is any line between the last array smaller than the minimum distance
    float minimumDistance = colsestVerticalPoints(cvPoints, index, d);

    return minimumDistance;
}

int main()
{
    Point P[] = {{0, 2}, {6, 67}, {43, 71}, {39, 107}, {189, 140}};

    int n = sizeof(P) / sizeof(P[0]);

    cout << closest(P, n);

    return 0;
}

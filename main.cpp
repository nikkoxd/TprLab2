#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define E 0.001

int main()
{
    int i = 1;
    double point[2] = {1, 1};
    double gradient[2] = {200, 600};
    double grModule = sqrt(200 * 200 + 600 * 600);

    while (grModule > E)
    {
        double h2 = pow(gradient[0], 2) * 100 + pow(gradient[1], 2) * 300;
        double h = -(gradient[0] * point[0] * 2) * 100;
        h -= gradient[1] * point[1] * 300;
        double hval = (h2 * 2) / (-h);

        point[0] = point[0] - gradient[0] * hval;
        point[1] = point[1] - gradient[1] * hval;
        gradient[0] = 200 * point[0];
        gradient[1] = 600 * point[1];

        grModule = sqrt(pow(gradient[0], 2) + pow(gradient[1], 2));
        cout << i++ << " " << grModule << endl;
        // if (i > 10) break;
    }

    cout << "Minimum point: (" << point[0] << ", " << point[1] << ")\n";
    cout << "Minimum: " << 100 * pow(point[0], 2) + 300 * pow(point[1], 2) + 5;
}
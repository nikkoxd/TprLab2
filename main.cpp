#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define E 0.001

int main()
{
// 100x_1^2 + 300x_2^2 + 5
  int i = 1;
  double point[2] = {1, 1};
  double gradient[2] = {200 * point[0], 600 * point[1]};
  double grModule = sqrt(pow(gradient[0], 2) + pow(gradient[1], 2));

  while (grModule > E)
  {
    double h = point[0] * gradient[0] + 3 * point[1] * gradient[1];
    h /= pow(gradient[0], 2) + 3 * pow(gradient[1], 2);

    point[0] = point[0] - gradient[0] * h;
    point[1] = point[1] - gradient[1] * h;

    gradient[0] = 200 * point[0];
    gradient[1] = 600 * point[1];

    grModule = sqrt(pow(gradient[0], 2) + pow(gradient[1], 2));

    cout << i++ << " " << grModule << endl;
    // if (i > 10) break;
  }

  cout << "Minimum point: (" << point[0] << ", " << point[1] << ")\n";
  cout << "Minimum: " << 100 * pow(point[0], 2) + 300 * pow(point[1], 2) + 5;
}
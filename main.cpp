// http://bigor.bmstu.ru/?cnt/?prn=y/?doc=MO/ch0605.mod

#include <cmath>
#include <iostream>
#include <vector>

#define n 2
#define precision 0.001
#define k1 100
#define k2 300
#define b 5

int main() 
{
  double x1, x2;
  double bruh1 = 0, bruh2 = 0;
  std::cin >> x1 >> x2;

  double l = 1;
  while (l >= precision) 
  {
    double r1 = l * (std::sqrt(n+1) + n - 1) / (n * std::sqrt(2));
    double r2 = l * (std::sqrt(n+1) - 1) / (n * std::sqrt(2));

    std::vector<std::vector<double>> R = {
      {x1, x1 + r1, x1 + r2},
      {x2, x2 + r2, x2 + r1}
    };

    double max = 0;
    double min = k1 * R[0][0] + k2 * R[0][1] + b;
    std::vector<double> minX = {0, 0};
    std::vector<double> xrk = {0, 0};
    for (int i = 0; i < n; i++)
    {
      double f = k1 * R[i][0] + k2 * R[i][1] + b;
      if (f > max) 
      {
        max = f;
        xrk = R[i];
      }
      if (f < min)
      {
        min = f;
        minX[0] = R[i][0];
        minX[1] = R[i][1];
      }
    }

    std::vector<double> Xrc = {0, 0};
    for (int i = 0; i < n; i++)
    {
      Xrc[0] += R[i][0];
      Xrc[1] += R[i][1];
    }
    Xrc[0] /= n;
    Xrc[1] /= n;

    std::vector<double> Xr1k = {0, 0};
    Xr1k[0] += 2 * Xrc[0] * xrk[0];
    Xr1k[1] += 2 * Xrc[1] * xrk[1];

    double fXr1k = k1 * Xr1k[0] + k2 * Xr1k[1] + b;

    max = 0;
    for (int i = 0; i < n; i++)
    {
      double f = k1 * R[i][0] + k2 * R[i][1] + b;
      double aboba = f - fXr1k;
      if (aboba > max) 
      {
        max = aboba;
        bruh1 = R[i][0];
        bruh2 = R[i][1];
      }
    }

    std::cout << minX[0] << " " << minX[1] << std::endl;        
    if (max <= precision) 
    {
      break;
    }

    // 😭
  }
}

// http://bigor.bmstu.ru/?cnt/?prn=y/?doc=MO/ch0605.mod 🤢

#include <cmath>
#include <iostream>
#include <vector>

#define n 2
#define precision 0.001
#define k1 100
#define k2 300
#define b 5
/* #define m 4 */

int main() 
{
  int m = std::ceil(1.65 * n + 0.05 * n * n);

  double x1, x2;
  double bruh1 = 0, bruh2 = 0;
  int index = 0;
  double l = 1;
  std::cin >> x1 >> x2;

  double r1 = l * (std::sqrt(n+1) + n - 1) / (n * std::sqrt(2));
  double r2 = l * (std::sqrt(n+1) - 1) / (n * std::sqrt(2));

  std::vector<std::vector<double>> R = {
    {x1, x1 + r1, x1 + r2},
    {x2, x2 + r2, x2 + r1}
  };

  while (l >= precision) 
  {
    double max = 0;
    double min = k1 * R[0][0] + k2 * R[1][0] + b;
    std::vector<double> minX = {0, 0};
    std::vector<double> xrk = {0, 0};
    for (int i = 0; i <= n; i++)
    {
      double f = k1 * R[0][i] + k2 * R[1][i] + b;
      if (f > max) 
      {
        max = f;
        xrk = {R[0][i], R[1][i]};
        index = i;
      }
    }

    std::vector<double> Xrc = {0, 0};
    for (int i = 0; i < n; i++)
    {
      Xrc[0] += R[0][i];
      Xrc[1] += R[1][i];
    }
    Xrc[0] /= n;
    Xrc[1] /= n;

    std::vector<double> Xr1k = {0, 0};
    Xr1k[0] += 2 * Xrc[0] - xrk[0];
    Xr1k[1] += 2 * Xrc[1] - xrk[1];

    R[0][index] = Xr1k[0];
    R[1][index] = Xr1k[1];

    double fXr1k = k1 * Xr1k[0] + k2 * Xr1k[1] + b;

    max = 0;
    min = fXr1k;
    for (int i = 0; i <= n; i++)
    {
      if (i != index)
      {
        double f = k1 * R[0][i] + k2 * R[1][i] + b;
        double aboba = std::abs(f - fXr1k);
        max = std::max(max, aboba);
        min = std::min(min, f);
      }
    }

    if (max <= precision) 
    {
      std::cout << "Точка минимума: " << min; 
      break;
    }

    // здесь ты проверяешь каждую вершину, повторилась она m раз или нет
    // 
  }
}

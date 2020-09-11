#include "tri.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool comparaison(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.first < b.first;
}

int main(void) {
  const auto increment = 25000;
  const auto limit = 1000000;

  auto x = increment;

  std::ofstream fichier;
  fichier.open ("ift3001-tp2-q2.csv");
  fichier << "taille, triParDenombrement, stable_sort\n";

  while(x <= limit) {
      std::vector<std::pair<int, int>> valeurs_triParDenombrement(x);
      std::vector<std::pair<int, int>> valeurs_stable_sort(x);

      auto i = 0;
      int a, b;
      std::ifstream infile("couples.txt");

      while (infile >> a >> b && i < x)
      {
        valeurs_triParDenombrement[i] = std::pair<int, int>(a, b);
        valeurs_stable_sort[i] = std::pair<int, int>(a, b);
        i++;
      }

      high_resolution_clock::time_point t_begin_triParDenombrement = high_resolution_clock::now();
      triParDenombrement(valeurs_triParDenombrement);
      high_resolution_clock::time_point t_end_triParDenombrement = high_resolution_clock::now();

      auto temps_triParDenombrement = duration_cast<milliseconds>(t_end_triParDenombrement - t_begin_triParDenombrement).count();

      high_resolution_clock::time_point t_begin_stable_sort = high_resolution_clock::now();
      std::stable_sort(valeurs_stable_sort.begin(), valeurs_stable_sort.end(), comparaison);
      high_resolution_clock::time_point t_end_stable_sort = high_resolution_clock::now();

      auto temps_stable_sort = duration_cast<milliseconds>(t_end_stable_sort - t_begin_stable_sort).count();

      fichier << x << ", " << temps_triParDenombrement << ", " << temps_stable_sort << "\n";

      x += increment;
  }

  fichier.close();

  return 0;
}
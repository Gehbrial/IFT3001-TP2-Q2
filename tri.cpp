#include <algorithm>
#include <cassert>
#include <vector>
#include <list>

#include "tri.hpp"

void triParDenombrement(std::vector<std::pair<int, int>> & liste) {
  assert(!liste.empty());

  auto n = liste.size();
  auto l = -1;
  auto u = 0;

  std::vector<std::pair<int, int>> S(n);

  for (int i = 0; i < n; i++) {
    std::pair<int, int> paire = liste[i];

    if (paire.first > u ) {
      u = paire.first;
    }

    if (l == -1 || paire.first < l) {
      l = paire.first;
    }

    S[i] = paire;
  }

  std::vector<int> D ((unsigned long)(u - l + 1), 0);

  for (int i = 0; i < n; i++) {
    D[liste[i].first - l]++;
  }

  for (int i = 1; i <= u-l; i++) {
    D[i] += D[i-1];
  }

  for (int i = (int)n-1; i >= 0; i--) {
    int j = liste[i].first - l;
    D[j]--;
    S[D[j]] = liste[i];
  }

  liste = S;
}

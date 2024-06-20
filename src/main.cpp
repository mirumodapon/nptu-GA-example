#include "genes.h"
#include "utils.h"


#include <vector>
#include <iostream>
#include <ctime>

int main() {
  srand(time(NULL));

  short int iterate = 50;
  size_t nGroup = 100;

  // Generate groups
  std::vector<Genes*> groups;
  for (size_t i = 0; i < nGroup; ++i) {
    Genes* g = new Genes();
    groups.push_back(g);

  }


  // iterate
  while (iterate--) {
    size_t length = groups.size();
    double probability[length];
    double sum = 0;

    std::vector<Genes*> selections;


    for (size_t i = 0; i < length; ++i) {
      double value = groups[i]->objective();

      sum += value;
      probability[i] = sum;
    }

    for (size_t i = 0; i < length; ++i) {
      probability[i] /= sum;
    }


    for (size_t i = 0; i < length; ++i) {
      double threshold = _rand();

      size_t n = 0;
			while (threshold > probability[n]) ++n;

      selections.push_back(groups[n]);
    }


    // Crossover
    for (size_t i = 0; i < selections.size(); ++i) {
      double threshold;
      threshold = _rand();

      if (threshold > 0.8) continue;

      size_t index = std::floor(selections.size() * _rand());


      Genes* g = *selections[i] * *selections[index];
      groups.push_back(g);
    }

    // Mutation
    for (size_t i = 0; i < selections.size(); ++i) {
      Genes* g = selections[i]->mutation();

      if (g == nullptr) continue;

      groups.push_back(g);
    }


    // Sort
    sortGenes(groups);

    // Kill some genes
    while (groups.size() > nGroup * 0.5) {
      Genes* g = groups[0];

      groups.erase(groups.begin());
      delete g;
    }

    // Generate genes
    while (groups.size() < nGroup) {
      Genes* g = new Genes();
      groups.push_back(g);
    }


  }


  sortGenes(groups);

  Genes* best = *groups.end();
  std::cout << "Genes: " << *best << std::endl;
  std::cout << "Value: " << best->objective() << std::endl;



  return 0;
}

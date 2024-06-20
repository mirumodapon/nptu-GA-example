#include "utils.h"

double _rand() {
  return (double) rand() / RAND_MAX;
}

void sortGenes(std::vector<Genes*>& genes) {

  double objective[genes.size()];
  for (size_t i = 0; i < genes.size(); ++i)
    objective[i] = genes[i]->objective();

  for (size_t i = 0; i < genes.size(); ++i) {
    for (size_t j = i; j < genes.size(); ++j) {
      if (objective[i] < objective[j]) continue;

      Genes* tmp = genes[i];
      genes[i] = genes[j];
      genes[j] = tmp;

      double tmpp = objective[i];
      objective[i] = objective[j];
      objective[j] = tmpp;
    }
  }

}

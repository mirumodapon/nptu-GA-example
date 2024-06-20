#include "genes.h"
#include "constant.h"
#include "utils.h"

#include <cmath>

Genes::Genes(): BinaryGenes(33) {
  for (size_t i = 0; i < 33; ++i) {
    set(i, _rand() < 0.5 ? 1 : 0);
  }
}

Genes::Genes(const Genes& g): BinaryGenes(g) {
}

Genes* Genes::clone() const {
  Genes* g = new Genes(*this);
  return g;
}

double Genes::getX1() const {
  int dec = 0;
  for (size_t i = 0; i < 18; ++i) {
    dec <<= 1;
    dec += (*this)[i];
  }

  return (double) dec / 10000 - 3;
}

double Genes::getX2() const {
  short dec = 0;
  for (size_t i = 18; i < 33; ++i) {
    dec <<= 1;
    dec += (*this)[i];
  }

  return (double) dec / 10000 + 4.1;
}

double Genes::objective() const {
  double x1 = getX1();
  double x2 = getX2();

  return 21.5
    + x1 * sin(4 * PI * x1)
    + x2 * sin(20 * PI * x2); 
}

Genes* operator* (const Genes& g1, const Genes& g2) {
  Genes* g = new Genes();

  for (size_t i = 0; i < 33; ++i) {
    if (_rand() > 0.5) g->set(i, g1[i]);
    else g->set(i, g2[i]);
  }

  return g;
}


Genes* Genes::mutation() const {
  Genes* g = this->clone();
  bool isMutation = false;

  for (size_t i = 0; i < 33; ++i) {
    if (_rand() > 0.05) continue;

    isMutation = true;
    g->set(i, !g->at(i));
  }


  if (!isMutation) {
    delete g;
    return nullptr;
  }

  return g;
}




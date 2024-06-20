#ifndef _GENES_
#define _GENES_

#include "binaryGenes.h"


class Genes: public BinaryGenes {
public:
  Genes();
  Genes(const Genes& g);

  Genes* clone() const;


  double getX1() const;
  double getX2() const;
  double objective() const;

  Genes* mutation() const;
  friend Genes* operator* (const Genes& g1, const Genes& g2);

private:


};

#endif

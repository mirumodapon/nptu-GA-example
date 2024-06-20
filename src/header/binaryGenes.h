#ifndef _BINARY_GENES_
#define _BINARY_GENES_

#include <cstddef>
#include <ostream>
#include "type.h"

class BinaryGenes {
public:
  BinaryGenes(size_t size);
  BinaryGenes(const BinaryGenes& g);
  ~BinaryGenes();
  size_t length() const;

  bool at(size_t index) const;
  void set(size_t index, bool value);
  
  bool operator[] (size_t index) const;
  friend std::ostream& operator<< (std::ostream& ost, BinaryGenes& g);

  BinaryGenes* clone() const;
private:
  size_t size;
  byte* genes;
};


#endif

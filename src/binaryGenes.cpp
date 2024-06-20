#include "binaryGenes.h"

#include <cmath>
#include <algorithm>

BinaryGenes::BinaryGenes(size_t size) {
  this->size = size;

  size_t b = std::ceil((float)size / 8);
  genes = new byte[b];
  std::fill(genes, genes + b, 0);
}

BinaryGenes::BinaryGenes(const BinaryGenes& g) {
  this->size = g.size;

  size_t b = std::ceil((float)size / 8);
  genes = new byte[b];

  for (size_t i = 0; i < b; ++i) {
    genes[i] = g.genes[i];
  }
}

BinaryGenes::~BinaryGenes() {
  delete[] this->genes;
}

size_t BinaryGenes::length() const {
  return this->size;
}

bool BinaryGenes::at(size_t index) const {
  if (index >= this->size) throw "Index out of range.";


  size_t b = index / 8;
  byte mask = 0x80 >> (index % 8);

  return this->genes[b] & mask;
}

void BinaryGenes::set(size_t index, bool value) {
  size_t b = index / 8;
  byte mask;

  if (value) {
    mask = 0x80 >> (index % 8);
    this->genes[b] = this->genes[b] | mask;
  } else {
    mask = 0x80 >> (index % 8);
    mask = ~mask;
    this->genes[b] = this->genes[b] & mask;
  }
}

bool BinaryGenes::operator[] (size_t index) const {
  return this->at(index);
}

std::ostream& operator<< (std::ostream& ost, BinaryGenes& g) {
  size_t b = g.size / 8;

  for (size_t i = 0; i < b; ++i) {
    byte gene = g.genes[i];

    for (size_t k = 0; k < 8; ++k) {
      ost << (gene & 0x80 ? '1' : '0');
      gene <<= 1;
    }

    ost << ' ';
  }

  byte gene = g.genes[b];
  for (size_t k = 0; k < g.size % 8; ++k) {
    ost << (gene & 0x80 ? '1' : '0');
    gene <<= 1;
  }

  return ost;
}

BinaryGenes* BinaryGenes::clone() const {
  BinaryGenes* g = new BinaryGenes(*this);
  return g;
}

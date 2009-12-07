#ifndef _CSPLIT_H_
#define _CSPLIT_H_

#include "translator.h"
#include "lattice.h"

// this "translator" takes single words (with NO SPACES) and segments
// them using the approach described in:
//
// C. Dyer. (2009) Using a maximum entropy model to build segmentation
//                 lattices for MT. In Proceedings of NAACL HLT 2009.
// note, an extra word space marker # is inserted at the left edge of
// the forest!
struct CompoundSplitImpl;
struct CompoundSplit : public Translator {
  CompoundSplit(const boost::program_options::variables_map& conf);
  bool Translate(const std::string& input,
                 SentenceMetadata* smeta,
                 const std::vector<double>& weights,
                 Hypergraph* forest);
 private:
  boost::shared_ptr<CompoundSplitImpl> pimpl_;
};

#endif

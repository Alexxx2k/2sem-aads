#include "functions.hpp"

int main()
{
  using namespace nikiforov;

  using list_l = List< std::pair< std::string, List< unsigned long long > > >;
  using list_ull = List< unsigned long long >;

  list_l seqsPair;
  list_ull listSumm;
  size_t maxSize = 0;
  try
  {
    input_(std::cin, seqsPair);
    List< unsigned long long >::ConstIterator iterList;
    for (list_l::ConstIterator iterSeqsPair = seqsPair.cbegin(); iterSeqsPair != seqsPair.cend(); ++iterSeqsPair)
    {
      outputName_(iterSeqsPair, seqsPair, maxSize);
    }

    
    outputSeqs_(seqsPair, listSumm, maxSize);
    outputSumm_(listSumm, maxSize);
  }
  catch (const std::overflow_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 0;
  }
  return 0;
}

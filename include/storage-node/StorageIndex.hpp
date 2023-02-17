#ifndef INDEX_HPP_
#define INDEX_HPP_

#include <string>
#include <queue>

#include "InvertedLists.hpp"
#include "L2Space.hpp"

namespace ann_dkvs
{
  class VectorDistanceIdMaxHeapCompare
  {
  public:
    bool operator()(QueryResult parent, QueryResult child)
    {
      bool swapParentWithChild = (parent.distance < child.distance ||
                                  (parent.distance == child.distance && parent.vector_id < child.vector_id));
      return swapParentWithChild;
    }
  };
  typedef std::priority_queue<QueryResult, std::vector<QueryResult>, VectorDistanceIdMaxHeapCompare> heap_t;

  class StorageIndex
  {
  private:
    InvertedLists *lists;
    distance_func_t distance_func;
    QueryResults extract_results(heap_t *candidates);
    void search_preassigned_list(
        Query* query,
        list_id_t list_id,
        heap_t *candidates);

  public:
    StorageIndex(InvertedLists *lists);
    QueryResults search_preassigned(Query* query);
  };
}
#endif // INDEX_HPP_
#ifndef INDEX_IVF_FLAT_H_
#define INDEX_IVF_FLAT_H_

#include <string>
#include <queue>

#include "InvertedLists.h"
using namespace std;

namespace ann_dkvs
{
  typedef float distance_t;
  typedef pair<distance_t, vector_id_t> result_t;
  typedef priority_queue<result_t> heap_t;

  class IndexIVFFlat
  {
  private:
    size_t vector_dims;
    InvertedLists lists;
    vector<result_t> extract_results(heap_t candidates);
    void search_list(
        list_id_t list_id,
        vector_el_t *query,
        size_t k,
        heap_t candidates);

  public:
    IndexIVFFlat(size_t vector_dims, string base_path);
    vector<result_t> search(
        list_id_t *list_ids,
        size_t nlist,
        vector_el_t *query,
        size_t k);
  };
}
#endif // INDEX_IVF_FLAT_H_
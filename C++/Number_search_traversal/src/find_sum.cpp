// Copyright 2022 CSCE 240
//

#include <hw3/inc/find_sum.h>

// collection of helper functions

// each function accepts same params as FindSum EXCEPT for sums_found, instead
//   I used four ints:
// (1) index of starting row
// (2) index of starting column
// (3) address of index of ending row
// (4) address of index of ending col
//
// Return true if found

// search row
// search column
// search diag dsc
// search diag asc

bool RowSum(int sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices) {
  for(size_t column = sum_indices[kMatrix_size_cols_idx]; column < matrix_size[kMatrix_size_cols_idx]; ++column) {
    sum -= matrix[sum_indices[kMatrix_size_rows_idx]][column];
    if(sum == 0) {
      sum_indices[kIndices_end_row_idx] = sum_indices[kMatrix_size_rows_idx];
      sum_indices[kIndices_end_col_idx] = column;
      return true;
    }
  }
  return false;
}

bool ColSum(int sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices) {
  for(size_t row = sum_indices[kMatrix_size_rows_idx]; row < matrix_size[kMatrix_size_rows_idx]; ++row) {
    sum -= matrix[row][sum_indices[kMatrix_size_cols_idx]];
    if(sum == 0) {
      sum_indices[kIndices_end_col_idx] = sum_indices[kMatrix_size_cols_idx];
      sum_indices[kIndices_end_row_idx] = row;
      return true;
    }
  }
  return false;
}

bool AscSum(int sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
  for( size_t row = sum_indices[kMatrix_size_rows_idx], column = sum_indices[kMatrix_size_cols_idx];
      row < matrix_size[kMatrix_size_rows_idx] && column < matrix_size[kMatrix_size_cols_idx]; ++row, ++column) {
        sum -= matrix[row][column];
        if(sum == 0) {
          sum_indices[kIndices_end_col_idx] = column;
          sum_indices[kIndices_end_row_idx] = row;
          return true;
        }
      }
  return false;
}

bool DecSum(int sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
  for( size_t row = sum_indices[kMatrix_size_rows_idx], column = sum_indices[kMatrix_size_cols_idx];
      row < matrix_size[kMatrix_size_rows_idx] && column < matrix_size[kMatrix_size_cols_idx]; --row, ++column) {
        sum -= matrix[row][column];
        if(sum == 0) {
          sum_indices[kIndices_end_col_idx] = column;
          sum_indices[kIndices_end_row_idx] = row;
          return true;
        }
      }

  return false;
}


size_t ** ExtendArray(size_t** array, size_t* size) {
  const size_t kStartSize = 2;
  size_t new_size = *size == 0 ? kStartSize : *size << 1;
  size_t **tmp = new size_t *[new_size];
  for (size_t i = 0; i < *size; ++i)   // copy all existing
    tmp[i] = array[i];
  delete [] array;  // clean up old
  *size = new_size;  // update size
  return tmp;  // update name
}

size_t * AllocIndices(size_t row, size_t col) {
  size_t *indices = new size_t[kIndices_size]; // kIndices_size = 4
  indices[kIndices_start_row_idx] = row;
  indices[kIndices_start_col_idx] = col;
  return indices;
}

typedef bool (*SumFuncType) (int, const int**, const size_t*, size_t*);


const size_t** FindSum(const int** matrix,
                       const size_t* matrix_size,
                       int search_sum,
                       size_t* sums_found)
/*
Preconditions:
 - matrix dimensions are correctly represented by matrix_size
 - sums_found output parameter exists (but may contain garbage values)

Postconditions:
 - sums_found stores number of summations found
 - sums_found holds zero if no summations found

Returns:
 - Returns a two-dimensional unsigned int of size
     sums_found x kIndices_size
   where n is the value in sums_found.
 - Return type is of the form {
     {
       start row : size_t,
       start col : size_t,
       end row : size_t,
       end col : size_t
     }
   }
 - Returns the nullptr if no summations were found and sets sums_found to 0
 */

{   
  
  // *sums_found = 0;  // init sums found to 0

  // size_t summations_size = 2;  // start assuming no more than 2 summations
  // // build structure to hold all found summations
  // size_t** summations = new size_t*[summations_size];

  // summations[*sums_found] = new size_t[kIndices_size];   // only done when
  //                                                       //   summation is found

  *sums_found = 0;  // initialize output variable
  size_t **summations = nullptr; // stores any summation indices

  size_t summations_size = 0;  // obviously
  size_t *indices = nullptr;  // stores individual pair of indices found

  SumFuncType sum_funcs[] = {
    AscSum, DecSum, RowSum, ColSum
  };

  size_t n_rows = matrix_size[kMatrix_size_rows_idx];
  size_t n_cols = matrix_size[kMatrix_size_cols_idx];

  for (size_t row = 0; row < n_rows; ++row) {
    for (size_t col = 0; col < n_cols; ++col) {
      if (search_sum == matrix[row][col]) {
        if (!indices)
          indices = AllocIndices(row, col);
        indices[kIndices_end_row_idx] = row;
        indices[kIndices_end_col_idx] = col;

        if (*sums_found == summations_size)
            summations = ExtendArray(summations, &summations_size);

          summations[*sums_found] = indices;  // add new index pairs
          ++(*sums_found);  // update count
          indices = nullptr;  // reset pointer
        break;  
      }
      for(SumFuncType sum_func : sum_funcs) {
        if(!indices)
          indices = AllocIndices(row, col);
        if((*sum_func)(search_sum, matrix, matrix_size, indices)) {
          if(*sums_found == summations_size)
            summations = ExtendArray(summations, &summations_size);
          
          summations[*sums_found] = indices;
          ++(*sums_found);
        }
        else {
          delete [] indices;
        }

        indices = nullptr;
      }
    }
  }


  return const_cast<const size_t**>(summations);
}


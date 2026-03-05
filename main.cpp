#include <iostream>

template< class T>
T* mergeN(const T* const* a, size_t sa, const size_t* sai, T* c)
{
  size_t * indices = new size_t[sa]{0};
  size_t size = 0;
  for (size_t i = 0; i < sa; ++i)
  {
    size += sai[i];
  }
  size_t index_c = 0;
  try
  {
    for (size_t k = 0; k < size; ++k)
    {
      T min;
      bool isFirstElem = true;
      size_t index_temp = 0;
      for (size_t i = 0; i < sa; ++i)
      {
        if (indices[i] < sai[i])
        {
          if (isFirstElem || a[i][indices[i]] < min)
          {
            min = a[i][indices[i]];
            index_temp = i;
            isFirstElem = false;
          }
        }
      }
      c[index_c] = min;
      index_c++;
      indices[index_temp]++;
    }
  }
  catch (...)
  {
    delete[] indices;
    throw;
  }
  delete[] indices;
  return c + index_c;
}

int main()
{}

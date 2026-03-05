/*
Неявный интерфейс:
1. Конструктор по умолчанию
2. Перегруженный оператор меньше
3. Перегруженный оператор копирующего присваивания
4. Деструктор

Недостатки явного интерфейса:
1. Память выделяется вне функции. Если пользователь выделил недостаточно памяти, то функция небезопасна.
2. Если в процессе заполнения массива генерируется исключение, то пользователь не может узнать,
   сколько элементов успело скопироваться в c (базовая гарантия)
3. По сигнатуре сложно понять, что нужно передать в функцию и какой ожидается результат
*/

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
      T min; // T::T()
      bool isFirstElem = true;
      size_t index_temp = 0;
      for (size_t i = 0; i < sa; ++i)
      {
        if (indices[i] < sai[i])
        {
          if (isFirstElem || a[i][indices[i]] < min) // T::operator<(const T &)
          {
            min = a[i][indices[i]]; //T::operator=(const T &)
            index_temp = i;
            isFirstElem = false;
          }
        }
      }
      c[index_c] = min; //T::operator=(const T &)
      index_c++;
      indices[index_temp]++;
    } // T::~T() для min
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

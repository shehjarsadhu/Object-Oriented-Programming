#include<iostream>
#include "swap.h"
#include "sort.h"
int main()
{
DNA D1 = DNA(">aget","GATTA");
DNA D2 = DNA(">aget","GAATA");
DNA D3 = DNA(">aget","GTTTA");
std::vector<DNA> a = {D1,D2,D3};
std::vector<DNA> b = sort(a, &headerLessThan);
std::vector<DNA> c = sort(a, &seqLenLessThan);

for(unsigned int i = 0 ; i<b.size()-1; i++)
  {
    std::cout<<b[i].getHeader() <<std::endl ;
  }
  for(unsigned int i = 0 ; i<c.size()-1; i++)
    {
      std::cout<<c[i].getSequence() <<std::endl ;
    }
}

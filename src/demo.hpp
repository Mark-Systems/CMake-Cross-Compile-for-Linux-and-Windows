#include <stdint.h>

class Demo{
   public:
   Demo(){};
   virtual ~Demo(){};
   int add (int a , int b){
      return a+b;
   };
};
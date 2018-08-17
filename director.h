#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "builder.h"
namespace DTLib
{
    class Director
    {
    public:
        static void Create(IBuild *builder) {
                builder->BuildCpu();
                builder->BuildMainboard();
                builder->BuildRam();
                builder->BuildVideoCard();
            }
    };
}
#endif // DIRECTOR_H

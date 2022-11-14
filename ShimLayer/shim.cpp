#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <unistd.h>
#include <dlfcn.h>
extern "C"
{
    int rand(); // this is needed for C++ shared library because C++ complier mangles function name
    int rand_default();
}

int rand_default()
{
    return 111;
}

int rand()
{
    typedef int (*func)(void);
    func f;
    // f = (func)dlsym(RTLD_NEXT, "rand");
    f = (func)dlsym(RTLD_DEFAULT, "rand_default");
    return f() % 1000;
}

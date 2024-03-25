#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "rubygc.h"

int
main(int argc, char **argv)
{
    char *gc_lib = getenv("RUBY_GC_LIB");
    if (gc_lib) {
      void *handle = dlopen(gc_lib, RTLD_LAZY);
      if (!handle) {
        fprintf(stderr, "Failed to load %s: %s\n", gc_lib, dlerror());
        return 1;
      }
      void (*GC_Init)(void) = dlsym(handle, "GC_Init");
      if (GC_Init) {
        GC_Init();
      } else {
        fprintf(stderr, "Failed to find GC_Init in %s: %s\n", gc_lib, dlerror());
      }
    } else {
        GC_Init_default();
    }
}

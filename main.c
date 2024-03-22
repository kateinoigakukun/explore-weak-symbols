#include <stdio.h>
#include "rubygc.h"

int
main(int argc, char **argv)
{
    if (GC_Init) {
        GC_Init();
    } else {
        GC_Init_default();
    }
}

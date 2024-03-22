#ifndef RUBYGC_H
#define RUBYGC_H

void GC_Init(void) __attribute__((weak));
void GC_Init_default(void);

#endif

#ifndef _SVMCALL_H
#define _SVMCALL_H

#ifdef __cplusplus
extern "C" {
#endif

int mainpredict(int argc, char **argv);
int maintrain(int argc, char **argv);
int mainscale(int argc,char **argv);

#ifdef __cplusplus
}
#endif

#endif /* _SVMCALL_H */
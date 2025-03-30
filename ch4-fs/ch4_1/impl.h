#include <stdio.h>
#include <stdlib.h>

#define SET_XATTR 438
#define READ_KV_SYSCALL 439
#define REMOVE_XATTR 440


int set_xattr(const char *path, const char *name, const char *value){
    return syscall(SET_XATTR, path, name, value);
};

// Function to get an extended attribute
// If name does not exist, return -1
// If name exists, return 1 and copy value to dst
int get_xattr(const char *path, const char *name, char *dst){
    return syscall(READ_KV_SYSCALL, path, name, dst);
};

// Function to remove an extended attribute
int remove_xattr(const char *path, const char *name){
    return syscall(REMOVE_XATTR, path, name);
};

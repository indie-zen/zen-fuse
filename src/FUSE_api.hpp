#ifndef ZEN_FUSE_API_HPP_INCLUDED
#define ZEN_FUSE_API_HPP_INCLUDED

#include <fuse_lowlevel.h>

extern "C" {
    void zenfuse_init(void *userdata, struct fuse_conn_info *conn);
    void zenfuse_destroy(void *userdata);
};

#endif // !ZEN_FUSE_API_HPP_INCLUDED

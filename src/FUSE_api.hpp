#pragma once

#include <fuse_lowlevel.h>

extern "C" {
    void zenfuse_init(void *userdata, struct fuse_conn_info *conn);
    void zenfuse_destroy(void *userdata);

    void zenfuse_readdir(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
			 struct fuse_file_info *fi);

    void zenfuse_lookup(fuse_req_t req, fuse_ino_t parent, const char *name);
    void zenfuse_getattr(fuse_req_t req, fuse_ino_t ino,
			 struct fuse_file_info *fi);
    void zenfuse_open(fuse_req_t req, fuse_ino_t ino,
		      struct fuse_file_info *fi);
    void zenfuse_read(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
		      struct fuse_file_info *fi);
};

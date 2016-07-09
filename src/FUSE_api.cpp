
#include "FUSE_api.hpp"
#include "ZenFuse.hpp"

#include <iostream>

static ZenFuse* pZenFuse = nullptr;

void zenfuse_init(void* userdata, struct fuse_conn_info* conn)
{
    std::cout << "zenfuse_init" << std::endl << std::flush;
    pZenFuse = ZenFuse::instance();
    pZenFuse->init(userdata, conn);
}

void zenfuse_destroy(void* userdata)
{
    pZenFuse->destroy(userdata);
    pZenFuse = nullptr;
}

void zenfuse_readdir(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
         struct fuse_file_info *fi)
{
    std::cout << "zenfuse_readdir" << std::endl << std::flush;
    pZenFuse->readDir(req, ino, size, off, fi);
}

void zenfuse_lookup(fuse_req_t req, fuse_ino_t parent, const char *name)
{
    std::cout << "zenfuse_lookup" << std::endl << std::flush;

    pZenFuse->lookup(req, parent, name);
}

void zenfuse_getattr(fuse_req_t req, fuse_ino_t ino,
		 struct fuse_file_info *fi)
{
    std::cout << "zenfuse_getattr" << std::endl << std::flush;
    pZenFuse->getattr(req, ino, fi);
}

void zenfuse_open(fuse_req_t req, fuse_ino_t ino,
	      struct fuse_file_info *fi)
{
    std::cout << "zenfuse_open" << std::endl << std::flush;

    pZenFuse->open(req, ino, fi);
}

void zenfuse_read(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
	      struct fuse_file_info *fi)
{
    std::cout << "zenfuse_read" << std::endl << std::flush;

    pZenFuse->read(req, ino, size, off, fi);
}

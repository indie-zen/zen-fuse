#define FUSE_USE_VERSION 30

//#include <config.h>
#include <fuse_lowlevel.h>

#include "FUSE_api.hpp"

#include "ZenFuse.hpp"

static struct fuse_lowlevel_ops zenfuse_ll_oper = {
    .init = zenfuse_init,
    .destroy = zenfuse_destroy,
};


int main(int argc, char* argv[])
{
    // Create a ZenFuse object to prevent a race condition
    ZenFuse* pZenFuse = ZenFuse::instance();

    return 0;
}

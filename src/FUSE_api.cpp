
#include "FUSE_api.hpp"
#include "ZenFuse.hpp"

static ZenFuse* pZenFuse = nullptr;

void zenfuse_init(void* userdata, struct fuse_conn_info* conn)
{
    pZenFuse = ZenFuse::instance();
    pZenFuse->init(userdata, conn);
}

void zenfuse_destroy(void* userdata)
{
    pZenFuse->destroy(userdata);
    pZenFuse = nullptr;
}

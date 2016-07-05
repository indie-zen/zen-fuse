#include "ZenFuse.hpp"

#include <fuse_lowlevel.h>

static ZenFuse* pZenFuse = nullptr;

ZenFuse*
ZenFuse::instance()
{
    if(pZenFuse == nullptr)
    {
        pZenFuse = new ZenFuse();
    }
    return pZenFuse;
}

ZenFuse::ZenFuse()
{

}

ZenFuse::~ZenFuse()
{

}

void
ZenFuse::init(void* _pUserData, struct fuse_conn_info* _pConn)
{
    m_pUserData = _pUserData;
}

void
ZenFuse::destroy(void* _pUserData)
{

}

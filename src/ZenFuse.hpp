#ifndef ZEN_FUSE_HPP_INCLUDED
#define ZEN_FUSE_HPP_INCLUDED

#include <fuse_lowlevel.h>

class ZenFuse
{
public:
    static ZenFuse* instance();

    void init(void* _pUserData, struct fuse_conn_info* _pConn);
    void destroy(void* _pUserData);

private:
    ZenFuse();
    ~ZenFuse();

private:
    void*                   m_pUserData;
    struct fuse_session*    m_pSession;
};

#endif // !ZEN_FUSE_HPP_INCLUDED

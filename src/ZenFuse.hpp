#ifndef ZEN_FUSE_HPP_INCLUDED
#define ZEN_FUSE_HPP_INCLUDED

#include <fuse_lowlevel.h>

class ZenFuse
{
public:
    static ZenFuse* instance();

    void init(void* _pUserData, struct fuse_conn_info* _pConn);
    void destroy(void* _pUserData);

    void readDir(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
            struct fuse_file_info *fi);

    void lookup(fuse_req_t req, fuse_ino_t parent, const char *name);
    void getattr(fuse_req_t req, fuse_ino_t ino,
		    struct fuse_file_info *fi);
    void open(fuse_req_t req, fuse_ino_t ino,
	        struct fuse_file_info *fi);
    void read(fuse_req_t req, fuse_ino_t ino, size_t size, off_t off,
    	    struct fuse_file_info *fi);

private:
    ZenFuse();
    ~ZenFuse();

private:
    void*                   m_pUserData;
    struct fuse_session*    m_pSession;
    struct fuse_args        m_args;
    struct fuse_chan*       m_pChan;
};

#endif // !ZEN_FUSE_HPP_INCLUDED

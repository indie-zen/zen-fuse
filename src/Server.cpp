#define FUSE_USE_VERSION 30

#include <iostream>
#include <cstddef>

//#include <config.h>
#include <fuse_lowlevel.h>

#include "FUSE_api.hpp"

#include "ZenFuse.hpp"

static struct fuse_lowlevel_ops zenfuse_ll_oper = {
    .init = zenfuse_init,
    .destroy = zenfuse_destroy,
    .readdir = zenfuse_readdir,

    .lookup		= zenfuse_lookup,
	.getattr	= zenfuse_getattr,
	.open		= zenfuse_open,
	.read		= zenfuse_read,
};

struct zen_fuse_data {
    int debug;
    std::string profile;
};

/*
 * @return -1 on error, 0 if arg is to be discarded, 1 if arg should be kept
 */
int processUserOptions(void *data, const char *arg, int key,
			       struct fuse_args *outargs)
{
    zen_fuse_data* pData = (zen_fuse_data*)data;
    switch(key)
    {
    case 1: // debug
        std::cout << "Debug: " << arg << std::endl;
        break;
    case 2:
        pData->profile = &arg[9];
        std::cout << "Profile: " << pData->profile << std::endl;
        break;
    default:
        std::cout << "Default (" << key << "): " << arg << std::endl;
        return 1;
    }
    return 0;
}

#define LO_OPT(t, p, v) { t, offsetof(struct zen_fuse_data, p), v }

static const struct fuse_opt zen_fuse_opts[] = {
    FUSE_OPT_KEY("--profile %s", 2),
	FUSE_OPT_END
};

int main(int argc, char* argv[])
{
    // Create a ZenFuse object to prevent a race condition
    ZenFuse* pZenFuse = ZenFuse::instance();

    struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
	struct fuse_chan *ch;
	char *mountpoint;
	int err = -1;

    struct zen_fuse_data userdata = { .debug = 0 };

	if (fuse_opt_parse(&args, &userdata, zen_fuse_opts, processUserOptions) == -1)
    {
        std::cerr << "Error processing fuse_opt_parse" << std::endl;
        return err;
    }

    // TODO Determine the address of Zen Spaces daemon


    std::cout << "Parsing command line" << std::endl;
	if (fuse_parse_cmdline(&args, &mountpoint, nullptr, nullptr) != -1 &&
	    (ch = fuse_mount(mountpoint, &args)) != nullptr) {
		struct fuse_session *se;

		se = fuse_lowlevel_new(&args, &zenfuse_ll_oper,
				       sizeof(zenfuse_ll_oper), nullptr);
		if (se != nullptr) {
			if (fuse_set_signal_handlers(se) != -1) {
				fuse_session_add_chan(se, ch);

				/* Block until ctrl+c or fusermount -u */
				err = fuse_session_loop(se);

				fuse_remove_signal_handlers(se);
				fuse_session_remove_chan(ch);
			}
			fuse_session_destroy(se);
		}
		fuse_unmount(mountpoint, ch);
	}
	fuse_opt_free_args(&args);

	return err ? 1 : 0;
}

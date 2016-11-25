
find_library(ZEN_ENTERPRISE_LIBRARY
    NAMES
        libzen-enterprise.a
    HINTS
        /usr/local
    PATH_SUFFIXES
        lib
        bin
)

find_library(ZEN_FABRIC_LIBRARY
    NAMES
        libzen-fabric.a
    HINTS
        /usr/local
    PATH_SUFFIXES
        lib
        bin
)

mark_as_advanced(ZEN_ENTERPRISE_LIBRARY)
mark_as_advanced(ZEN_FABRIC_LIBRARY)

//
// Created by RedNicStone on 16/08/23.
//

#ifndef OSMIO_LOADER_VERSION_H
#define OSMIO_LOADER_VERSION_H

#include <cstdint>


typedef uint32_t OsVersion;

//todo: This may cause problems on little endian systems
#define OS_MAKE_API_VERSION(variant, major, minor, patch) \
    ((((OsVersion)(variant)) << 29U) | (((OsVersion)(major)) << 22U) | \
     (((OsVersion)(minor))   << 12U) |  ((OsVersion)(patch)))

#define OS_API_VERSION_VARIANT(version) ((OsVersion)(version) >> 29U)
#define OS_API_VERSION_MAJOR(version) (((OsVersion)(version) >> 22U) & 0x7FU)
#define OS_API_VERSION_MINOR(version) (((OsVersion)(version) >> 12U) & 0x3FFU)
#define OS_API_VERSION_PATCH(version) ((OsVersion)(version) & 0xFFFU)

#define OS_API_VERSION_1_0_0 OS_MAKE_API_VERSION(0, 1, 0, 0)

#define OS_API_HEADER_VERSION OS_API_VERSION_1_0_0

#endif //OSMIO_LOADER_VERSION_H

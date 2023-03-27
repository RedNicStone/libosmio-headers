# libosmio-headers - **O**ptimized **S**tatic **M**ulti **I**/**O** library headers
**Headers for libosmio loaders and installable client drivers**

This repository contains all public include headers for libosmio. \
These headers can be used when building custom loaders and ICD's for libosmio.
They are also used to generate documentation files.

## Who is this repository for?
This repo, `libosmio-headers`, is provided as an easy way to create custom loaders and ICD's for the osmio ecosystem. \
The target audience is developers wanting to extend or implement osmio functionality.
If you are looking to use osmio as a library in your own project, take a look at the [meta repo](https://github.com/RedNicStone/libosmio). \
\
What this repo is used for:
- As header for osmio loaders, see section [For a custom loader implementation](#for-a-custom-loader-implementation)
- As header for osmio ICD's, see section [For a custom ICD](#for-a-custom-icd)
- Generating the libosmio documentation
- Linking against libosmio dynamically, which is strongly advised against [^1]

## Using this repository to provide public headers
This repository uses CMake, so including it in you project as public headers is almost as easy as adding a CMake project. \
To include osmio headers as public header files to your project, see these examples:

### For a custom loader implementation
```cmake
Todo: Add loader include example
```

### For a custom ICD
```cmake
Todo: Add ICD include example
```

## Finding documentation on this repository
All documentation on osmio functions as well as how to build your custom loader and ICD can be found in the [documentation repo](https://github.com/RedNicStone/libosmio-docs).

## Contributing to this repository
Unfortunately contributions to this repository will be accepted only under rare circumstances. \
Since this repo holds the API footprint of libosmio, any change is likely to impact or even break existing loaders and ICDs. \
The readme and CMake files are unlikely to have any impact though, so feel free to open contributions to these.

## Opening issues on this repository
Issues regarding the header files provided by this repository are likely to force an API change, so they fall under the same restrictions as [contributing](#contributing-to-this-repository).

[^1]: Linking against osmio this way is not recommended. 
If you want to link libosmio dynamically, install a loader on your system and link against those headers.

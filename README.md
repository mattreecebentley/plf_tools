# plf_tools
Toolsets shared across plf:: libraries, including compiler feature-detection, functions/objects for using C++14/17/20 features in earlier compilers, and others.

The first toolset, compiler defines, are assessments of availability of C++ features for most compilers (but mainly GCC/Clang/MSVC), resulting in defined macros for those features which are available. These are always instantiated, since they are used in the other 3 toolsets. An additional header, plf_tools_undef.h, undefines these macros - this can be used as needed at the end of a given project, however you should guard this with a per-file macro within your code if you're likely to have a class containing another class which also uses the tools eg. plf::list<plf::colony<int>>.

The other three toolsets are only instantiated if their matching macro is defined. These are:

    plf_tools - various tools. Instantiated if the macro PLF_INCLUDE_TOOLS is defined prior to including the .h.

    plf_bit_tools - bit-manipulation tools. Instantiated if the macro PLF_INCLUDE_BIT_TOOLS is defined prior to including the .h.

    plf_uninitialized_tools - allocator-aware versions of std::uninitialized_copy, std::uninitialized_move and std::uninitialized_fill_n. Instantiated if the macro PLF_INCLUDE_UNINITIALIZED_TOOLS is defined prior to including the .h.

The _INCLUDE macros are automatically undefined at the end of the .h, you do not need to undefine them manually.

See the main documentation page (https://plflib.org/tools.htm) for more details.

// Copyright (c) 2026, Matthew Bentley (mattreecebentley@gmail.com) www.plflib.org

// zLib license (https://www.zlib.net/zlib_license.html):
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
// 	claim that you wrote the original software. If you use this software
// 	in a product, an acknowledgement in the product documentation would be
// 	appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
// 	misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#undef PLF_CONSTRUCT_ELEMENT
#undef PLF_DEFAULT_SUPPORT
#undef PLF_ALIGNMENT_SUPPORT
#undef PLF_INITIALIZER_LIST_SUPPORT
#undef PLF_TYPE_TRAITS_SUPPORT
#undef PLF_IS_ALWAYS_EQUAL_SUPPORT
#undef PLF_ALLOCATOR_TRAITS_SUPPORT
#undef PLF_VARIADICS_SUPPORT
#undef PLF_MOVE_SEMANTICS_SUPPORT
#undef PLF_NOEXCEPT
#undef PLF_NOEXCEPT_ALLOCATOR
#undef PLF_NOEXCEPT_SWAP
#undef PLF_NOEXCEPT_MOVE_ASSIGN
#undef PLF_CONSTEXPR
#undef PLF_CONSTFUNC
#undef PLF_CPP20_SUPPORT
#undef PLF_EXCEPTIONS_SUPPORT
#undef PLF_CPP11_SUPPORT
#undef PLF_CONSTEVAL_SUPPORT
#undef PLF_VOIDT_SUPPORT


#undef PLF_CONSTRUCT
#undef PLF_DESTROY
#undef PLF_ALLOCATE
#undef PLF_DEALLOCATE

#if defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L) && _MSC_VER < 1951
	#pragma warning ( pop )
#endif

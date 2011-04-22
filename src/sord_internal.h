/*
  Copyright 2011 David Robillard <http://drobilla.net>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THIS SOFTWARE IS PROVIDED  AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef SORD_SORD_INTERNAL_H_
#define SORD_SORD_INTERNAL_H_

#include <stddef.h>
#include <stdint.h>

#include "sord/sord.h"

typedef intptr_t SordCount;  ///< Count of nodes or triples

/** Node */
struct _SordNode {
	SordNodeType type;      ///< SordNodeType
	size_t       n_bytes;   ///< Length of data in bytes (including terminator)
	SordCount    refs;      ///< Reference count (i.e. number of containing quads)
	SordNode     datatype;  ///< Literal data type (ID of a URI node, or 0)
	const char*  lang;      ///< Literal language (interned string)
	uint8_t*     buf;       ///< Value (string)
};

#endif /* SORD_SORD_INTERNAL_H_ */

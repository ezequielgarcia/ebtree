/*
 * Elastic Binary Trees - exported functions for String data nodes.
 *
 * Copyright (C) 2000-2015 Willy Tarreau - w@1wt.eu
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/* Consult ebsttree.h for more details about those functions */

#include "ebsttree.h"

/* Find the first occurence of a zero-terminated string <x> in the tree <root>.
 * It's the caller's reponsibility to use this function only on trees which
 * only contain zero-terminated strings. If none can be found, return NULL.
 */
REGPRM2 struct ebmb_node *ebst_lookup(struct eb_root *root, const char *x)
{
	return __ebst_lookup(root, x);
}

/* Find the first occurence of a length <len> string <x> in the tree <root>.
 * It's the caller's reponsibility to use this function only on trees which
 * only contain zero-terminated strings, and that no null character is present
 * in string <x> in the first <len> chars. If none can be found, return NULL.
 */
REGPRM3 struct ebmb_node *ebst_lookup_len(struct eb_root *root, const char *x, unsigned int len)
{
	struct ebmb_node *node;

	node = ebmb_lookup(root, x, len);
	if (!node || node->key[len] != 0)
		return NULL;
	return node;
}

/* Insert ebmb_node <new> into subtree starting at node root <root>. Only
 * new->key needs be set with the zero-terminated string key. The ebmb_node is
 * returned. If root->b[EB_RGHT]==1, the tree may only contain unique keys. The
 * caller is responsible for properly terminating the key with a zero.
 */
REGPRM2 struct ebmb_node *ebst_insert(struct eb_root *root, struct ebmb_node *new)
{
	return __ebst_insert(root, new);
}

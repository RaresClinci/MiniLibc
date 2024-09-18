// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	// verificam daca lista a fost initializata
	if (mem_list_head.next == NULL) {
		mem_list_init();
	}

	// alocam memorie de marimea ceruta
	void* data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	// verificam alocarea
	if ((long)data == -1) {
		return NULL;
	}

	// adaugam la lista
	if (mem_list_add(data, size) == -1) {
		return NULL;
	}

	return data;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	// alocam memoria
	void* data = malloc(nmemb * size);

	// verifcam daca s-a realizat alocarea corect
	if (data == NULL) {
		return NULL;
	}

	// introudcem 0 in memorie
	memset(data, 0, nmemb * size);

	return data;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	// extragem marimea lui ptr din lista
	struct mem_list *to_delete = mem_list_find(ptr);
	size_t size = to_delete->len;

	// scoatem din lista zona care depoziteaza ptr
	mem_list_del(ptr);

	// eliberam memoria
	munmap(ptr, size);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	// extragem lungime veche a ptr
	struct mem_list *to_realloc = mem_list_find(ptr);
	size_t size_old = to_realloc->len;

	// stergem valoarea veche ptr din lista
	mem_list_del(ptr);

	// realocam memoria
	void *data = mremap(ptr, size_old, size, MREMAP_MAYMOVE);

	// verifcam daca s-a realizat realocarea
	if ((long)data == -1) {
		return NULL;
	}

	// readaugam la lista
	if (mem_list_add(data, size) == 0) {
		return data;
	} else {
		return NULL;
	}
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	// implementare descrisa in GNU libc manual
	return realloc(ptr, nmemb * size);
}

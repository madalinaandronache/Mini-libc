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
    // Source: https://stackoverflow.com/questions/8475609/implementing-your-own-malloc-free-with-mmap-and-munmap

    size_t total_size = size + sizeof(struct mem_list);
    void* ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr != MAP_FAILED) {
        struct mem_list* block = (struct mem_list*)ptr;
        block->start = ptr + sizeof(struct mem_list);
        block->len = size;
        block->prev = NULL;
        block->next = NULL;

        return block->start;
    }

	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;

    if (total_size != 0) {
        void *memory = malloc(total_size);

        if (memory != NULL) {
            memset(memory, 0, total_size);
        }

        return memory;
    }

	return NULL;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
        return;
    }
    struct mem_list* block = (struct mem_list*)(ptr - sizeof(struct mem_list));
    if (block != NULL) {
        if (block->prev != NULL) {
            block->prev->next = block->next;
        }

        if (block->next != NULL) {
            block->next->prev = block->prev;
        }

        munmap(block, block->len + sizeof(struct mem_list));
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(size);
    }

    struct mem_list *mem_region = mem_list_find(ptr);

    if (mem_region != NULL) {
        if (mem_region->len >= size) {
            return ptr;
        } else {
            void *new_ptr = malloc(size);

            if (new_ptr != NULL) {
                memcpy(new_ptr, ptr, mem_region->len);
                free(ptr);

                return new_ptr;
            } else {
                return NULL;
            }
        }
    } else {
        return malloc(size);
    }

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

    size_t total_size = nmemb * size;

    if (total_size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(total_size);
    }

    struct mem_list *mem_region = mem_list_find(ptr);

    if (mem_region != NULL) {
        if (mem_region->len >= size) {
            return ptr;
        } else {
            void *new_ptr = malloc(size);

            if (new_ptr != NULL) {
                size_t copy_size;
                if (mem_region->len < size) {
                    copy_size = mem_region->len;
                } else {
                    copy_size = size;
                }
                memcpy(new_ptr, ptr, copy_size);
                free(ptr);

                return new_ptr;
            } else {
                return NULL;
            }
        }
    } else {
        return malloc(size);
    }

	return NULL;
}

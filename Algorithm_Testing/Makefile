SOURCES=query_main.c queries.c unsorted_queries.c sorted_queries.c hash_queries.c heap_page.c record.c utilities.c hash.c
HEADERS=query_main.h queries.h unsorted_queries.h sorted_queries.h hash_queries.h heap_page.h record.h utilities.h hash.h
README=readme
MAKEFILE=Makefile


all: query_main.o queries.o heap_page.o record.o utilities.o unsorted_queries.o sorted_queries.o hash_queries.o hash.o
	gcc -std=c99 -Wall -pedantic -lm query_main.o queries.o heap_page.o record.o utilities.o unsorted_queries.o sorted_queries.o hash_queries.o hash.o -o run_queries

query_main.o: query_main.c query_main.h
	gcc -std=c99 -Wall -pedantic -c query_main.c

queries.o: queries.c queries.h
	gcc -std=c99 -Wall -pedantic -c queries.c

unsorted_queries.o: unsorted_queries.c unsorted_queries.h
	gcc -std=c99 -Wall -pedantic -c unsorted_queries.c

sorted_queries.o: sorted_queries.c sorted_queries.h
	gcc -std=c99 -Wall -pedantic -c sorted_queries.c

hash_queries.o: hash_queries.c hash_queries.h
	gcc -std=c99 -Wall -pedantic -c hash_queries.c

heap_page.o: heap_page.c heap_page.h
	gcc -std=c99 -Wall -pedantic -c heap_page.c

record.o: record.c record.h
	gcc -std=c99 -Wall -pedantic -c record.c

utilities.o: utilities.c utilities.h
	gcc -std=c99 -Wall -pedantic -c utilities.c

hash.o: hash.c hash.h
	gcc -std=c99 -Wall -pedantic -lm -c hash.c


clean:
	rm -rf *o query


########################################################################
# Move this target to the end of the Makefile to zip up your code
# when submitting. Do not submit your .dat files, or directories.
# We only want the files that are part of your implementation.
########################################################################
archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)

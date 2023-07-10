_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror $(_OPT) -I./include $(_DEBUG)

.PHONY: clean clean-img doc check-syntax compile-all launch-tests video

# rule to generate the doxygen documentation
doc:
	doxygen conf/doxygen.conf

# rule to remove all .o files and all executables
clean:
	- rm -f *.o
	- find . -executable -type f -delete

# rule to clean images and video
clean-img:
	- rm out/*.ppm video.mp4

# compile rules
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

# you should put all the .o files corresponding to your .c files as prerequisites of
# this rule (see examples)
# \ allows to go on the next line
check-syntax: example-main.o example-string.o read-file-formatted.o \
	      read-file-text.o write-fact.o test-dummy.o \
		  app-naive-loader.o app-naive-conway.o\
		  naive_universe.o naive_loader.o naive_conway.o naive_ppm_writer.o\
		  test-naive-universe.o test-naive-loader.o test-naive-conway.o test-naive-generate-image.o \
		  linked_list_cell.o list_universe.o list_loader.o list_conway.o list_ppm_writer.o\
		  test-linked-list.o test-list-universe-print.o test-list-universe.o test-list-loader.o test-list-conway.o test-list-generate-image.o\
		  app-list-loader.o app-list-conway.o

# put all the rules to build your applications and tests here (see examples)
example-main: example-main.o
	$(CC) $(CFLAGS) -o example-main example-main.o

example-string: example-string.o
	$(CC) $(CFLAGS) -o example-string example-string.o

read-file-formatted: read-file-formatted.o
	$(CC) $(CFLAGS) -o read-file-formatted read-file-formatted.o

read-file-text: read-file-text.o
	$(CC) $(CFLAGS) -o read-file-text read-file-text.o

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o write-fact write-fact.o

app-ex-loader: app-ex-loader.o
	$(CC) $(CFLAGS) -o app-ex-loader app-ex-loader.o

test-dummy: test-dummy.o
	$(CC) $(CFLAGS) -o test-dummy test-dummy.o

#naive implementation
app-naive-loader: app-naive-loader.o naive_universe.o naive_loader.o
	$(CC) $(CFLAGS) -o app-naive-loader app-naive-loader.o naive_universe.o naive_loader.o

app-naive-conway: app-naive-conway.o naive_universe.o naive_loader.o naive_conway.o naive_ppm_writer.o
	$(CC) $(CFLAGS) -o app-naive-conway app-naive-conway.o naive_universe.o naive_loader.o naive_conway.o naive_ppm_writer.o


test-naive-universe: test-naive-universe.o naive_universe.o
	$(CC) $(CFLAGS) -o test-naive-universe test-naive-universe.o naive_universe.o

test-naive-loader: test-naive-loader.o naive_loader.o naive_universe.o
	$(CC) $(CFLAGS) -o test-naive-loader test-naive-loader.o naive_loader.o naive_universe.o

test-naive-conway: test-naive-conway.o naive_loader.o naive_universe.o naive_conway.o 
	$(CC) $(CFLAGS) -o test-naive-conway test-naive-conway.o naive_loader.o naive_universe.o naive_conway.o 

test-naive-generate-image: test-naive-generate-image.o naive_loader.o naive_universe.o naive_ppm_writer.o
	$(CC) $(CFLAGS) -o test-naive-generate-image test-naive-generate-image.o naive_loader.o naive_universe.o naive_ppm_writer.o

#linked list implementation
app-list-loader: app-list-loader.o list_universe.o list_loader.o linked_list_cell.o
	$(CC) $(CFLAGS) -o app-list-loader app-list-loader.o list_universe.o list_loader.o linked_list_cell.o

app-list-conway: app-list-conway.o list_conway.o list_universe.o list_loader.o list_ppm_writer.o linked_list_cell.o
	$(CC) $(CFLAGS) -o app-list-conway app-list-conway.o list_conway.o list_universe.o list_loader.o list_ppm_writer.o linked_list_cell.o

test-linked-list: test-linked-list.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-linked-list test-linked-list.o linked_list_cell.o

test-list-universe-print: test-list-universe-print.o list_universe.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-list-universe-print test-list-universe-print.o list_universe.o linked_list_cell.o

test-list-universe: test-list-universe.o list_universe.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-list-universe test-list-universe.o list_universe.o linked_list_cell.o

test-list-loader: test-list-loader.o list_loader.o list_universe.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-list-loader test-list-loader.o list_loader.o list_universe.o linked_list_cell.o

test-list-conway:  test-list-conway.o list_loader.o list_universe.o list_conway.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-list-conway test-list-conway.o list_loader.o list_universe.o list_conway.o linked_list_cell.o

test-list-generate-image: test-list-generate-image.o list_loader.o list_universe.o list_conway.o list_ppm_writer.o linked_list_cell.o
	$(CC) $(CFLAGS) -o test-list-generate-image test-list-generate-image.o list_loader.o list_universe.o list_conway.o list_ppm_writer.o linked_list_cell.o
# put all your applications and tests executables as prerequisite of this rule
# \ allows to go to the next line
compile-all: example-main example-string read-file-formatted \
             read-file-text write-fact test-dummy \
	     app-ex-loader \
		 app-naive-loader app-naive-conway\
		 test-naive-universe test-naive-loader test-naive-conway test-naive-generate-image\
		 test-linked-list test-list-universe-print test-list-universe test-list-loader test-list-conway test-list-generate-image\
		 app-list-loader app-list-conway
		 

# add all your test executables in the following variable. You should respect
# the order given in the project text
ALL_TESTS = test-dummy test-naive-universe test-naive-loader test-naive-conway test-naive-generate-image test-linked-list\
			test-list-universe-print test-list-universe test-list-loader test-list-conway test-list-generate-image

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$$x --all; done

# misc
WIDTH=1024
HEIGHT=768

video: out
	mogrify -format png -resize $(WIDTH)X$(HEIGHT) -filter box -background black -extent $(WIDTH)X$(HEIGHT) -gravity center out/*.p*m
	ffmpeg -framerate 5 -i out/img-%03d.png -vcodec libx264 -vf format=yuv420p video.mp4
	rm -f out/*.png

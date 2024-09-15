test: test.c
	gcc $^ -o $@ -lstat -L ../libstat
	
run: test
	LD_LIBRARY_PATH=../libstat ./test
	
clean:
	rm -f test

.PHONY: run clean

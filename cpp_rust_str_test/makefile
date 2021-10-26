CC      = gcc

ifeq ($(shell uname),Darwin)
    LDFLAGS := -Wl,-dead_strip
else
    LDFLAGS := -Wl,--gc-sections -lpthread -ldl
endif

all: target/print_floats
	target/print_floats

target:
	mkdir -p $@

target/print_floats: target/hello.o target/debug/libprint_floats.a
	$(CC) -o $@ $^ $(LDFLAGS)

target/debug/libprint_floats.a: src/lib.rs Cargo.toml
	cargo build

target/hello.o: src/hello.c | target
	$(CC) -o $@ -c $<

clean:
	rm -rf target
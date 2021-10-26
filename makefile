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

target/print_floats: target/hello.o cpp_rust_str_test/target/debug/libprint_floats.a
	$(CC) -o $@ $^ $(LDFLAGS)

target/debug/libprint_floats.a: cpp_rust_str_test/src/lib.rs cpp_rust_str_test/Cargo.toml
	cargo build --manifest-path cpp_rust_str_test/Cargo.toml 

target/hello.o: cpp_rust_str_test/src/hello.c | target
	$(CC) -o $@ -c $<

clean:
	rm -rf target
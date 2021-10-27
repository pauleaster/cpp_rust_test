// Reference: https://github.com/alexcrichton/rust-ffi-examples


#![crate_type = "staticlib"]
use core::slice;
use std::str;

#[allow(clippy::not_unsafe_ptr_arg_deref)]

#[no_mangle]
pub extern fn print_floats(string_of_floats: * const u8, len: usize) -> i32 {

    println!("Starting rust function");
    println!("Reading C buffer");
    let buffer=unsafe{slice::from_raw_parts(string_of_floats, len)}; 
    println!("Decoding C buffer");
    match str::from_utf8(buffer) {
        Ok(s) => {
            for float_str in s.split_ascii_whitespace() {
                match float_str.parse::<f64>() {
                    Ok(number) => println!("{}",number),
                    Err(e) => println!("Invalid float => {:?}",e),
                };
            }
        },
        Err(e) => println!("Invalid string => {:?}",e),
    }
    println!("Completed rust function");
    0
}

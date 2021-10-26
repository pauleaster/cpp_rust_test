// Reference: https://github.com/alexcrichton/rust-ffi-examples

#![crate_type = "staticlib"]
use core::slice;
use std::str;

#[no_mangle]
pub extern fn print_floats(string_of_floats: * const u8, len: usize) -> i32 {

    unsafe{
        let buffer=slice::from_raw_parts(string_of_floats, len); 
        match str::from_utf8(buffer) {
            Ok(s) => {
                for float_str in s.split_ascii_whitespace() {
                    match float_str.parse::<f64>() {
                        Ok(number) => println!("{}",number),
                        Err(e) => println!("{:?}",e) ,
                    };
                }
            },
            Err(e) => println!("{:?}",e),
        }
    }
    1
}

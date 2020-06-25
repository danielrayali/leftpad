# leftpad

Just a simple program that will pad text on the left to align it on the right. That's it. Just in case anyone needs it for anything...

## Dependencies

- C++11 compiler
- Make

## Building

`$ make`

## Running

```bash
$ cat input.txt 
But I must explain to you how all 
        this mistaken idea of denouncing of a 
  pleasure and praising pain
$ ./leftpad 50 < input.txt 
                 But I must explain to you how all
             this mistaken idea of denouncing of a
                        pleasure and praising pain

```

## License

See LICENSE file.
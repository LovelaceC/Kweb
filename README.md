# Kweb

Kweb is a very simple library for creating websites in C.

## Really?

Yeahh, why not?

## Dependencies

- [Onion](https://github.com/davidmoreno/onion/)
- Nothing else lmao

## Running

Install onion (it's also available in some distros repos), and then do `make
run`, it will automatically compile and run kweb.

A simple demo will run, you can visit it going to localhost:8080

## TODO

I literally started working on this today (Jul 19 01:57:48 2021) and it barely
has stuff, I am really looking forward to make this grow and more usable.

- More elements. So far it only supports labels
- Child elements. So we can get outputs like:

  ```html
<div>
<p>A child</p>
<p>Another child</p>
</div>
  ```

- Documentation
- Abstractions for certain useful functionalities, such as filesystem
management, sockets, and that kind of stuff.
- Database support.
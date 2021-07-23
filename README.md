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
- Documentation
- Abstractions for certain useful functionalities, such as filesystem
management, sockets, and that kind of stuff.
- Database support.
- File format supports (images, videos, etcetera - as it runs its own server)
- Think about more ToDo's lmao
- Simple form creation and management:
  - For example: "form_create" "form_add_label" "form_add_input"
  "form_add_button" "form_add_radio", etcetera
- Simple GET/POST support

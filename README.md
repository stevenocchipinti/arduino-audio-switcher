Arduino Audio Switcher
======================

This codebase has two parts:

1. Web front-end
2. Arduino


Web front-end
-------------

```
yarn
yarn start
```


Arduino
-------

While you can use the Arduino IDE or similar, I'm attempting to use an alpha
build of the `arduino-cli` for this project.

- Download `arduino-cli` from here: https://github.com/arduino/arduino-cli
- Make `arduino-cli` available in the `$PATH`
- Use `yarn compile` and `yarn upload`

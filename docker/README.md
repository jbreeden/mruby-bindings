# Docker Image

## Install Docker

[Do it](https://www.docker.com/)

## Build the Docker Image

This should be done in this directory.

```
docker build --tag mruby-bindings .
```

## Run a Container

This can be done anywhere, as long as you've already built the image.

```
docker run --rm -it mruby-bindings
```

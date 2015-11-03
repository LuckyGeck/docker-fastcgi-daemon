# docker-fastcgi-daemon
Docker setup for nginx + fastcgi-daemon2

# Requirements
To use this docker setup via `make` you should have the following commands in your `$PATH`:
* `docker`
* `docker-compose`
* `make`

# Quick Start
## Start from scratch
Starts up `docker` via `docker-compose` with nginx + fastcgi-daemon2 and built version of your fastcgi project

* `make`

## Reload your `.so` in fastcgi-daemon
* `make restart`

## Build your fastcgi project
* `make build`
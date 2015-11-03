# docker-fastcgi-daemon
Docker setup for nginx + fastcgi-daemon2

# Setup endpoints
## Network endpoints
* `$DOCKER_MACHINE_IP:8000` - `nginx` started
* `$DOCKER_MACHINE_IP:8000/test` - your `fastcgi-daemon` will listen on this URL
* `$DOCKER_MACHINE_IP:8001` - [monitoring port](https://github.com/lmovsesjan/Fastcgi-Daemon/blob/master/doc/en/Setup.md#operability-test) for fastcgi-daemon

## File system endpoints
* `/tmp/fastcgi/fastcgi_daemon.sock` - `socket` for `nginx` <-> `fastcgi-daemon` interaction
* `fastcgi_data/`
    * `default_nginx_site.conf` - `nginx` default site configuration
    * `fastcgi.conf` - `fastcgi-daemon` configuration
* `src/` - folder with your project's sources (contains sample `Makefile` + `.cpp`)
* `logs/` - `nginx` logs

# Requirements
To use this docker setup via `make` you should have the following commands in your `$PATH`:
* `docker`
* `docker-compose`
* `make`

# Quick Start
## Start from scratch
Starts up `docker` via `docker-compose` with `nginx` + `fastcgi-daemon` and built version of your fastcgi project

* `make`

## Reload your `.so` in fastcgi-daemon
* `make restart`

## Build your fastcgi project
* `make build`

## Cleanup all setup
* `make clean`
FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
    autoconf-archive \
    automake1.9 \
    autotools-dev \
    build-essential \
    debhelper \
    git \
    libboost-dev \
    libboost-regex-dev \
    libboost-thread-dev \
    libfcgi-dev \
    libssl-dev \
    libtool \
    libxml2-dev \
    pkg-config

ENV FCGI_VERSION 2.10-26

RUN mkdir -p /tmp/build_fastcgi && cd /tmp/build_fastcgi && \
    git clone https://github.com/lmovsesjan/Fastcgi-Daemon.git && \
    cd Fastcgi-Daemon && \
    dpkg-buildpackage -rfakeroot && \
    cd .. && \
    sudo dpkg -i \
        ./fastcgi-daemon2-init_${FCGI_VERSION}_amd64.deb \
        ./fastcgi-daemon2_${FCGI_VERSION}_amd64.deb \
        ./libfastcgi-daemon2-dev_${FCGI_VERSION}_amd64.deb \
        ./libfastcgi-daemon2_${FCGI_VERSION}_amd64.deb \
        ./libfastcgi2-syslog_${FCGI_VERSION}_amd64.deb \
    && cd /tmp && rm -rf /tmp/build_fastcgi

VOLUME ["/data", "/tmp/fastcgi"]
WORKDIR "/data"
CMD ["fastcgi-daemon2", "--config=fastcgi.conf"]
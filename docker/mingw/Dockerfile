FROM ubuntu:latest

LABEL maintainer="Nauris Linde <nauris.linde@giraffe360.com>"
LABEL company="Giraffe360"
LABEL description="Windows development environment for Room Sketcher with Qt"
LABEL version="1.0"

ENV DEBIAN_FRONTEND=noninteractive \
    DEBCONF_NONINTERACTIVE_SEEN=true \
    QT_PATH=${QT_PATH} \
    WINEDEBUG=-all

RUN apt-get -yqq update && apt-get -yqq --no-install-suggests --no-install-recommends install \
    git \
    openssh-client \
    curl \
    ca-certificates \
    wine64 \
    locales

# Reconfigure locale
RUN locale-gen en_US.UTF-8 && dpkg-reconfigure locales

RUN ln -s /usr/bin/wine64-stable /usr/local/bin/wine

ARG AQT_VERSION=3.1.2
ARG AQT_URL="https://github.com/miurahr/aqtinstall/releases/download/v$AQT_VERSION/aqt.exe"
RUN curl -fLs $AQT_URL > /tmp/aqt.exe

ARG QT_VERSION=6.5.0
ARG QT_PATH=C:\\Qt
RUN wine /tmp/aqt.exe install-qt -O "$QT_PATH" windows desktop "$QT_VERSION" win64_mingw
RUN wine /tmp/aqt.exe install-tool -O "$QT_PATH" windows desktop tools_mingw90
RUN wine /tmp/aqt.exe install-tool -O "$QT_PATH" windows desktop tools_cmake
RUN wine /tmp/aqt.exe install-tool -O "$QT_PATH" windows desktop tools_ninja
RUN wine /tmp/aqt.exe install-tool -O "$QT_PATH" windows desktop tools_openssl_x64
RUN wine /tmp/aqt.exe install-tool -O "$QT_PATH" windows desktop tools_ifw

COPY wine.sh /tmp/
RUN /tmp/wine.sh

RUN apt -qq clean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
    rm /var/log/lastlog /var/log/faillog

WORKDIR /usr/src/app
FROM ubuntu:latest

LABEL maintainer="Nauris Linde <nauris.linde@giraffe360.com>"
LABEL company="Giraffe360"
LABEL description="Ubuntu development environment for Room Sketcher with Qt"
LABEL version="1.0"

ENV TERM=xterm-color

ENV DEBIAN_FRONTEND=noninteractive \
    DEBCONF_NONINTERACTIVE_SEEN=true \
    QT_PATH=${QT_PATH} \
    WINEDEBUG=-all

RUN apt-get -yqq update && apt-get -yqq --no-install-suggests --no-install-recommends install \
    git \
    curl libcurl4-openssl-dev \
    cmake \
    python3 \
    python3-pip \
    build-essential \
    ccache \
    ninja-build \
    ca-certificates \
    pkg-config \
    libgl1-mesa-dev \
    libdbus-1-dev libfontconfig1-dev libxkbcommon-dev libxkbcommon-x11-dev libxcb-xinerama0-dev libxcb-xkb-dev \
    libfreetype6-dev libx11-dev libx11-xcb-dev libxext-dev libxfixes-dev libxi-dev libxrender-dev libxcb1-dev \
    libxcb-glx0-dev libxcb-keysyms1-dev libxcb-image0-dev libxcb-shm0-dev libxcb-icccm4-dev libxcb-sync-dev \
    libxcb-xfixes0-dev libxcb-shape0-dev libxcb-randr0-dev libxcb-render-util0-dev libxcb-util-dev \
    catch2 \
    locales

RUN locale-gen "en_US.UTF-8"
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

RUN pip3 install aqtinstall

ARG QT_VERSION=6.5.0
ARG QT_PATH=/opt/qt
ARG QT_MODULES=
ARG QT_HOST=linux
ARG QT_TARGET=desktop
ARG QT_ARCH=gcc_64
RUN aqt install --outputdir ${QT_PATH} ${QT_VERSION} ${QT_HOST} ${QT_TARGET} ${QT_ARCH} -m ${QT_MODULES}
RUN aqt install-tool --outputdir ${QT_PATH} ${QT_HOST} ${QT_TARGET} tools_ifw

ENV PATH /opt/qt/${QT_VERSION}/gcc_64/bin:$PATH
ENV PATH /opt/qt/Tools/QtInstallerFramework/4.5/bin:$PATH

RUN apt -qq clean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
    rm /var/log/lastlog /var/log/faillog

WORKDIR /usr/src/app
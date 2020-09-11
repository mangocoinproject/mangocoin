# daemon runs in the background
# run something like tail /var/log/Mangocoind/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/Mangocoind:/var/lib/Mangocoind -v $(pwd)/wallet:/home/mangocoin --rm -ti mangocoin:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG MANGOCOIN_BRANCH=master
ENV MANGOCOIN_BRANCH=${MANGOCOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/mangocoin/mangocoin.git /src/mangocoin && \
    cd /src/mangocoin && \
    git checkout $MANGOCOIN_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/Mangocoind /usr/local/bin/Mangocoind && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/Mangocoind && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/mangocoin && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the Mangocoind service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/Mangocoind Mangocoind && \
    useradd -s /bin/bash -m -d /home/mangocoin mangocoin && \
    mkdir -p /etc/services.d/Mangocoind/log && \
    mkdir -p /var/log/Mangocoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Mangocoind/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/Mangocoind/run && \
    echo "cd /var/lib/Mangocoind" >> /etc/services.d/Mangocoind/run && \
    echo "export HOME /var/lib/Mangocoind" >> /etc/services.d/Mangocoind/run && \
    echo "s6-setuidgid Mangocoind /usr/local/bin/Mangocoind" >> /etc/services.d/Mangocoind/run && \
    chmod +x /etc/services.d/Mangocoind/run && \
    chown nobody:nogroup /var/log/Mangocoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Mangocoind/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/Mangocoind/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/Mangocoind" >> /etc/services.d/Mangocoind/log/run && \
    chmod +x /etc/services.d/Mangocoind/log/run && \
    echo "/var/lib/Mangocoind true Mangocoind 0644 0755" > /etc/fix-attrs.d/Mangocoind-home && \
    echo "/home/mangocoin true mangocoin 0644 0755" > /etc/fix-attrs.d/mangocoin-home && \
    echo "/var/log/Mangocoind true nobody 0644 0755" > /etc/fix-attrs.d/Mangocoind-logs

VOLUME ["/var/lib/Mangocoind", "/home/mangocoin","/var/log/Mangocoind"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/mangocoin export HOME /home/mangocoin s6-setuidgid mangocoin /bin/bash"]

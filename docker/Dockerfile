FROM ubuntu:jammy

LABEL maintainer="Jongkuk Lim <limjk@jmarple.ai>"

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Seoul
ENV TERM xterm-256color

ENV NVIDIA_VISIBLE_DEVICES ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

ARG UID=1000
ARG GID=1000
RUN groupadd -g $GID -o user && useradd -m -u $UID -g $GID -o -s /bin/bash user

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN until apt-get update --fix-missing; do echo "Retrying"; done
RUN apt-get update && apt-get install -y sudo dialog apt-utils tzdata
RUN echo "%sudo ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers && echo "user:user" | chpasswd && adduser user sudo

WORKDIR /home/user
USER user

RUN sudo apt-get update && sudo apt-get install -y libgl1-mesa-dev && sudo apt-get -y install jq

RUN sudo apt-get update && sudo apt-get -y install wget curl git
RUN curl -s https://raw.githubusercontent.com/JeiKeiLim/my_term/main/run.sh | /bin/bash

RUN sudo apt-get update && sudo apt-get install -y zsh && \
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended && \
    git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
RUN echo "\n# Custom settings" >> /home/user/.zshrc && \
    echo "export PATH=/home/user/.local/bin:$PATH" >> /home/user/.zshrc && \
    echo "export LC_ALL=C.UTF-8 && export LANG=C.UTF-8" >> /home/user/.zshrc && \
    sed '11 c\ZSH_THEME=powerlevel10k/powerlevel10k' ~/.zshrc  > tmp.txt && mv tmp.txt ~/.zshrc && \
    echo 'POWERLEVEL9K_DISABLE_CONFIGURATION_WIZARD=true' >> ~/.zshrc
RUN sudo chsh -s $(which zsh) $(whoami)
# Place your environment here

# Install glog
RUN git clone https://github.com/google/glog.git -b v0.6.0 && \
    cd glog && \
    cmake -S . -B build -G "Unix Makefiles" && \
    cmake --build build && \
    sudo cmake --build build --target install

# Install formatter, linter
RUN sudo apt-get install -y python3-pip cppcheck flex bison libserial-dev graphviz libgtest-dev
RUN python3 -m pip install cpplint clang-format
RUN git clone https://github.com/doxygen/doxygen.git -b Release_1_9_8 \
    && mkdir -p doxygen/build \
    && cd doxygen/build \
    && cmake -G "Unix Makefiles" .. \
    && make -j \
    && sudo make install

RUN sudo usermod -aG dialout user


FROM ubuntu:resolute

# Build-time arguments for user/group IDs
ARG UID=1002
ARG GID=1002
ARG USER=kevin
ARG CMAKETAR=cmake-4.2.3-linux-x86_64.tar.gz

# Install clang in non-interactive mode and clean up apt cache
RUN export DEBIAN_FRONTEND=noninteractive \
 && apt-get update \
 && apt-get install -y --no-install-recommends clang lldb ninja-build clangd wget ca-certificates \
 && rm -rf /var/lib/apt/lists/*

# CMAKE
RUN cd \
 && wget https://github.com/Kitware/CMake/releases/download/v4.2.3/"${CMAKETAR}" \
 && tar -xvf "${CMAKETAR}" --strip-components=1 -C /usr/local \
 && rm "${CMAKETAR}"

# Create group and user using provided IDs
RUN groupadd -g "${GID}" "${USER}" \
 && useradd -u "${UID}" -g "${GID}" -m -s /bin/bash "${USER}"

USER ${USER}

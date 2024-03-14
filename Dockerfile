FROM tobante/arm-gcc:10.3

# Install required packages and dependencies
RUN apt-get update && \
    apt-get install -y build-essential make

# Copy your project files to the container
COPY . /app

# Set the working directory
WORKDIR /app

# Build project command
RUN cd /app/Debug_FLASH && make

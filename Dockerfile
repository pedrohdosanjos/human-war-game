FROM ubuntu:22.04

# Instalar dependências
RUN apt update && apt install -y \
    build-essential \
    cmake \
    libsfml-dev \
    x11-xserver-utils \
    libx11-dev \
    && rm -rf /var/lib/apt/lists/*

# Diretório de trabalho
WORKDIR /app

# Copiar projeto para dentro do container
COPY . .

# Corrigir possíveis builds anteriores
RUN rm -f human-war

# Compilar o jogo
RUN g++ -std=c++17 -Iheaders sources/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o human-war

# Comando padrão
CMD ["./human-war"]

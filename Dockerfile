FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ -o my_program main.cpp

CMD ["./my_program"]


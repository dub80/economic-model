FROM alpine:3.8.4

RUN apk upgrade --update \
  && apk add build-base \
  && apk add gsl-dev \
  && apk add check-dev \
  && apk add valgrind

COPY . ./app

WORKDIR /app

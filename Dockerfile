FROM alpine:3.10.2

RUN apk update \
  && apk add build-base \
  && apk add check-dev \
  && apk add gsl-dev

COPY . ./app

WORKDIR /app

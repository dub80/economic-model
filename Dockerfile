FROM alpine:3.10.2

RUN apk add build-base \
  && apk add check-dev

COPY . ./app

WORKDIR /app
